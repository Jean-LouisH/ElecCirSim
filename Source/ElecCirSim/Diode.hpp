/**
*                      This file is part of:
*                          ElecCirSim
*
* Diode
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Diode
	{
		ComponentProperties properties;
		double forwardVoltage;

		Diode():
			forwardVoltage(0.7)
		{}
	}Diode;
}