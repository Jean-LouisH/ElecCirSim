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

namespace ElecCirSim
{
	enum TerminalTypes
	{
		POSITIVE,
		NEGATIVE,
		COLLECTOR,
		BASE,
		EMITTER,
		GATE,
		BODY,
		SOURCE,
		DRAIN,
	};

	typedef struct
	{
		Vector2 position;
		double voltage;
		double current;
		uint8_t type;
	}Terminal;
}

