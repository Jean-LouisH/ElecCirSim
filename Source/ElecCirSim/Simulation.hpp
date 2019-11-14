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
		bool isFinalTerminalOfBranch(Terminal terminal, Terminal finalTerminal);
		bool isGroundReturnPathTerminal(Terminal terminal);
		Terminal findSeriesConnectedTerminal(Terminal terminal);
		bool areConnected(Terminal firstTerminal, Terminal secondTerminal);
		Terminal findOtherTerminalOnComponent(Terminal terminal);
		bool hasParallelBranch(Terminal terminal);
	public:

		Simulation() :
			totalTime_s(0.0),
			deltaTime_s(10.0 * MICRO),
			wasSceneGraphUpdated(false)
		{}

		void computeDigitalLogic();
		void analyzeFromDCVoltageSources();
		double calculateTotalDCCircuitResistance(DCVoltageSource dcVoltageSource);
		double calculateBranchResistanceRecursively(Terminal currentTerminal, Terminal finalTerminal);
	};
}