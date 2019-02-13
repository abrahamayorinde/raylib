/**********************************************************************************************
*
*   rnet - A simple and easy-to-use network module for raylib
*
*   FEATURES:
*       - Manage network stuff
*
*   DEPENDENCIES:
*       core.h    - core stuff
*
*   CONTRIBUTORS:
*       Jak Barnes (github: @syphonx) (Feb. 2019):
*           - Initial version
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
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
 
#if defined(RNET_STANDALONE)
#include "raudio.h"
#include <stdarg.h>         // Required for: va_list, va_start(), vfprintf(), va_end()
#else
#include "raylib.h"         // Declares module functions
// Check if config flags have been externally provided on compilation line
#if !defined(EXTERNAL_CONFIG_FLAGS)
#include "config.h"         // Defines module configuration flags
#endif
#include "utils.h"          // Required for: fopen() Android mapping
#endif

void HelloWorld(void);

void HelloWorld()
{
	TraceLog(LOG_DEBUG, "Hello, World!");
}
