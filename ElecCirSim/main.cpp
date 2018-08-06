#include <SDL.h>

#include "ElecCirSim.hpp"
#include "Engine.hpp"

#include "Constants.hpp"
#include "Timer.hpp"

int main(int argc, char* argv[])
{
	ElecCirSim::Engine* engine = new ElecCirSim::Engine();

	ElecCirSim::initialize(engine);
	ElecCirSim::loop(engine);
	ElecCirSim::shutdown(engine);

	delete engine;

	return 0;
}