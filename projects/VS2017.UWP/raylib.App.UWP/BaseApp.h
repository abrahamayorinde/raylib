/**********************************************************************************************
*
*   raylib.BaseApp - UWP App generic code for managing interface between C and C++
*
*   LICENSE: zlib/libpng
*   
*   CONFIGURATION:
*   
*	#define PCH
*		This defines what header is the PCH and needs to be included
*
*   Copyright (c) 2013-2019 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#pragma once

#if defined(PCH)
#include PCH
#endif

#include <memory>
#include <wrl.h>

//EGL
#include <EGL/eglplatform.h>

#include "raylib.h"
#include "utils.h"

using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::Devices::Input;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Gaming::Input;
using namespace Windows::Graphics::Display;
using namespace Microsoft::WRL;
using namespace Platform;

extern "C" { EGLNativeWindowType uwpWindow; };

/*
TODO list:
	- Cache reference to our CoreWindow?
	- Implement gestures support
*/

// Stand-ins for "core.c" variables
#define MAX_GAMEPADS              4         // Max number of gamepads supported
#define MAX_GAMEPAD_BUTTONS       32        // Max bumber of buttons supported (per gamepad)
#define MAX_GAMEPAD_AXIS          8         // Max number of axis supported (per gamepad)

//Mouse cursor locking
bool cursorLocked = false;
Vector2 mouseDelta = {0, 0};

//Our mouse cursor
CoreCursor ^regularCursor = ref new CoreCursor(CoreCursorType::Arrow, 0); // The "visible arrow" cursor type

//Base app implementation
ref class BaseApp : public Windows::ApplicationModel::Core::IFrameworkView
{
public:

	// IFrameworkView Methods.
	virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView)
	{
		// Register event handlers for app lifecycle. This example includes Activated, so that we
		// can make the CoreWindow active and start rendering on the window.
		applicationView->Activated += ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &BaseApp::OnActivated);

		// Logic for other event handlers could go here.
		// Information about the Suspending and Resuming event handlers can be found here:
		// http://msdn.microsoft.com/en-us/library/windows/apps/xaml/hh994930.aspx

		CoreApplication::Resuming += ref new EventHandler<Platform::Object^>(this, &BaseApp::OnResuming);
	}

	virtual void SetWindow(Windows::UI::Core::CoreWindow^ window)
	{
		window->SizeChanged += ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &BaseApp::OnWindowSizeChanged);
		window->VisibilityChanged += ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &BaseApp::OnVisibilityChanged);
		window->Closed += ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &BaseApp::OnWindowClosed);

		window->PointerPressed += ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &BaseApp::PointerPressed);
		window->PointerReleased += ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &BaseApp::PointerReleased);
		window->PointerWheelChanged += ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &BaseApp::PointerWheelChanged);
		window->KeyDown += ref new TypedEventHandler<CoreWindow ^, KeyEventArgs ^>(this, &BaseApp::OnKeyDown);
		window->KeyUp += ref new TypedEventHandler<CoreWindow ^, KeyEventArgs ^>(this, &BaseApp::OnKeyUp);

		Windows::Devices::Input::MouseDevice::GetForCurrentView()->MouseMoved += ref new TypedEventHandler<MouseDevice^, MouseEventArgs^>(this, &BaseApp::MouseMoved);

		DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();
		currentDisplayInformation->DpiChanged += ref new TypedEventHandler<DisplayInformation^, Object^>(this, &BaseApp::OnDpiChanged);
		currentDisplayInformation->OrientationChanged += ref new TypedEventHandler<DisplayInformation^, Object^>(this, &BaseApp::OnOrientationChanged);

		// The CoreWindow has been created, so EGL can be initialized.

		uwpWindow = (EGLNativeWindowType)window;

		InitWindow(width, height, NULL);
	}

	virtual void Load(Platform::String^ entryPoint) {}

	virtual void Run()
	{
		while (!mWindowClosed)
		{
			if (mWindowVisible)
			{
				//Call update function
				Update();

				PollInput();

				CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
			}
			else
			{
				CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
			}
		}

		CloseWindow();
	}

	//Called every frame (Maybe add draw)
	virtual void Update() {}

	virtual void Uninitialize() {}

