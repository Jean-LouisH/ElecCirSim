#include <SDL.h>
#include <SDL_image.h>

#include "Constants.hpp"
#include "Timer.hpp"

int main(int argc, char* argv[])
{
	double currentTime = 0;
	double lastTime = 0;
	SDL_Window* window;
	SDL_GLContext context;
	Timer time;

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("SDL could not initialize because: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
		"ElecCirSim",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		640,
		0);

	if (window == NULL)
	{
		SDL_Log(
			"SDL could not create the window because: %s",
			SDL_GetError());
	}

	SDL_Surface* logo = IMG_Load("");
	SDL_SetWindowIcon(window, logo);
	SDL_FreeSurface(logo);

	SDL_Renderer* renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	do
	{
		time.cycleStart = SDL_GetTicks();

		time.cycleEnd = SDL_GetTicks();
		time.cycleDelta = time.cycleEnd - time.cycleStart;
		time.frameDelay = FRAME_TIME_MS - time.cycleDelta;
		if (time.frameDelay > 0)
			SDL_Delay(time.frameDelay);
		time.frame = SDL_GetTicks() - time.cycleStart;
	} while (true);

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}