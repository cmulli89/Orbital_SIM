/*
 * SimControl.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#include "SimControl.h"
#include <iostream>

SimControl::SimControl()
	:
	/*
	 * create earth
	 * create ship
	*/
	earth(5.972E24, 6378145.0, 3.986005E14),
	satelite(7754.84, 250000.0, 89 , 200)
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
	satelite.setVelocity(14967);
	satelite.calculateOrbit(earth, "Orbital_Sim/orbitTestTwo.txt");
	std::cout<<satelite.calculateEscapeVelocity(earth)<<std::endl;
}

void SimControl::executeSimulation()
{
	initialize();
	update();
}

