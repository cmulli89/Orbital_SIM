/*
 * SpaceObject.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#include "SpaceObject.h"

#include <iostream> //kludge

SpaceObject::SpaceObject():
	mVelocity(0.0),
	mRadialLocation(0.0),
	mZenithAngle(0.0),
	mRadius(0.0),
	semiMajorAxis(0.0),
	eccentricity(0.0),
	numberOfIncrements(0.0)
{
	for( int i=0; DIMENSIONS > i; ++i )
	{
		cartesianLocation.push_back(0.0);
	}
}

SpaceObject::SpaceObject(double velocity, double radialLocation, double zenithAngle, double n):
		mVelocity(velocity),
		mRadialLocation(radialLocation),
		mZenithAngle(zenithAngle),
		mRadius(0.0),
		semiMajorAxis(0.0),
		eccentricity(0.0),
		numberOfIncrements(n)
{
	for( int i=0; DIMENSIONS > i; ++i )
	{
		cartesianLocation.push_back(0.0);
	}
}

SpaceObject::~SpaceObject() {}

void SpaceObject::calculateEccentricity(const Planet& planet)
{
	mRadius = mRadialLocation + planet.getRadius();
	/// - http://www.braeunig.us/space/orbmech.htm  Eq. 4.27
	eccentricity = sqrt( pow(( mRadius*pow( mVelocity ,2 ))/planet.getGravitationalParam() - 1,2) * pow(sin(PI/180 * mZenithAngle),2) +
			pow(cos(PI/180 * mZenithAngle),2) );
}

void SpaceObject::calculateOrbit(const Planet& planet, char* filename)
{
	myfile.open(filename);
	double theta = 0.0;
	calculateEccentricity(planet);
	/// - http://www.braeunig.us/space/orbmech.htm  Eq. 4.32
	semiMajorAxis = 1/( (2/mRadius) - (pow( mVelocity, 2 )/ planet.getGravitationalParam()) );
	/// - Semi-Latus-Rectum
	double p = semiMajorAxis * (1 - pow( eccentricity, 2));
	for(int i = 0; i<=numberOfIncrements; ++i){
		mRadius = p/(1 + eccentricity*cos(PI/180 * theta));       //Calculates the r values
		cartesianLocation = coordConv.polarToCartesian(mRadius, theta);
		myfile<<std::scientific<<cartesianLocation[0]<<"\t"<<cartesianLocation[1]<<std::endl;
		theta += 360.0/numberOfIncrements;

	}
	myfile.close();
}

double SpaceObject::calculateEscapeVelocity(const Planet& planet)
{
	return sqrt(2.0 * planet.getGravitationalParam() / (mRadialLocation + planet.getRadius()));
}
