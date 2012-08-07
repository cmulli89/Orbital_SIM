/*
 * SimControl.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#include "SimControl.h"
#include <iostream>
#include <cstdlib>

SimControl::SimControl():
	simVar()
{
	// TODO Auto-generated constructor stub

}

SimControl::~SimControl() {
	// TODO Auto-generated destructor stub
}

void SimControl::initialize()
{
	//Nothing to do here
}

void SimControl::update()
{
	simVar.earth.generatePlanetPlotData();
	simVar.satelite.calculateOrbit(simVar.earth, "Orbital_Sim/orbitTest.txt");
	simVar.satelite.setVelocity(14967);
	simVar.satelite.calculateOrbit(simVar.earth, "Orbital_Sim/orbitTestTwo.txt");
	std::cout<<"Escape Velocity = "<<simVar.satelite.calculateEscapeVelocity(simVar.earth)<<std::endl;
	plot();
}

void SimControl::executeSimulation()
{
	initialize();
	update();
}

void SimControl::plot()
{
	//Path is specific to location of SIM files on current computer.

	//Work Set
	//system("python ~/Orbital_SIM/Workspace/Orbital_Sim/makePlots.py");
	//Home Set
	system("python ~/workspace/Orbital_SIM/Orbital_Sim/makePlots.py");
}

