/**
*                      This file is part of:
*                          ElecCirSim
*
* Simulation
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <string>
#include "Camera2D.hpp"
#include "SimulationObjects.hpp"

namespace ElecCirSim
{
	class Simulation
	{
	private:
		SimulationObjects objects;
		Camera2D camera;
		double totalTime_s;
		double deltaTime_s;
		bool wasSceneGraphUpdated;
		std::string title;

		bool isOpenCircuitTerminal(Terminal terminal);
		bool isFinalTerminalOfCircuit(Terminal terminal, DCVoltageSource dcVoltageSource);
		bool isGroundReturnPathTerminal(Terminal terminal);
	public:

		Simulation():
			totalTime_s(0.0),
			deltaTime_s(10.0 * MICRO),
			wasSceneGraphUpdated(false)
		{}

		void analyzeFromVoltageSource();
	};
}