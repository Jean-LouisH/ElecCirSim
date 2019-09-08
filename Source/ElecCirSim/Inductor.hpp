/**
*                      This file is part of:
*                          ElecCirSim
*
* Inductor
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "Component.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Inductor
	{
		Component component;

		Inductor()
		{
			component.elements.inductance_henries = 100.0 * MILLI;
		}
	}Inductor;
}