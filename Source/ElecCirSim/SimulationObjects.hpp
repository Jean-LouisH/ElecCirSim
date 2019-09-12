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
	typedef struct SimulationObjects
	{
		std::map<TerminalIndex, Terminal> terminals;
		TerminalPositionRegistry terminalPositionRegistry;
		std::map<ComponentIndex, DCVoltageSource> dcVoltageSources;
		std::map<ComponentIndex, Ground> grounds;
		std::map<ComponentIndex, PowerSwitch> switches;
		std::map<ComponentIndex, Resistor> resistors;
		std::map<ComponentIndex, Wire> wires;

		unsigned int generatedTerminalCount;
		unsigned int dcVoltageSourceCount;
		unsigned int groundCount;
		unsigned int switchCount;
		unsigned int resistorCount;
		unsigned int wireCount;

		SimulationObjects():
			generatedTerminalCount(0),
			dcVoltageSourceCount(0),
			groundCount(0),
			switchCount(0),
			resistorCount(0),
			wireCount(0)
		{}
	}SimulationObjects;
}