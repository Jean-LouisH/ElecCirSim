/**
*                      This file is part of:
*                          ElecCirSim
*
* Power Switch
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "ComponentProperties.hpp"

namespace ElecCirSim
{
	typedef struct PowerSwitch
	{
		ComponentProperties properties;
		bool isClosed;

		PowerSwitch() :
			isClosed(true)
		{}
	}PowerSwitch;
}