#pragma once

#include <SDL_render.h>
#include <stdint.h>
#include <vector>
#include "Rect.hpp"
#include "Transform2D.hpp"

typedef struct Sprite2D
{
	Transform2D transform;
	SDL_Texture* texture;
	Rect pixels;
	uint8_t alpha;
	SDL_RendererFlip flip;

	Sprite2D():
		alpha(255),
		flip(SDL_FLIP_NONE)
	{}
}Sprite2D;