#pragma once

#include <SDL_render.h>
#include <stdint.h>
#include <vector>
#include "Rect.hpp"
#include "Transform2D.hpp"

typedef struct Sprite2D
{
	Transform2D transform;
	uint8_t* texture;
	Rect pixels;
	uint8_t alpha;
	bool flip;

	Sprite2D():
		alpha(255),
		flip(false)
	{}
}Sprite2D;