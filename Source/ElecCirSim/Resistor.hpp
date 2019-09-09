/**
*                      This file is part of:
*                          ElecCirSim
*
* Resistor
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"

namespace ElecCirSim
{
	typedef struct Resistor
	{
		ComponentProperties properties;

		Resistor()
		{
			properties.elements.resistance_ohms = 100.0;
		}
	}Resistor;
}