#include "SpriteCache.hpp"

void ElecCirSim::SpriteCache::buildWithRenderer(SDL_Renderer* renderer)
{
	SDL_Surface* dcVoltageSourceSurface = IMG_Load("../../Data/Sprites/dc_voltage_source.png");
	SDL_Surface* groundSurface = IMG_Load("../../Data/Sprites/ground.png");
	SDL_Surface* resistorSurface = IMG_Load("../../Data/Sprites/resistor.png");
	SDL_Surface* capacitorSurface = IMG_Load("../../Data/Sprites/capacitor.png");
	SDL_Surface* inductorSurface = IMG_Load("../../Data/Sprites/inductor.png");

	this->dcVoltageSource = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->ground = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->resistor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->capacitor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->inductor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);

	SDL_FreeSurface(dcVoltageSourceSurface);
	SDL_FreeSurface(groundSurface);
	SDL_FreeSurface(resistorSurface);
	SDL_FreeSurface(capacitorSurface);
	SDL_FreeSurface(inductorSurface);
}

void ElecCirSim::SpriteCache::clear()
{
	SDL_DestroyTexture(this->dcVoltageSource);
	//SDL_DestroyTexture(this->acVoltageSource);
	SDL_DestroyTexture(this->ground);
	//SDL_DestroyTexture(this->powerSwitch);
	SDL_DestroyTexture(this->resistor);
	SDL_DestroyTexture(this->capacitor);
	SDL_DestroyTexture(this->inductor);
	//SDL_DestroyTexture(this->potentiometer);
	//SDL_DestroyTexture(this->transformer);
	//SDL_DestroyTexture(this->centreTappedTransformer);
	//SDL_DestroyTexture(this->npnTransistor);
	//SDL_DestroyTexture(this->pnpTransistor);
	//SDL_DestroyTexture(this->nMosfet);
	//SDL_DestroyTexture(this->pMosfet);
	//SDL_DestroyTexture(this->notGate);
	//SDL_DestroyTexture(this->andGate);
	//SDL_DestroyTexture(this->orGate);
	//SDL_DestroyTexture(this->nandGate);
	//SDL_DestroyTexture(this->norGate);
}