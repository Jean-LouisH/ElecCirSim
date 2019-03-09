/**
*                      This file is part of:
*                          ElecCirSim
*
* Timer
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

namespace ElecCirSim
{
	typedef struct Timer
	{
		int cycleStart;
		int cycleEnd;
		int cycleDelta;
		int frameDelay;
		int frame;
		Timer() :
			cycleStart(0),
			cycleEnd(0),
			cycleDelta(0),
			frameDelay(0),
			frame(0) {}
	}Timer;
}