protected:

	// Input polling
	void PollInput()
	{
		// Process Messages
		{
			//Loop over pending messages
			while (UWPHasMessages())
			{
				//Get the message
				auto msg = UWPGetMessage();

				//Carry out the command
				switch(msg->Type)
				{
				case ShowMouse: //Do the same thing because of how UWP works...
				case UnlockMouse:
				{
					CoreWindow::GetForCurrentThread()->PointerCursor = regularCursor;
					cursorLocked = false;
					MoveMouse(GetMousePosition());
					break;
				}
				case HideMouse: //Do the same thing because of how UWP works...
				case LockMouse:
				{
					CoreWindow::GetForCurrentThread()->PointerCursor = nullptr;
					cursorLocked = true;
					break;
				}
				case SetMouseLocation:
				{
					MoveMouse(msg->Vector0);
					break;
				}
				}

				//Delete the message
				DeleteUWPMessage(msg);
			}
		}

		// Process Mouse
		{
			CoreWindow ^window = CoreWindow::GetForCurrentThread();

			if (cursorLocked)
			{
				// Track cursor movement delta, recenter it on the client
				auto curMousePos = GetMousePosition();

				auto x = curMousePos.x + mouseDelta.x;
				auto y = curMousePos.y + mouseDelta.y;

				UpdateMousePosition({ x, y });

				// Why we're not using UWPSetMousePosition here...
				//		 UWPSetMousePosition changes the "mousePosition" variable to match where the cursor actually is.
				//		 Our cursor is locked to the middle of screen, and we don't want that reflected in "mousePosition"
				Vector2 centerClient = { (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2) };
				window->PointerPosition = Point(centerClient.x + window->Bounds.X, centerClient.y + window->Bounds.Y);
			}
			else
			{
				// Record the cursor's position relative to the client
				auto x = window->PointerPosition.X - window->Bounds.X;
				auto y = window->PointerPosition.Y - window->Bounds.Y;

				UpdateMousePosition({ x, y });
			}

			mouseDelta = { 0 ,0 };
		}

		// Process Gamepads
		{
			// Check if gamepads are ready
			for (int i = 0; i < MAX_GAMEPADS; i++)
			{
				// HACK: UWP keeps a contiguous list of gamepads. For the interest of time I'm just doing a 1:1 mapping of
				// connected gamepads with their spot in the list, but this has serious robustness problems
				// e.g. player 1, 2, and 3 are playing a game - if player2 disconnects, p3's controller would now be mapped to p2's character since p3 is now second in the list.

				UWPMessage* msg = CreateUWPMessage();
				msg->Type = MarkGamepadActive;
				msg->Int0 = i;
				msg->Bool0 = i < Gamepad::Gamepads->Size;
				UWPSendMessage(msg);
			}

			// Get current gamepad state
			for (int i = 0; i < MAX_GAMEPADS; i++)
			{
				if (IsGamepadAvailable(i))
				{
					// Get current gamepad state
					auto gamepad = Gamepad::Gamepads->GetAt(i);
					GamepadReading reading = gamepad->GetCurrentReading();

					// NOTE: Maybe it would be wiser to redefine the gamepad button mappings in "raylib.h" for the UWP platform instead of remapping them manually
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_A, ((reading.Buttons & GamepadButtons::A) == GamepadButtons::A));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_B, ((reading.Buttons & GamepadButtons::B) == GamepadButtons::B));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_X, ((reading.Buttons & GamepadButtons::X) == GamepadButtons::X));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_Y, ((reading.Buttons & GamepadButtons::Y) == GamepadButtons::Y));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_LB, ((reading.Buttons & GamepadButtons::LeftShoulder) == GamepadButtons::LeftShoulder));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_RB, ((reading.Buttons & GamepadButtons::RightShoulder) == GamepadButtons::RightShoulder));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_SELECT, ((reading.Buttons & GamepadButtons::View) == GamepadButtons::View)); // Changed for XB1 Controller
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_START, ((reading.Buttons & GamepadButtons::Menu) == GamepadButtons::Menu)); // Changed for XB1 Controller
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_UP, ((reading.Buttons & GamepadButtons::DPadUp) == GamepadButtons::DPadUp));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_RIGHT, ((reading.Buttons & GamepadButtons::DPadRight) == GamepadButtons::DPadRight));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_DOWN, ((reading.Buttons & GamepadButtons::DPadDown) == GamepadButtons::DPadDown));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_LEFT, ((reading.Buttons & GamepadButtons::DPadLeft) == GamepadButtons::DPadLeft));
					RegisterGamepadButton(i, GAMEPAD_XBOX_BUTTON_HOME, false); // Home button not supported by UWP

					// Get current axis state
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_LEFT_X, (float)reading.LeftThumbstickX);
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_LEFT_Y, (float)reading.LeftThumbstickY);
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_RIGHT_X, (float)reading.RightThumbstickX);
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_RIGHT_Y, (float)reading.RightThumbstickY);
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_LT, (float)reading.LeftTrigger);
					RegisterGamepadAxis(i, GAMEPAD_XBOX_AXIS_RT, (float)reading.RightTrigger);
				}
			}
		}
	}

	// Application lifecycle event handlers.
	void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args)
	{
		// Run() won't start until the CoreWindow is activated.
		CoreWindow::GetForCurrentThread()->Activate();
	}

	void OnResuming(Platform::Object^ sender, Platform::Object^ args) {}

	// Window event handlers.
	void OnWindowSizeChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::WindowSizeChangedEventArgs^ args) {}

	void OnVisibilityChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args)
	{
		mWindowVisible = args->Visible;
	}

	void OnWindowClosed(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::CoreWindowEventArgs^ args)
	{
		mWindowClosed = true;
	}

	// DisplayInformation event handlers.
	void OnDpiChanged(Windows::Graphics::Display::DisplayInformation^ sender, Platform::Object^ args) {}
	void OnOrientationChanged(Windows::Graphics::Display::DisplayInformation^ sender, Platform::Object^ args) {}

	// Input event handlers
	void PointerPressed(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::PointerEventArgs^ args)
	{
		if (args->CurrentPoint->Properties->IsLeftButtonPressed)
		{
			RegisterClick(MOUSE_LEFT_BUTTON, 1);
		}
		if (args->CurrentPoint->Properties->IsRightButtonPressed)
		{
			RegisterClick(MOUSE_RIGHT_BUTTON, 1);
		}
		if (args->CurrentPoint->Properties->IsMiddleButtonPressed)
		{
			RegisterClick(MOUSE_MIDDLE_BUTTON, 1);
		}
	}

	void PointerReleased(Windows::UI::Core::CoreWindow ^sender, Windows::UI::Core::PointerEventArgs^ args)
	{
		if (!(args->CurrentPoint->Properties->IsLeftButtonPressed))
		{
			RegisterClick(MOUSE_LEFT_BUTTON, 0);
		}
		if (!(args->CurrentPoint->Properties->IsRightButtonPressed))
		{
			RegisterClick(MOUSE_RIGHT_BUTTON, 0);
		}
		if (!(args->CurrentPoint->Properties->IsMiddleButtonPressed))
		{
			RegisterClick(MOUSE_MIDDLE_BUTTON, 0);
		}
	}

	void PointerWheelChanged(Windows::UI::Core::CoreWindow ^sender, Windows::UI::Core::PointerEventArgs^ args)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = ScrollWheelUpdate;
		msg->Float0 = args->CurrentPoint->Properties->MouseWheelDelta;
		UWPSendMessage(msg);
	}

	void MouseMoved(Windows::Devices::Input::MouseDevice^ mouseDevice, Windows::Devices::Input::MouseEventArgs^ args)
	{
		mouseDelta.x += args->MouseDelta.X;
		mouseDelta.y += args->MouseDelta.Y;
	}

	void OnKeyDown(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::KeyEventArgs ^ args)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = RegisterKey;
		msg->Int0 = (int)args->VirtualKey;
		msg->Char0 = 1;
		UWPSendMessage(msg);
	}

	void OnKeyUp(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::KeyEventArgs ^ args)
	{
		//TODO: Fix hold errors
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = RegisterKey;
		msg->Int0 = (int)args->VirtualKey;
		msg->Char0 = 0;
		UWPSendMessage(msg);
	}

