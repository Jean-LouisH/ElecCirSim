#include "Simulation.hpp"

void ElecCirSim::Simulation::computeDigitalLogic()
{
	for (unsigned int i = 0; i < this->componentGraph.lastLogicGateIndex; i++)
	{
		if (this->componentGraph.logicGates.count(i))
		{
			LogicGate* logicGate = &this->componentGraph.logicGates.at(i);
			Terminal* terminal1 = &this->componentGraph.terminals.at(logicGate->properties.terminalIndices.at(0));
			Terminal* terminal2 = &this->componentGraph.terminals.at(logicGate->properties.terminalIndices.at(1));
			Terminal* terminal3;

			if (this->componentGraph.terminals.count(logicGate->properties.terminalIndices.at(2)))
				terminal3 = &this->componentGraph.terminals.at(logicGate->properties.terminalIndices.at(2));

			switch (logicGate->type)
			{
				case LogicGate::NOT_GATE: 
					if (terminal1->voltage > logicGate->maxVoltage / 2.0)
					{

					}
					else
					{

					}
					break;
				case LogicGate::AND_GATE:
					if (terminal1->voltage > logicGate->maxVoltage / 2.0 &&
						terminal2->voltage > logicGate->maxVoltage / 2.0)
					{

					}
					else
					{

					}
					break;
				case LogicGate::OR_GATE:
					if (terminal1->voltage > logicGate->maxVoltage / 2.0 ||
						terminal2->voltage > logicGate->maxVoltage / 2.0)
					{

					}
					else
					{

					}
					break;
				case LogicGate::NAND_GATE:
					if (!(terminal1->voltage > logicGate->maxVoltage / 2.0 &&
						terminal2->voltage > logicGate->maxVoltage / 2.0))
					{

					}
					else
					{

					}
					break;
				case LogicGate::NOR_GATE:
					if (!(terminal1->voltage > logicGate->maxVoltage / 2.0 ||
						terminal2->voltage > logicGate->maxVoltage / 2.0))
					{

					}
					else
					{

					}
					break;
			}
		}
	}
}

void ElecCirSim::Simulation::analyzeFromDCVoltageSources()
{
	for (unsigned int i = 0; i < this->componentGraph.lastDCVoltageSourceIndex; i++)
	{
		//Previous DC Voltages may have been removed, so every one should be checked
		// for existence before using.
		if (this->componentGraph.dcVoltageSources.count(i))
		{
			DCVoltageSource* dcVoltageSource = &this->componentGraph.dcVoltageSources.at(i);
			double totalResistance = this->calculateTotalDCCircuitResistance(*dcVoltageSource);
			dcVoltageSource->properties.current = dcVoltageSource->maxVoltage / totalResistance;
		}
	}
}

double ElecCirSim::Simulation::calculateTotalDCCircuitResistance(DCVoltageSource dcVoltageSource)
{
	Terminal liveDCTerminal = this->componentGraph.terminals.at(dcVoltageSource.properties.terminalIndices.at(1));
	Terminal neutralDCTerminal = this->componentGraph.terminals.at(dcVoltageSource.properties.terminalIndices.at(0));
	return this->calculateBranchResistanceRecursively(liveDCTerminal, neutralDCTerminal);
}

double ElecCirSim::Simulation::calculateBranchResistanceRecursively(Terminal currentTerminal, Terminal finalTerminal)
{
	double totalResistance = 0.0;

	while (!(this->isOpenCircuitTerminal(currentTerminal)) &&
		!(this->isFinalTerminalOfBranch(currentTerminal, finalTerminal)) &&
		!(totalResistance != HUGE_VAL))
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
					totalResistance += this->componentGraph.resistors.at(seriesConnectedTerminal.componentIndex).properties.elements.resistance_ohms;
					currentTerminal = this->findOtherTerminalOnComponent(seriesConnectedTerminal);
					break;
				case ComponentTypes::POWER_SWITCH_COMPONENT:
					if (!this->componentGraph.switches.at(seriesConnectedTerminal.componentIndex).isClosed)
						totalResistance = HUGE_VAL;
					break;
			}
		}
		else
		{
			Terminal currentReverseTerminal = finalTerminal;
			Terminal otherParallelTerminal;

			while (!(this->isOpenCircuitTerminal(currentReverseTerminal)) &&
				!(this->areConnected(currentReverseTerminal, currentTerminal)))
			{
				if (!(this->hasParallelBranch(currentReverseTerminal)))
				{
					currentReverseTerminal = this->findSeriesConnectedTerminal(currentReverseTerminal);
					currentReverseTerminal = this->findOtherTerminalOnComponent(currentReverseTerminal);
				}
				else
				{
					otherParallelTerminal = currentReverseTerminal;
					std::vector<TerminalIndex> adjacentTerminalIndices =
							this->componentGraph.terminalPositionRegistry.at(otherParallelTerminal.position);

					int adjacentTerminalCount = adjacentTerminalIndices.size();
					for (int i = 0; i < adjacentTerminalCount; i++)
						;
				}
			}

			if (this->areConnected(currentReverseTerminal, currentTerminal))
			{
				std::vector<TerminalIndex> adjacentTerminalIndices =
					this->componentGraph.terminalPositionRegistry.at(currentTerminal.position);
				double parallelConductance = 0.0;

				for (int i = 0; i < adjacentTerminalIndices.size(); i++)
				{
					if (adjacentTerminalIndices.at(i) != currentTerminal.index)
					{
						Terminal branchTerminal = this->componentGraph.terminals.at(adjacentTerminalIndices.at(i));
						parallelConductance += 1.0 / this->calculateBranchResistanceRecursively(branchTerminal, otherParallelTerminal);
					}
				}

				totalResistance += 1.0 / parallelConductance;
				currentTerminal = this->findOtherTerminalOnComponent(otherParallelTerminal);
			}
		}
	}

	if (this->isOpenCircuitTerminal(currentTerminal))
		totalResistance = HUGE_VAL;

	return totalResistance;
}

