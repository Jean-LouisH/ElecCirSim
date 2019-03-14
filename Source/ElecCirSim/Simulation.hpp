/**
*                          ElecCirSim
*
* Simulation
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "Application.hpp"

namespace ElecCirSim
{
	namespace Simulation
	{		
		void centreSpritesToTerminals(
			std::vector<Component>* components, 
			bool wasCanvasUpdated);
	}
}