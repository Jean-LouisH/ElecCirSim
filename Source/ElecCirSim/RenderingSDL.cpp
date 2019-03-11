#include "RenderingSDL.hpp"
#include "SDLRenderable.hpp"

void Rendering2D::SDL::buildRenderablesFromComponents(
	std::vector<SDLRenderable>* SDLRenderables,
	std::vector<ElecCirSim::Component> components,
	Camera2D camera2D,
	SDL_Window* window)
{
	SDLRenderables->clear();
	int windowWidth_px = 0;
	int windowHeight_px = 0;
	SDL_GetWindowSize(window, &windowWidth_px, &windowHeight_px);

	int spriteCount = components.size();
	for (int i = 0; i < spriteCount; i++)
	{
		Sprite2D* sprite = &components.at(i).sprite;

		double spriteWidth = sprite->pixels.width;
		double spriteHeight = sprite->pixels.height;
		double spriteWidthScaled = spriteWidth * sprite->transform.scale.x;
		double spriteHeightScaled = spriteHeight * sprite->transform.scale.y;
		double cameraWidth = camera2D.viewport_px.width;
		double cameraHeight = camera2D.viewport_px.height;
		double cameraX = camera2D.transform.position_px.x;
		double cameraY = camera2D.transform.position_px.y;
		double spriteX = sprite->transform.position_px.x;
		double spriteY = sprite->transform.position_px.y;
		double rotationRelativeToCamera = 
			(sprite->transform.rotation_rad - camera2D.transform.rotation_rad) * 180.0;

		SDLRenderable renderable;
		renderable.texture = sprite->texture;
		
		renderable.textureRect.x = 0;
		renderable.textureRect.y = 0;
		renderable.textureRect.w = spriteWidth;
		renderable.textureRect.h = spriteHeight;
		
		renderable.renderingRect.x = (int)((((spriteX - (spriteWidthScaled / 2.0) - cameraX) / cameraWidth) + 0.5) * (double)windowWidth_px);
		renderable.renderingRect.y = (int)((((cameraY - spriteY - (spriteHeightScaled / 2.0)) / cameraHeight) + 0.5) * (double)windowHeight_px);
		renderable.renderingRect.w = (int)(spriteWidthScaled / cameraWidth * (double)windowWidth_px);
		renderable.renderingRect.h = (int)(spriteHeightScaled / cameraHeight * (double)windowHeight_px);
		
		renderable.rotation = rotationRelativeToCamera;
		renderable.flip = sprite->flip;
		
		SDLRenderables->push_back(renderable);
	}
}