/**
*                      This file is part of:
*                          ElecCirSim
*
* Application
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <map>
#include <string>
#include "Camera2D.hpp"
#include "Component.hpp"
#include "Terminal.hpp"
#include "TerminalPositionRegistry.hpp"

namespace ElecCirSim
{
	typedef struct Application
	{
		std::map<TerminalIndex, Terminal> terminals;
		TerminalPositionRegistry terminalPositionRegistry;
		Camera2D camera;
		double simulationTime_s;
		double timeStep_us;
		bool wasCanvasUpdated;
		std::string simulationTitle;
		int generatedTerminalCount;

		Application():
			simulationTime_s(0.0),
			timeStep_us(10.0),
			wasCanvasUpdated(false),
			generatedTerminalCount(0)
		{}
	}Application;
}