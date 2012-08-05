/*
 * SimControl.h
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#ifndef SIMCONTROL_H_
#define SIMCONTROL_H_

#include "SpaceObject.h"
//#include <Python.h>

// TRYING TO INGRATE PYTHON INTO C++ CODE UNDER PLOT()

class SimControl {
public:
	SimControl();
	virtual ~SimControl();

	void executeSimulation();

private:
	void initialize();
	void update();
	void plot();

	Planet earth;
	SpaceObject satelite;

};

#endif /* SIMCONTROL_H_ */
