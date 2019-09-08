#include "ElecCirSim.hpp"
#include "Constants.hpp"
#include <SDL_image.h>

void ElecCirSim::initialize(Core* core)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		SDL_Log("SDL could not initialize because: %s", SDL_GetError());

	core->window = SDL_CreateWindow(
		"ElecCirSim",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		640,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

	if (core->window == NULL)
	{
		SDL_Log(
			"SDL could not create the window because: %s",
			SDL_GetError());
	}
	else
	{
		IMG_Init(IMG_INIT_PNG);

		SDL_Surface* logo = IMG_Load("");
		SDL_SetWindowIcon(core->window, logo);
		SDL_FreeSurface(logo);

		core->glContext = SDL_GL_CreateContext(core->window);
	}
}

void ElecCirSim::loop(Core* core, Application* application)
{
	Timer* timer = &core->timer;

	do
	{
		timer->cycleStart = SDL_GetTicks();

		ElecCirSim::input(core);
		ElecCirSim::compute(core, application);
		ElecCirSim::output(core);
		ElecCirSim::sleep(core);
	} while (core->state != coreStates::SHUTDOWN);
}

void ElecCirSim::sleep(Core* core)
{
	Timer* timer = &core->timer;
	timer->cycleEnd = SDL_GetTicks();
	timer->cycleDelta = timer->cycleEnd - timer->cycleStart;
	timer->frameDelay = FRAME_TIME_MS - timer->cycleDelta;
	if (timer->frameDelay > 0)
		SDL_Delay(timer->frameDelay);
	timer->frame = SDL_GetTicks() - timer->cycleStart;
}

void ElecCirSim::input(Core* core)
{
	SDL_Event SDLEvents;
	MouseState* mouse = &core->input.mouse;

	while (SDL_PollEvent(&SDLEvents))
	{
		switch (SDLEvents.type)
		{
			/*Close window button*/
		case SDL_QUIT:
			core->state = coreStates::SHUTDOWN;
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

void ElecCirSim::compute(Core* core, Application* application)
{

}

void ElecCirSim::output(Core* core)
{

}

void ElecCirSim::shutdown(Core* core, Application* application)
{
	IMG_Quit();
	SDL_GL_DeleteContext(core->glContext);
	SDL_DestroyWindow(core->window);
	SDL_Quit();
}