bool ElecCirSim::Simulation::isOpenCircuitTerminal(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->componentGraph.terminalPositionRegistry.at(terminal.position);

	return (adjacentTerminalIndices.size() == 1);
}

bool ElecCirSim::Simulation::isFinalTerminalOfBranch(Terminal terminal, Terminal finalTerminal)
{
	if (this->areConnected(terminal, finalTerminal))
		return true;

	return this->isGroundReturnPathTerminal(terminal);
}

bool ElecCirSim::Simulation::isGroundReturnPathTerminal(Terminal terminal)
{
	if (this->componentGraph.grounds.size() > 1)
	{
		std::vector<TerminalIndex> adjacentTerminalIndices =
			this->componentGraph.terminalPositionRegistry.at(terminal.position);

		for (int i = 0; i < adjacentTerminalIndices.size(); i++)
			for (int j = 1; j < this->componentGraph.lastGroundIndex; i++)
				if (this->componentGraph.grounds.count(j))
					if (this->componentGraph.grounds.at(j).properties.terminalIndices.at(0) == adjacentTerminalIndices.at(i))
						return true;
	}

	return false;
}

ElecCirSim::Terminal ElecCirSim::Simulation::findSeriesConnectedTerminal(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->componentGraph.terminalPositionRegistry.at(terminal.position);

	Terminal seriesConnectedTerminal;

	for (int j = 0; j < 2; j++)
		if (adjacentTerminalIndices.at(j) != terminal.index)
		{
			seriesConnectedTerminal = this->componentGraph.terminals.at(adjacentTerminalIndices.at(j));
			break;
		}

	return seriesConnectedTerminal;
}

bool ElecCirSim::Simulation::areConnected(Terminal firstTerminal, Terminal secondTerminal)
{
	return (firstTerminal.position.x == secondTerminal.position.x) &&
		(firstTerminal.position.y == secondTerminal.position.y);
}

ElecCirSim::Terminal ElecCirSim::Simulation::findOtherTerminalOnComponent(Terminal terminal)
{
	Terminal otherTerminal;
	std::vector<TerminalIndex> componentTerminalIndices;

	switch (terminal.componentType)
	{
		case ComponentTypes::WIRE_COMPONENT:
			componentTerminalIndices = this->componentGraph.wires.at(terminal.componentIndex).properties.terminalIndices;
			break;
		case ComponentTypes::RESISTOR_COMPONENT:
			componentTerminalIndices = this->componentGraph.resistors.at(terminal.componentIndex).properties.terminalIndices;
			break;
	}

	if (componentTerminalIndices.size() == 2)
		for (int i = 0; i < 2; i++)
			if (componentTerminalIndices.at(i) != terminal.index)
			{
				otherTerminal = this->componentGraph.terminals.at(componentTerminalIndices.at(i));
				break;
			}

	return otherTerminal;
}

bool ElecCirSim::Simulation::hasParallelBranch(Terminal terminal)
{
	std::vector<TerminalIndex> adjacentTerminalIndices =
		this->componentGraph.terminalPositionRegistry.at(terminal.position);
	bool isConnectedToGround = false;
	int parallelBranches = adjacentTerminalIndices.size();

	for (int i = 0; i < adjacentTerminalIndices.size(); i++)
		if (this->componentGraph.terminals.at(adjacentTerminalIndices.at(i)).componentType == 
			ComponentTypes::GROUND_COMPONENT)
		{
			isConnectedToGround = true;
			break;
		}

	if ((this->componentGraph.grounds.size() == 1) && isConnectedToGround)
		parallelBranches -= 1;

	return (parallelBranches > 2);
}