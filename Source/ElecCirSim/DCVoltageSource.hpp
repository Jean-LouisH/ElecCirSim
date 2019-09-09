/**
*                      This file is part of:
*                          ElecCirSim
*
* DC Voltage Source
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"

namespace ElecCirSim
{
	typedef struct DCVoltageSource
	{
		ComponentProperties properties;
		double maxVoltage;

		DCVoltageSource():
			maxVoltage(0.0)
		{}
	}DCVoltageSource;
}