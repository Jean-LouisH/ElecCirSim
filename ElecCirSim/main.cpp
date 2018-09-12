#include <SDL.h>

#include "ElecCirSim.hpp"
#include "Core.hpp"

#include "Constants.hpp"
#include "Timer.hpp"

int main(int argc, char* argv[])
{
	ElecCirSim::Core* core = new ElecCirSim::Core();

	ElecCirSim::initialize(core);
	ElecCirSim::loop(core);
	ElecCirSim::shutdown(core);

	delete core;

	return 0;
}