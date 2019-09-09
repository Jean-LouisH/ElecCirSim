/**
*                      This file is part of:
*                          ElecCirSim
*
* Potentiometer
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Potentiometer
	{
		ComponentProperties properties;
		double slider_pct;

		Potentiometer():
			slider_pct(0.5)
		{
			properties.elements.resistance_ohms = 100.0;
		}
	}Potentiometer;
}