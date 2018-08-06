#include "ElecCirSim.hpp"
#include "Constants.hpp"
#include <SDL_image.h>


void ElecCirSim::initialize(Engine* engine)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		SDL_Log("SDL could not initialize because: %s", SDL_GetError());

	engine->window = SDL_CreateWindow(
		"ElecCirSim",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		640,
		0);

	if (engine->window == NULL)
		SDL_Log(
			"SDL could not create the window because: %s",
			SDL_GetError());

	SDL_Surface* logo = IMG_Load("");
	SDL_SetWindowIcon(engine->window, logo);
	SDL_FreeSurface(logo);

	SDL_Renderer* renderer = SDL_CreateRenderer(
		engine->window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void ElecCirSim::loop(Engine* engine)
{
	do
	{
		engine->timer.cycleStart = SDL_GetTicks();

		engine->timer.cycleEnd = SDL_GetTicks();
		engine->timer.cycleDelta = engine->timer.cycleEnd - engine->timer.cycleStart;
		engine->timer.frameDelay = FRAME_TIME_MS - engine->timer.cycleDelta;
		if (engine->timer.frameDelay > 0)
			SDL_Delay(engine->timer.frameDelay);
		engine->timer.frame = SDL_GetTicks() - engine->timer.cycleStart;
	} while (true);
}

void ElecCirSim::shutdown(Engine* engine)
{
	SDL_DestroyWindow(engine->window);
	SDL_Quit();
}