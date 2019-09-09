/**
*                      This file is part of:
*                          ElecCirSim
*
* LED
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct LED
	{
		ComponentProperties properties;
		double forwardVoltage;
		double red;
		double green;
		double blue;

		LED() :
			forwardVoltage(2.1),
			red(1.0),
			green(0.0),
			blue(0.0)
		{}
	}LED;
}