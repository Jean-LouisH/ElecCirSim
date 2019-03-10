/**
*                      This file is part of:
*                          ElecCirSim
*
* Application
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <vector>
#include <string>
#include "Component.hpp"
#include "ComponentTerminalRegistry.hpp"
#include "SpriteCache.hpp"

namespace ElecCirSim
{
	typedef struct Application
	{
		std::vector<Component> components;
		ComponentTerminalRegistry registry;
		SpriteCache spriteCache;
		double simulationTime_s;
		double timeStep_us;
		std::string simulationTitle;
		Application():
			simulationTime_s(0.0)
		{}
	}Application;
}