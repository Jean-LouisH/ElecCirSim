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
#include "ComponentProperties.hpp"
#include "Terminal.hpp"
#include "TerminalPositionRegistry.hpp"

#include "ACVoltageSource.hpp"
#include "BJTTransistor.hpp"
#include "Capacitor.hpp"
#include "DCVoltageSource.hpp"
#include "Diode.hpp"
#include "Ground.hpp"
#include "Inductor.hpp"
#include "LED.hpp"
#include "LogicGate.hpp"
#include "MOSFET.hpp"
#include "Potentiometer.hpp"
#include "PowerSwitch.hpp"
#include "Resistor.hpp"
#include "Transformer.hpp"
#include "Wire.hpp"
#include "ZenerDiode.hpp"

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