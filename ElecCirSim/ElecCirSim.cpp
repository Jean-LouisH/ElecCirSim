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
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

	if (engine->window == NULL)
		SDL_Log(
			"SDL could not create the window because: %s",
			SDL_GetError());

	SDL_Surface* logo = IMG_Load("");
	SDL_SetWindowIcon(engine->window, logo);
	SDL_FreeSurface(logo);

	engine->SDLRenderer = SDL_CreateRenderer(
		engine->window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void ElecCirSim::loop(Engine* engine)
{
	do
	{
		engine->timer.cycleStart = SDL_GetTicks();

		ElecCirSim::input(engine);
		ElecCirSim::output(engine);

		engine->timer.cycleEnd = SDL_GetTicks();
		engine->timer.cycleDelta = engine->timer.cycleEnd - engine->timer.cycleStart;
		engine->timer.frameDelay = FRAME_TIME_MS - engine->timer.cycleDelta;
		if (engine->timer.frameDelay > 0)
			SDL_Delay(engine->timer.frameDelay);
		engine->timer.frame = SDL_GetTicks() - engine->timer.cycleStart;
	} while (engine->state != engineStates::SHUTDOWN);
}

void ElecCirSim::input(Engine* engine)
{
	SDL_Event SDLEvents;
	MouseState* mouse = &engine->input.mouse;

	while (SDL_PollEvent(&SDLEvents))
	{
		switch (SDLEvents.type)
		{
			/*Close window button*/
		case SDL_QUIT:
			engine->state = engineStates::SHUTDOWN;
			break;

		case SDL_MOUSEBUTTONDOWN:
			mouse->type = SDL_MOUSEBUTTONDOWN;
			mouse->timestamp_ms = SDLEvents.button.timestamp;
			mouse->windowID = SDLEvents.button.windowID;
			mouse->button = SDLEvents.button.button;
			mouse->buttonState = SDLEvents.button.state;
			mouse->clicks = SDLEvents.button.clicks;
			mouse->x = SDLEvents.button.x;
			mouse->y = SDLEvents.button.y;
			break;
		case SDL_MOUSEBUTTONUP:
			mouse->type = SDL_MOUSEBUTTONUP;
			mouse->timestamp_ms = SDLEvents.button.timestamp;
			mouse->windowID = SDLEvents.button.windowID;
			mouse->button = SDLEvents.button.button;
			mouse->buttonState = SDLEvents.button.state;
			mouse->clicks = SDLEvents.button.clicks;
			mouse->x = SDLEvents.button.x;
			mouse->y = SDLEvents.button.y;
			break;
		case SDL_MOUSEMOTION:
			mouse->type = SDL_MOUSEMOTION;
			mouse->timestamp_ms = SDLEvents.motion.timestamp;
			mouse->windowID = SDLEvents.motion.windowID;
			mouse->motionState = SDLEvents.motion.state;
			mouse->x = SDLEvents.motion.x;
			mouse->y = SDLEvents.motion.y;
			mouse->xrel = SDLEvents.motion.xrel;
			mouse->yrel = SDLEvents.motion.yrel;
			break;
		case SDL_MOUSEWHEEL:
			mouse->type = SDL_MOUSEWHEEL;
			mouse->timestamp_ms = SDLEvents.wheel.timestamp;
			mouse->windowID = SDLEvents.wheel.windowID;
			mouse->xScroll = SDLEvents.wheel.x;
			mouse->yScroll = SDLEvents.wheel.y;
			mouse->direction = SDLEvents.wheel.direction;
			break;
		}
	}
}

void ElecCirSim::output(Engine* engine)
{
	SDL_SetRenderDrawColor(engine->SDLRenderer, 0, 0, 0, 255);
	SDL_RenderClear(engine->SDLRenderer);

	SDL_RenderPresent(engine->SDLRenderer);
}

void ElecCirSim::shutdown(Engine* engine)
{
	SDL_DestroyWindow(engine->window);
	SDL_Quit();
}