/**
*                      This file is part of:
*                          ElecCirSim
*
* Analogue Component
*
* Defines the general structure of analogue electronic components to be listed in the simulation.
*
* Copyright (c) 2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <vector>
#include <stdint.h>

#include "Terminal.hpp"

enum ComponentTypes
{
	RESISTOR,
	CAPACITOR,
	INDUCTOR,
	NPN_TRANSISTOR,
	PNP_TRANSISTOR,
	N_MOSFET,
	P_MOSFET,
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
	uint8_t type;
	ElectricalElements elements;
}Component;