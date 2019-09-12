/**
*                          ElecCirSim
*
* Analogue and digital circuit simulator
*
* Copyright (c) 2018-2019 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "Simulation.hpp"
#include "Core.hpp"

namespace ElecCirSim
{
	void initialize(Core* core);
	void loop(Core* core, Simulation* simulation);
	void sleep(Core* core);
	void input(Core* core);
	void compute(Core* core, Simulation* simulation);
	void output(Core* core);
	void shutdown(Core* core, Simulation* simulation);
}