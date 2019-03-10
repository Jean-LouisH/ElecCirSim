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
#include <stdint.h>

#include "Terminal.hpp"
#include "SDLRenderable.hpp"

namespace ElecCirSim
{
	enum ComponentTypes
	{
		DC_VOLTAGE_SOURCE,
		AC_VOLTAGE_SOURCE,
		GROUND,

		POWER_SWITCH,

		RESISTOR,
		CAPACITOR,
		INDUCTOR,

		POTENTIOMETER,

		TRANSFORMER,
		CENTRE_TAPPED_TRANSFORMER,

		NPN_TRANSISTOR,
		PNP_TRANSISTOR,
		N_MOSFET,
		P_MOSFET,

		NOT_GATE,
		AND_GATE,
		OR_GATE,
		NAND_GATE,
		NOR_GATE,
	};

	typedef struct
	{
		double resistance;
		double capacitance;
		double inductance;
	}ElectricalElements;

	typedef struct
	{
		std::vector<Terminal> terminals;
		SDLRenderable sprite;
		uint8_t type;
		ElectricalElements elements;
	}Component;
}

