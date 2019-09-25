#include "Simulation.hpp"

void ElecCirSim::Simulation::analyzeFromDCVoltageSources()
{
	for (unsigned int i = 0; i < this->objects.lastDCVoltageSourceIndex; i++)
	{
		if (this->objects.dcVoltageSources.count(i))
		{
			DCVoltageSource* dcVoltageSource = &this->objects.dcVoltageSources.at(i);
			double totalResistance = this->calculateTotalDCCircuitResistance(*dcVoltageSource);
			dcVoltageSource->properties.current = dcVoltageSource->maxVoltage / totalResistance;
		}
	}
}

double ElecCirSim::Simulation::calculateTotalDCCircuitResistance(DCVoltageSource dcVoltageSource)
{
	Terminal liveDCTerminal = this->objects.terminals.at(dcVoltageSource.properties.terminalIndices.at(1));
	Terminal neutralDCTerminal = this->objects.terminals.at(dcVoltageSource.properties.terminalIndices.at(0));
	return this->calculateBranchResistanceRecursively(liveDCTerminal, neutralDCTerminal);
}

double ElecCirSim::Simulation::calculateBranchResistanceRecursively(Terminal currentTerminal, Terminal finalTerminal)
{
	double totalResistance = 0.0;

	while (!(this->isOpenCircuitTerminal(currentTerminal)) &&
		!(this->isFinalTerminalOfBranch(currentTerminal, finalTerminal)))
	{
		if (!(this->hasParallelBranch(currentTerminal)))
		{
			Terminal seriesConnectedTerminal = this->findSeriesConnectedTerminal(currentTerminal);

			switch (seriesConnectedTerminal.componentType)
			{
				case ComponentTypes::WIRE_COMPONENT:
					currentTerminal = this->findOtherTerminalOnComponent(seriesConnectedTerminal);
					break;
				case ComponentTypes::RESISTOR_COMPONENT:
					totalResistance += this->objects.resistors.at(seriesConnectedTerminal.componentIndex).properties.elements.resistance_ohms;
					currentTerminal = this->findOtherTerminalOnComponent(seriesConnectedTerminal);
					break;
			}
		}
		else
		{
			Terminal currentReverseTerminal = finalTerminal;

			while (!(this->isOpenCircuitTerminal(currentReverseTerminal) && 
				!(this->hasParallelBranch(currentReverseTerminal))))
			{
				currentReverseTerminal = this->findSeriesConnectedTerminal(currentReverseTerminal);
				currentReverseTerminal = this->findOtherTerminalOnComponent(currentReverseTerminal);
			}

			//std::vector<TerminalIndex> adjacentTerminalIndices =
			//	this->objects.terminalPositionRegistry.at(currentTerminal.position);
			//int adjacentTerminalCount = adjacentTerminalIndices.size();
			//std::vector<Terminal> branchSearchTerminals;

			//for (int i = 0; i < adjacentTerminalCount; i++)
			//	branchSearchTerminals.push_back(this->objects.terminals.at(adjacentTerminalIndices.at(i)));
		}
	}

	if (this->isOpenCircuitTerminal(currentTerminal))
		totalResistance = HUGE_VAL;

	return totalResistance;
}

bool ElecCirSim::Simulation::isOpenCircuitTerminal(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);

	return (adjacentTerminalIndices.size() == 1);
}

bool ElecCirSim::Simulation::isFinalTerminalOfBranch(Terminal terminal, Terminal finalTerminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);

	for (int i = 0; i < adjacentTerminalIndices.size(); i++)
		if (finalTerminal.index == adjacentTerminalIndices.at(i))
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
				if (this->objects.grounds.count(j))
					if (this->objects.grounds.at(j).properties.terminalIndices.at(0) == adjacentTerminalIndices.at(i))
						return true;
	}

	return false;
}

ElecCirSim::Terminal ElecCirSim::Simulation::findSeriesConnectedTerminal(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);

	Terminal seriesConnectedTerminal;

	for (int j = 0; j < 2; j++)
		if (adjacentTerminalIndices.at(j) != terminal.index)
		{
			seriesConnectedTerminal = this->objects.terminals.at(adjacentTerminalIndices.at(j));
			break;
		}

	return seriesConnectedTerminal;
}

ElecCirSim::Terminal ElecCirSim::Simulation::findOtherTerminalOnComponent(Terminal terminal)
{
	Terminal otherTerminal;
	std::vector<TerminalIndex> componentTerminalIndices;

	switch (terminal.componentType)
	{
		case ComponentTypes::WIRE_COMPONENT:
			componentTerminalIndices = this->objects.wires.at(terminal.componentIndex).properties.terminalIndices;
			break;
		case ComponentTypes::RESISTOR_COMPONENT:
			componentTerminalIndices = this->objects.resistors.at(terminal.componentIndex).properties.terminalIndices;
			break;
	}

	if (componentTerminalIndices.size() == 2)
		for (int i = 0; i < 2; i++)
			if (componentTerminalIndices.at(i) != terminal.index)
			{
				otherTerminal = this->objects.terminals.at(componentTerminalIndices.at(i));
				break;
			}

	return otherTerminal;
}

bool ElecCirSim::Simulation::hasParallelBranch(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->objects.terminalPositionRegistry.at(terminal.position);
	bool isConnectedToGround = false;
	int parallelBranches = adjacentTerminalIndices.size();

	for (int i = 0; i < adjacentTerminalIndices.size(); i++)
		if (this->objects.terminals.at(adjacentTerminalIndices.at(i)).componentType == 
			ComponentTypes::GROUND_COMPONENT)
		{
			isConnectedToGround = true;
			break;
		}

	if ((this->objects.grounds.size() == 1) && isConnectedToGround)
		parallelBranches -= 1;

	return (parallelBranches > 2);
}