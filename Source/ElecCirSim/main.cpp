#include <SDL.h>

#include "ElecCirSim.hpp"
#include "Simulation.hpp"
#include "Core.hpp"

#include "Constants.hpp"
#include "Timer.hpp"

int main(int argc, char* argv[])
{
	ElecCirSim::Core* core = new ElecCirSim::Core();
	ElecCirSim::Simulation* simulation = new ElecCirSim::Simulation();

	core->filepath = argv[0];

	ElecCirSim::initialize(core);
	if (core->state != ElecCirSim::coreStates::SHUTDOWN)
		ElecCirSim::loop(core, simulation);
	ElecCirSim::shutdown(core, simulation);

	delete simulation;
	delete core;

	return 0;
}