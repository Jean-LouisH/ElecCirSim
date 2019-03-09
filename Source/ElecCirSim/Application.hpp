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
#include "Component.hpp"
#include "ComponentTerminalRegistry.hpp"

namespace ElecCirSim
{
	typedef struct Application
	{
		std::vector<Component> components;
		ComponentTerminalRegistry registry;
		Application()
		{}
	}Application;
}