/**
*                      This file is part of:
*                          ElecCirSim
*
* Terminal Position Registry
*
* Stores the positions of component terminals in a map to avoid using search algorithms to find intersections.
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <vector>
#include <stdint.h>

#include "Aliases.hpp"
#include "Vector2.hpp"
#include <stdint.h>
#include <vector>
#include <map>

namespace ElecCirSim
{
	class TerminalPositionRegistry
	{
	private:
		std::map<uint64_t, std::vector<TerminalIndex>> registry;
		uint64_t hash(Vector2 position);
	public:
		std::vector<TerminalIndex> at(Vector2 position);
	};
}

