/*
 * SimControl.h
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#ifndef SIMCONTROL_H_
#define SIMCONTROL_H_

#include "SpaceObject.h"

class SimControl {
public:
	SimControl();
	virtual ~SimControl();

	void executeSimulation();

private:
	void initialize();
	void update();

	Planet earth;
	SpaceObject satelite;

};

#endif /* SIMCONTROL_H_ */
