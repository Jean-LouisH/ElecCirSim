#include "TerminalPositionRegistry.hpp"

uint64_t ElecCirSim::TerminalPositionRegistry::hash(Vector2 position)
{
	return ((uint64_t)position.x) + (((uint64_t)position.y) << 32);
}

std::vector<ElecCirSim::TerminalIndex> ElecCirSim::TerminalPositionRegistry::at(Vector2 position)
{
	return this->registry.at(this->hash(position));
}