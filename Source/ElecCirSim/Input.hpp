/**
*                      This file is part of:
*                          ElecCirSim
*
* Input
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

namespace ElecCirSim
{
	typedef struct MouseState
	{
		Uint32 type;
		Uint8 clicks;
		Sint32 x;
		Sint32 y;
		Sint32 xrel;
		Sint32 yrel;
		Sint32 xScroll;
		Sint32 yScroll;
		Uint32 direction;
		Uint8 button;
		Uint8 buttonState;
		Uint32 motionState;
		Uint32 timestamp_ms;
		Uint32 windowID;

		MouseState() :
			type(0),
			clicks(0),
			x(0),
			y(0),
			xrel(0),
			yrel(0),
			xScroll(0),
			yScroll(0),
			direction(0),
			button(0),
			buttonState(0),
			motionState(0),
			timestamp_ms(0),
			windowID(0)
		{}
	}MouseState;

	typedef struct Input
	{
		MouseState mouse;
	}Input;
}
