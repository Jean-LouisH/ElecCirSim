/**
*                      This file is part of:
*                          ElecCirSim
*
* Sprite Cache
*
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <SDL_render.h>
#include <SDL_image.h>

namespace ElecCirSim
{
	class SpriteCache
	{
	public:
		SDL_Texture* dcVoltageSource;
		SDL_Texture* acVoltageSource;
		SDL_Texture* ground;
		SDL_Texture* powerSwitch;
		SDL_Texture* resistor;
		SDL_Texture* capacitor;
		SDL_Texture* inductor;
		SDL_Texture* potentiometer;
		SDL_Texture* transformer;
		SDL_Texture* centreTappedTransformer;
		SDL_Texture* npnTransistor;
		SDL_Texture* pnpTransistor;
		SDL_Texture* nMosfet;
		SDL_Texture* pMosfet;
		SDL_Texture* notGate;
		SDL_Texture* andGate;
		SDL_Texture* orGate;
		SDL_Texture* nandGate;
		SDL_Texture* norGate;

		void buildWithRenderer(SDL_Renderer* renderer);
		void clear();
	};
}