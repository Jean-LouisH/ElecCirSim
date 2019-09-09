/**
*                      This file is part of:
*                          ElecCirSim
*
* BJT Transistor
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct BJTTransistor
	{
		enum channels
		{
			NPN_CHANNEL,
			PNP_CHANNEL
		};

		ComponentProperties properties;
		uint8_t channel;
		double beta;
		double baseCurrent;
		double collectorCurrent;
		double emitterCurrent;

		BJTTransistor():
			channel(NPN_CHANNEL),
			beta(100.0),
			baseCurrent(0.0),
			collectorCurrent(0.0),
			emitterCurrent(0.0)
		{}
	}BJTTransistor;
}