/**
*                      This file is part of:
*                          ElecCirSim
*
* AC Voltage Source
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"

namespace ElecCirSim
{
	typedef struct ACVoltageSource
	{
		ComponentProperties properties;
		double maxVoltage;
		double frequency;
		double DCOffset;
		double phase;
		double phaseOffset;

		ACVoltageSource() :
			maxVoltage(0.0),
			frequency(0.0),
			DCOffset(0.0),
			phase(0.0),
			phaseOffset(0.0)
		{}
	}ACVoltageSource;
}