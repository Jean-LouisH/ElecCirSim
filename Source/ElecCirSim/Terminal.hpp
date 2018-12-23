/**
*                      This file is part of:
*                          ElecCirSim
*
* Terminal
*
* Copyright (c) 2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <stdint.h>

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
		int xPosition;
		int yPosition;
		double voltage;
		double current;
		uint8_t type;
	}Terminal;
}

