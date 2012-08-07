/*
 * SimVars.h
 *
 *  Created on: Aug 6, 2012
 *      Author: cmulli89
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief This class is used to define all the variables for the SIM.
///
/// @details This is where SpaceObjects and Planets are defined that are used in the simulation. This
///          class provides a single location for all the instantiations of the classes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMVARS_H_
#define SIMVARS_H_

class SimVars
{
public:
	SimVars():
		earth(5.972E24, 6378145.0, 3.986005E14),
		satelite(7754.84, 250000.0, 89 , 200)
	{
		earth.setPosition(0.0, 0.0);
	};

	virtual ~SimVars()
	{};

	Planet earth;
	SpaceObject satelite;


};



#endif /* SIMVARS_H_ */
