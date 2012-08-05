/*
 * SpaceObject.h
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#ifndef SPACEOBJECT_H_
#define SPACEOBJECT_H_

#define PI 3.14159265

#include "Planet.h"
#include "CoordinateConversions.h"
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>


class SpaceObject {
public:

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This is the default constructor for the SpaceObject Class.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	SpaceObject();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This is the overloaded constructor for the SpaceObject Class.
	///
	/// @param[in] velocity       (km/s) Magnitude of the current velocity of the object.
	/// @param[in] radialLocation (km)   Distance of the object from the planet's surface.
	/// @param[in] zenithAngle    (deg)  Angle between pos and vel vectors.
	/// @param[in] n              (--)   Number of increments for generating the orbital data.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	SpaceObject(double velocity, double radialLocation, double zenithAngle, double n);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This is the default deconstructor for the SpaceObject Class.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual ~SpaceObject();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This function calculates the eccentricity of the object orbiting the given planet.
	///
	/// @param[in] planet (--) Planet that the space object is orbiting.
	///
	/// @return void
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	void calculateEccentricity(const Planet& planet);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This function calculates the orbit of the object around the given planet.
	///
	/// @param[in] planet   (--) Planet that the space object is orbiting.
	/// @param[in] filename (--) Name of the file that the orbit data is written too.
	///
	/// @return void
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	void calculateOrbit(const Planet& planet, const char* filename);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This function sets the velocity of the object.
	///
	/// @param[in] velocity   (m/s) New velocity of the space object.
	///
	/// @return void
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setVelocity(const double velocity)
	{
		mVelocity = velocity;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief This function calculates the velocity the object would need to escape its current orbit and
	///        launch on to a parabolic trajectory.
	///
	/// @return escapeVelocity (m/s) Velocity needed to escape current orbit.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	double calculateEscapeVelocity(const Planet& planet);

private:
	double mVelocity;          /// (m/s) Velocity of object
	double mRadialLocation;    /// (m)   Location of object from surface of planet
	double mZenithAngle;       /// (deg) Angle between pos and vel vectors
	double mRadius;            /// (m)   Location of object from center of planet
	double semiMajorAxis;      /// (m)   Half of the major orbit axis
	double eccentricity;       /// (--)  Variable that describes shape of orbit
	double numberOfIncrements; /// (--)  Number of increments for generating orbit
	double escapeVelocity;     /// (m/s) Velocity required so KE = gravitational Force
	std::vector<double> cartesianLocation;
	CoordinateConversions coordConv;
	std::ofstream myfile;  ///Declares operator for output file functions
};

#endif /* SPACEOBJECT_H_ */
