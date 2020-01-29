/**
*                      This file is part of:
*                          ElecCirSim
*
* Simulation Objects
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <map>
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
	typedef struct ComponentGraph
	{
		std::map<TerminalIndex, Terminal> terminals;
		TerminalPositionRegistry terminalPositionRegistry;
		std::map<ComponentIndex, DCVoltageSource> dcVoltageSources;
		std::map<ComponentIndex, Ground> grounds;
		std::map<ComponentIndex, PowerSwitch> switches;
		std::map<ComponentIndex, Resistor> resistors;
		std::map<ComponentIndex, Wire> wires;
		std::map<ComponentIndex, LogicGate> logicGates;

		unsigned int lastTerminalIndex;
		unsigned int lastDCVoltageSourceIndex;
		unsigned int lastGroundIndex;
		unsigned int lastSwitchIndex;
		unsigned int lastResistorIndex;
		unsigned int lastWireIndex;
		unsigned int lastLogicGateIndex;

		ComponentGraph():
			lastTerminalIndex(0),
			lastDCVoltageSourceIndex(0),
			lastGroundIndex(0),
			lastSwitchIndex(0),
			lastResistorIndex(0),
			lastWireIndex(0),
			lastLogicGateIndex(0)
		{}
	}SimulationObjects;
}