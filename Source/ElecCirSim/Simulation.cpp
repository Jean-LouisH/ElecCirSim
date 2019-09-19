#include "Simulation.hpp"

void ElecCirSim::Simulation::analyzeFromVoltageSource()
{
	for (unsigned int i = 0; i < this->objects.lastDCVoltageSourceIndex; i++)
	{
		if (this->objects.dcVoltageSources.count(i) > 0)
		{
			DCVoltageSource dcVoltageSource = this->objects.dcVoltageSources.at(i);
			Terminal liveTerminal = this->objects.terminals.at(dcVoltageSource.properties.terminalIndices.at(1));
			Terminal currentTerminal = liveTerminal;

			while (!this->isOpenCircuitTerminal(currentTerminal) &&
				!this->isFinalTerminalOfCircuit(currentTerminal, dcVoltageSource))
			{

			}
		}
	}
}

bool ElecCirSim::Simulation::isOpenCircuitTerminal(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);

	return (adjacentTerminalIndices.size() == 0);
}

bool ElecCirSim::Simulation::isFinalTerminalOfCircuit(Terminal terminal, DCVoltageSource dcVoltageSource)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);

	for (int i = 0; i < adjacentTerminalIndices.size(); i++)
		if (dcVoltageSource.properties.terminalIndices.at(0) == adjacentTerminalIndices.at(i))
			return true;

	return this->isGroundReturnPathTerminal(terminal);
}

bool ElecCirSim::Simulation::isGroundReturnPathTerminal(Terminal terminal)
{
	if (this->objects.grounds.size() > 1)
	{
		std::vector<TerminalIndex> adjacentTerminalIndices =
			this->objects.terminalPositionRegistry.at(terminal.position);

		for (int i = 0; i < adjacentTerminalIndices.size(); i++)
			for (int j = 1; j < this->objects.lastGroundIndex; i++)
				if (this->objects.grounds.at(j).properties.terminalIndices.at(0) == adjacentTerminalIndices.at(i))
					return true;
	}

	return false;
}