#include "TextureCache.hpp"

void ElecCirSim::TextureCache::buildWithRenderer(SDL_Renderer* renderer)
{
	SDL_Surface* dcVoltageSourceSurface = IMG_Load("../../Data/Sprites/dc_voltage_source.png");
	SDL_Surface* acVoltageSourceSurface = IMG_Load("");
	SDL_Surface* groundSurface = IMG_Load("../../Data/Sprites/ground.png");
	SDL_Surface* powerSwitchSurface = IMG_Load("");
	SDL_Surface* resistorSurface = IMG_Load("../../Data/Sprites/resistor.png");
	SDL_Surface* capacitorSurface = IMG_Load("../../Data/Sprites/capacitor.png");
	SDL_Surface* inductorSurface = IMG_Load("../../Data/Sprites/inductor.png");
	SDL_Surface* potentiometerSurface = IMG_Load("");
	SDL_Surface* transformerSurface = IMG_Load("");
	SDL_Surface* centreTappedTransformerSurface = IMG_Load("");
	SDL_Surface* npnTransistorSurface = IMG_Load("");
	SDL_Surface* pnpTransistorSurface = IMG_Load("");
	SDL_Surface* nMosfetSurface = IMG_Load("");
	SDL_Surface* pMosfetSurface = IMG_Load("");
	SDL_Surface* notGateSurface = IMG_Load("");
	SDL_Surface* andGateSurface = IMG_Load("");
	SDL_Surface* orGateSurface = IMG_Load("");
	SDL_Surface* nandGateSurface = IMG_Load("");
	SDL_Surface* norGateSurface = IMG_Load("");

	this->dcVoltageSource = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->acVoltageSource = SDL_CreateTextureFromSurface(renderer, acVoltageSourceSurface);
	this->ground = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->powerSwitch = SDL_CreateTextureFromSurface(renderer, powerSwitchSurface);
	this->resistor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->capacitor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->inductor = SDL_CreateTextureFromSurface(renderer, dcVoltageSourceSurface);
	this->potentiometer = SDL_CreateTextureFromSurface(renderer, potentiometerSurface);
	this->transformer = SDL_CreateTextureFromSurface(renderer, transformerSurface);
	this->centreTappedTransformer = SDL_CreateTextureFromSurface(renderer, centreTappedTransformerSurface);
	this->npnTransistor = SDL_CreateTextureFromSurface(renderer, npnTransistorSurface);
	this->pnpTransistor = SDL_CreateTextureFromSurface(renderer, pnpTransistorSurface);
	this->nMosfet = SDL_CreateTextureFromSurface(renderer, nMosfetSurface);
	this->pMosfet = SDL_CreateTextureFromSurface(renderer, pMosfetSurface);
	this->notGate = SDL_CreateTextureFromSurface(renderer, notGateSurface);
	this->andGate = SDL_CreateTextureFromSurface(renderer, andGateSurface);
	this->orGate = SDL_CreateTextureFromSurface(renderer, orGateSurface);
	this->nandGate = SDL_CreateTextureFromSurface(renderer, nandGateSurface);
	this->norGate = SDL_CreateTextureFromSurface(renderer, norGateSurface);

	SDL_FreeSurface(dcVoltageSourceSurface);
	SDL_FreeSurface(acVoltageSourceSurface);
	SDL_FreeSurface(groundSurface);
	SDL_FreeSurface(powerSwitchSurface);
	SDL_FreeSurface(resistorSurface);
	SDL_FreeSurface(capacitorSurface);
	SDL_FreeSurface(inductorSurface);
	SDL_FreeSurface(potentiometerSurface);
	SDL_FreeSurface(transformerSurface);
	SDL_FreeSurface(centreTappedTransformerSurface);
	SDL_FreeSurface(npnTransistorSurface);
	SDL_FreeSurface(pnpTransistorSurface);
	SDL_FreeSurface(nMosfetSurface);
	SDL_FreeSurface(pMosfetSurface);
	SDL_FreeSurface(notGateSurface);
	SDL_FreeSurface(andGateSurface);
	SDL_FreeSurface(orGateSurface);
	SDL_FreeSurface(nandGateSurface);
	SDL_FreeSurface(norGateSurface);
}

void ElecCirSim::TextureCache::clear()
{
	SDL_DestroyTexture(this->dcVoltageSource);
	SDL_DestroyTexture(this->acVoltageSource);
	SDL_DestroyTexture(this->ground);
	SDL_DestroyTexture(this->powerSwitch);
	SDL_DestroyTexture(this->resistor);
	SDL_DestroyTexture(this->capacitor);
	SDL_DestroyTexture(this->inductor);
	SDL_DestroyTexture(this->potentiometer);
	SDL_DestroyTexture(this->transformer);
	SDL_DestroyTexture(this->centreTappedTransformer);
	SDL_DestroyTexture(this->npnTransistor);
	SDL_DestroyTexture(this->pnpTransistor);
	SDL_DestroyTexture(this->nMosfet);
	SDL_DestroyTexture(this->pMosfet);
	SDL_DestroyTexture(this->notGate);
	SDL_DestroyTexture(this->andGate);
	SDL_DestroyTexture(this->orGate);
	SDL_DestroyTexture(this->nandGate);
	SDL_DestroyTexture(this->norGate);
}