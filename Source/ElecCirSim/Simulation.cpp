#include "Simulation.hpp"

//bool ElecCirSim::Simulation::isOpenCircuitTerminal(Terminal terminal)
//{
//	std::vector<TerminalIndex> adjacentTerminalIndices =
//		this->objects.terminalPositionRegistry.at(terminal.position);
//
//	return (adjacentTerminalIndices.size() == 0);
//}
//
//bool ElecCirSim::Simulation::isFinalTerminalOfCircuit(Terminal terminal, DCVoltageSource dcVoltageSource)
//{
//	std::vector<TerminalIndex> adjacentTerminalIndices =
//		this->objects.terminalPositionRegistry.at(terminal.position);
//
//	for (int i = 0; i < adjacentTerminalIndices.size(); i++)
//		if (dcVoltageSource.properties.terminalIndices.at(0) == adjacentTerminalIndices.at(i))
//			return true;
//
//	return false;
//}

void ElecCirSim::Simulation::analyzeFromVoltageSource()
{
	for (unsigned int i = 0; i < this->objects.lastDCVoltageSourceIndex; i++)
	{
		if (this->objects.dcVoltageSources.count(i) > 0)
		{
			DCVoltageSource dcVoltageSource = this->objects.dcVoltageSources.at(i);
			Terminal liveTerminal = this->objects.terminals.at(dcVoltageSource.properties.terminalIndices.at(1));
			Terminal currentTerminal = liveTerminal;

			//while (!this->isOpenCircuitTerminal(currentTerminal) &&
			//	!this->isFinalTerminalOfCircuit(currentTerminal, dcVoltageSource))
			//{

			//}
		}
	}
}