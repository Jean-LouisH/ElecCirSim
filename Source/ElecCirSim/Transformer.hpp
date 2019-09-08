/**
*                      This file is part of:
*                          ElecCirSim
*
* Transformer
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "Component.hpp"
#include "Constants.hpp"

namespace ElecCirSim
{
	typedef struct Transformer
	{
		Component component;
		unsigned int primaryTurns;
		double primaryInductance;
		unsigned int secondaryTurns;
		double secondaryInductance;

		Transformer():
			primaryTurns(100),
			primaryInductance(1.0),
			secondaryTurns(100),
			secondaryInductance(1.0)
		{}
	}Transformer;
}