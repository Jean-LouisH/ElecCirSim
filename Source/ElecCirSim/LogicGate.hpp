/**
*                      This file is part of:
*                          ElecCirSim
*
* Logic Gate
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"
#include <stdint.h>

namespace ElecCirSim
{
	typedef struct LogicGate
	{
		enum types
		{
			NOT_GATE,
			AND_GATE,
			OR_GATE,
			NAND_GATE,
			NOR_GATE
		};

		ComponentProperties properties;
		uint8_t type;
		double slewRate_volts_per_ns;

		LogicGate():
			type(NOT_GATE),
			slewRate_volts_per_ns(500.0 * MILLI)
		{}
	}LogicGate;
}