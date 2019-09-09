/**
*                      This file is part of:
*                          ElecCirSim
*
* Zener Diode
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct ZenerDiode
	{
		ComponentProperties properties;
		double forwardVoltage;
		double zenerVoltage;

		ZenerDiode() :
			forwardVoltage(0.7),
			zenerVoltage(5.7)
		{}
	}ZenerDiode;
}