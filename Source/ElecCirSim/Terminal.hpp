/**
*                      This file is part of:
*                          ElecCirSim
*
* Terminal
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <stdint.h>
#include "Vector2.hpp"
#include "Aliases.hpp"
#include "ComponentTypes.hpp"
#include "TerminalTypes.hpp"

namespace ElecCirSim
{
	typedef struct Terminal
	{
		Vector2 position;
		double voltage;
		TerminalType type;
		TerminalIndex index;
		ComponentIndex componentIndex;
		ComponentType componentType;

		Terminal():
			position({0.0, 0.0}),
			voltage(0.0),
			type(0),
			index(0),
			componentIndex(0),
			componentType(0)
		{}
	}Terminal;
}

