/**
*                      This file is part of:
*                         ElecCirSim
*
* Output
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "SDLRenderable.hpp"
#include <vector>

namespace ElecCirSim
{
	typedef struct Output
	{
		std::vector<SDLRenderable> SDLRenderables;
	}Output;
}
