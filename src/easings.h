/*******************************************************************************************
*
*   raylib Easings - Useful easing functions for values animation
*
*   A port of Robert Penner's easing equations to C (http://robertpenner.com/easing/)
*
*   Robert Penner License
*   ---------------------------------------------------------------------------------
*   Open source under the BSD License. 
*
*   Copyright (c) 2001 Robert Penner. All rights reserved.
*
*   Redistribution and use in source and binary forms, with or without modification, 
*   are permitted provided that the following conditions are met:
*
*       - Redistributions of source code must retain the above copyright notice, 
*         this list of conditions and the following disclaimer.
*       - Redistributions in binary form must reproduce the above copyright notice, 
*         this list of conditions and the following disclaimer in the documentation 
*         and/or other materials provided with the distribution.
*       - Neither the name of the author nor the names of contributors may be used 
*         to endorse or promote products derived from this software without specific 
*         prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
*   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
*   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
*   IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
*   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
*   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
*   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
*   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
*   OF THE POSSIBILITY OF SUCH DAMAGE.
*   ---------------------------------------------------------------------------------
*
*   Copyright (c) 2015 Ramon Santamaria
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

#ifndef EASINGS_H
#define EASINGS_H

#include <math.h>

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

// Linear Easing functions
float EaseLinearNone(float t, float b, float c, float d) { return (c*t/d + b); }
float EaseLinearIn(float t, float b, float c, float d) { return (c*t/d + b); }
float EaseLinearOut(float t, float b, float c, float d) { return (c*t/d + b); }
float EaseLinearInOut(float t,float b, float c, float d) { return (c*t/d + b); }

// Sine Easing functions
float EaseSineIn(float t, float b, float c, float d) { return (-c*cos(t/d*(PI/2)) + c + b); }
float EaseSineOut(float t, float b, float c, float d) { return (c*sin(t/d*(PI/2)) + b); }
float EaseSineInOut(float t, float b, float c, float d) { return (-c/2*(cos(PI*t/d) - 1) + b); }

// Circular Easing functions
float EaseCircIn(float t, float b, float c, float d) { return (-c*(sqrt(1 - (t/=d)*t) - 1) + b); }
float EaseCircOut(float t, float b, float c, float d) { return (c*sqrt(1 - (t=t/d-1)*t) + b); }
float EaseCircInOut(float t, float b, float c, float d) 
{
    if ((t/=d/2) < 1) return (-c/2*(sqrt(1 - t*t) - 1) + b);
    return (c/2*(sqrt(1 - t*(t-=2)) + 1) + b);
}

// Cubic Easing functions
float EaseCubicIn(float t, float b, float c, float d) { return (c*(t/=d)*t*t + b); }
float EaseCubicOut(float t, float b, float c, float d) { return (c*((t=t/d-1)*t*t + 1) + b); }
float EaseCubicInOut(float t, float b, float c, float d) 
{ 
    if ((t/=d/2) < 1) return (c/2*t*t*t + b);
    return (c/2*((t-=2)*t*t + 2) + b);    
}

// Quadratic Easing functions
float EaseQuadIn(float t, float b, float c, float d) { return (c*(t/=d)*t + b); }
float EaseQuadOut(float t, float b, float c, float d) { return (-c*(t/=d)*(t-2) + b); }
float EaseQuadInOut(float t, float b, float c, float d) 
{
    if ((t/=d/2) < 1) return (((c/2)*(t*t)) + b);
    return (-c/2*(((t-2)*(--t)) - 1) + b);
}

// Exponential Easing functions
float EaseExpoIn(float t, float b, float c, float d) { return (t == 0) ? b : (c*pow(2, 10*(t/d - 1)) + b); }
float EaseExpoOut(float t, float b, float c, float d) { return (t == d) ? (b + c) : (c*(-pow(2, -10*t/d) + 1) + b);    }
float EaseExpoInOut(float t, float b, float c, float d) 
{
    if (t == 0) return b;
    if (t == d) return (b + c);
    if ((t/=d/2) < 1) return (c/2*pow(2, 10*(t - 1)) + b);
    
    return (c/2*(-pow(2, -10*--t) + 2) + b);
}

// Back Easing functions
float EaseBackIn(float t, float b, float c, float d) 
{
    float s = 1.70158f;
    float postFix = t/=d;
    return (c*(postFix)*t*((s + 1)*t - s) + b);
}

float EaseBackOut(float t, float b, float c, float d)
{    
    float s = 1.70158f;
    return (c*((t=t/d-1)*t*((s + 1)*t + s) + 1) + b);
}

float EaseBackInOut(float t, float b, float c, float d)
{
    float s = 1.70158f;
    if ((t/=d/2) < 1) return (c/2*(t*t*(((s*=(1.525f)) + 1)*t - s)) + b);
    
    float postFix = t-=2;
    return (c/2*((postFix)*t*(((s*=(1.525f)) + 1)*t + s) + 2) + b);
}

// Bounce Easing functions
float EaseBounceIn(float t, float b, float c, float d) { return (c - EaseBounceOut(d-t, 0, c, d) + b); }
float EaseBounceOut(float t, float b, float c, float d) 
{
    if ((t/=d) < (1/2.75f)) 
    {
        return (c*(7.5625f*t*t) + b);
    } 
    else if (t < (2/2.75f)) 
    {
        float postFix = t-=(1.5f/2.75f);
        return (c*(7.5625f*(postFix)*t + 0.75f) + b);
    } 
    else if (t < (2.5/2.75)) 
    {
        float postFix = t-=(2.25f/2.75f);
        return (c*(7.5625f*(postFix)*t + 0.9375f) + b);
    } 
    else 
    {
        float postFix = t-=(2.625f/2.75f);
        return (c*(7.5625f*(postFix)*t + 0.984375f) + b);
    }
}

float EaseBounceInOut(float t, float b, float c, float d) 
{
    if (t < d/2) return (EaseBounceIn(t*2, 0, c, d)*0.5f + b);
    else return (EaseBounceOut(t*2-d, 0, c, d)*0.5f + c*0.5f + b);
}

// Elastic Easing functions
float EaseElasticIn(float t, float b, float c, float d) 
{
    if (t == 0) return b;
    if ((t/=d) == 1) return (b + c);
    
    float p = d*0.3f;
    float a = c; 
    float s = p/4;
    float postFix = a*pow(2, 10*(t-=1));
    
    return (-(postFix*sin((t*d-s)*(2*PI)/p )) + b);
}

float EaseElasticOut(float t, float b, float c, float d)
{
    if (t == 0) return b;
    if ((t/=d) == 1) return (b + c);
    
    float p = d*0.3f;
    float a = c; 
    float s = p/4;
    
    return (a*pow(2,-10*t)*sin((t*d-s)*(2*PI)/p) + c + b);    
}

float EaseElasticInOut(float t, float b, float c, float d)
{
    if (t == 0) return b;
    if ((t/=d/2) == 2) return (b + c);
    
    float p = d*(0.3f*1.5f);
    float a = c;
    float s = p/4;

    if (t < 1) 
    {
        float postFix = a*pow(2, 10*(t-=1));
        return -0.5f*(postFix*sin((t*d-s)*(2*PI)/p)) + b;
    }
    
    float postFix = a*pow(2, -10*(t-=1));
    
    return (postFix*sin((t*d-s)*(2*PI)/p)*0.5f + c + b);
}

#ifdef __cplusplus
}
#endif

#endif // EASINGS_H