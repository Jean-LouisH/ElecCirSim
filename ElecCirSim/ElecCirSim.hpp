/**
*                          ElecCirSim
*
* Analogue and digital circuit simulator
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include "Engine.hpp"

namespace ElecCirSim
{
	void initialize(Engine* engine);
	void loop(Engine* engine);
	void input(Engine* engine);
	void output(Engine* engine);
	void shutdown(Engine* engine);
}