#pragma once

#include <SDL_render.h>
#include <vector>
#include "Sprite2D.hpp"
#include "Component.hpp"
#include "SDLRenderable.hpp"
#include "Camera2D.hpp"

namespace Rendering2D
{
	namespace SDL
	{
		void buildRenderablesFromComponents(
			std::vector<SDLRenderable>* SDLRenderables,
			std::vector<ElecCirSim::Component> components,
			Camera2D camera2D,
			SDL_Window* window);
	}
}
