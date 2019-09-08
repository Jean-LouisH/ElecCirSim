#include "Renderer2D.hpp"
#include <GL/glew.h>

void ElecCirSim::Renderer2D::clearBuffers()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}