/*
 * SimControl.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#include "SimControl.h"

SimControl::SimControl()
	:
	/*
	 * create earth
	 * create ship
	*/
	earth(5.972E24, 6378145.0, 3.986005E14),
	satelite(8500.0, 250000.0, 89 , 200)
{
	// TODO Auto-generated constructor stub

}

SimControl::~SimControl() {
	// TODO Auto-generated destructor stub
}

void SimControl::initialize()
{
	/*
	 * create earth
	 * create ship
	 * open/create files
	 *
	 */
	earth.setPosition(0.0, 0.0);
}

void SimControl::update()
{
	earth.generatePlanetPlotData();
	satelite.calculateOrbit(earth, "Orbital_Sim/orbitTest.txt");
}

void SimControl::executeSimulation()
{
	initialize();
	update();
}