private:

	void MoveMouse(Vector2 pos)
	{
		CoreWindow ^window = CoreWindow::GetForCurrentThread();
		Point mousePosScreen = Point(pos.x + window->Bounds.X, pos.y + window->Bounds.Y);
		window->PointerPosition = mousePosScreen;
	}

	void RegisterGamepadButton(int gamepad, int button, char status)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = MarkGamepadButton;
		msg->Int0 = gamepad;
		msg->Int1 = button;
		msg->Char0 = status;
		UWPSendMessage(msg);
	}

	void RegisterGamepadAxis(int gamepad, int axis, float value)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = MarkGamepadAxis;
		msg->Int0 = gamepad;
		msg->Int1 = axis;
		msg->Float0 = value;
		UWPSendMessage(msg);
	}

	void UpdateMousePosition(Vector2 pos)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = UpdateMouseLocation;
		msg->Vector0 = pos;
		UWPSendMessage(msg);
	}

	void RegisterClick(int button, char status)
	{
		UWPMessage* msg = CreateUWPMessage();
		msg->Type = UWPMessageType::RegisterClick;
		msg->Int0 = button;
		msg->Char0 = status;
		UWPSendMessage(msg);
	}

	bool mWindowClosed = false;
	bool mWindowVisible = true;

	int width = 800;
	int height = 450;
};

//Application source for creating the program
template<typename AppType>
ref class ApplicationSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public:
	virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView()
	{
		return ref new AppType();
	}
};