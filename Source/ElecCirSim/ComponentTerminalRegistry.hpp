/**
*                      This file is part of:
*                          ElecCirSim
*
* Component-Terminal Registry
*
* Stores the positions of component terminals in a map to avoid using algorithms to find intersections.
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <vector>
#include <stdint.h>

#include "Component.hpp"
#include "Terminal.hpp"
#include "Aliases.hpp"
#include "Vector2.hpp"
#include <vector>
#include <map>

namespace ElecCirSim
{
	typedef struct
	{
		ComponentIndex componentIndex;
		TerminalIndex terminalIndex;
	}ComponentTerminalPair;

	class ComponentTerminalRegistry
	{
	private:
		std::map<Vector2, std::vector<ComponentTerminalPair>> registry;
	public:
	};
}

