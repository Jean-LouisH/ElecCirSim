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

#include "Component.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Potentiometer
	{
		Component component;
		double slider_pct;

		Potentiometer():
			slider_pct(0.5)
		{
			component.elements.resistance_ohms = 100.0;
		}
	}Potentiometer;
}