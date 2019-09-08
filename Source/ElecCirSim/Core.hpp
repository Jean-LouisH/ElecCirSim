/**
*                      This file is part of:
*                          ElecCirSim
*
* Core
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "SDL.h"
#include "Timer.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include <stdint.h>

namespace ElecCirSim
{
	enum coreStates
	{
		RUNNING_APPLICATION_WINDOWED,
		SHUTDOWN,
	};

	typedef struct Core
	{
		SDL_Window* window;
		SDL_GLContext glContext;
		const char* filepath;
		Timer timer;
		Input input;
		Output output;
		uint8_t state;
		Core() :
			window(NULL),
			filepath(NULL),
			state(RUNNING_APPLICATION_WINDOWED) {}
	}Core;
}
