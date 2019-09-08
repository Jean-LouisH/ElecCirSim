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

#include "Component.hpp"

namespace ElecCirSim
{
	typedef struct Resistor
	{
		Component component;

		Resistor()
		{
			component.elements.resistance_ohms = 100.0;
		}
	}Resistor;
}