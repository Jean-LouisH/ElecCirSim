/**
*                      This file is part of:
*                          ElecCirSim
*
* Capacitor
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Capacitor
	{
		ComponentProperties properties;

		Capacitor()
		{
			properties.elements.capacitance_farads = 1.0 * MICRO;
		}
	}Capacitor;
}