#include <SDL.h>

#include "ElecCirSim.hpp"
#include "Application.hpp"
#include "Core.hpp"

#include "Constants.hpp"
#include "Timer.hpp"

int main(int argc, char* argv[])
{
	ElecCirSim::Core* core = new ElecCirSim::Core();
	ElecCirSim::Application* application = new ElecCirSim::Application();

	core->filepath = argv[0];

	ElecCirSim::initialize(core);
	if (core->state != ElecCirSim::SHUTDOWN)
		ElecCirSim::loop(core, application);
	ElecCirSim::shutdown(core, application);

	delete application;
	delete core;

	return 0;
}