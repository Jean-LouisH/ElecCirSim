#pragma once

namespace ElecCirSim
{
	typedef struct ElectricalElements
	{
		double resistance_ohms;
		double capacitance_farads;
		double inductance_henries;

		ElectricalElements():
			resistance_ohms(0.0),
			capacitance_farads(0.0),
			inductance_henries(0.0)
		{}
	}ElectricalElements;
}