/**
*                      This file is part of:
*                          ElecCirSim
*
* MOSFET
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"
#include <stdint.h>

namespace ElecCirSim
{
	typedef struct MOSFET
	{
		enum channels
		{
			N_CHANNEL,
			P_CHANNEL
		};

		ComponentProperties properties;
		double tresholdVoltage;
		uint8_t channel;

		MOSFET():
			tresholdVoltage(1.5),
			channel(N_CHANNEL)
		{}
	}MOSFET;
}