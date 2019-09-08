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

#include "Terminal.hpp"
#include "Vector2.hpp"
#include <vector>
#include <map>

namespace ElecCirSim
{
	using TerminalPositionRegistry = std::map<Vector2, std::vector<TerminalIndex>>;
}

