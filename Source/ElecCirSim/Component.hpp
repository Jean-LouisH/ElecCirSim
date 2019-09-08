/**
*                      This file is part of:
*                          ElecCirSim
*
* Component
*
* Defines the general structure of all electronic components to be listed in the simulation.
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <vector>
#include "Aliases.hpp"
#include "ElectricalElements.hpp"

namespace ElecCirSim
{
	typedef struct Component
	{
		std::vector<TerminalIndex> terminalIndices;
		ElectricalElements elements;
		double current;

		Component():
			current(0.0)
		{}
	}Component;
}

