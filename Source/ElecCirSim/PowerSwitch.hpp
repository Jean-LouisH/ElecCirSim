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

#include "Component.hpp"

namespace ElecCirSim
{
	typedef struct PowerSwitch
	{
		Component component;
		bool isClosed;

		PowerSwitch() :
			isClosed(true)
		{}
	}PowerSwitch;
}