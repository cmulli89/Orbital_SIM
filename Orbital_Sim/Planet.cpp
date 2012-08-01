/*
 * Planet.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: cmulli89
 */

#include "Planet.h"

Planet::Planet():
mMass(0.0),
mRadius(0.0),
mGravitationalParam(0.0)

{
	for( int i=0; DIMENSIONS > i; ++i )
	{
		mPosition.push_back(0.0);
	}
}

Planet::Planet(double mass, double radius, double gravitationalParameter):
		mMass(mass),
		mRadius(radius),
		mGravitationalParam(gravitationalParameter)
{
	for( int i=0; DIMENSIONS > i; ++i )
	{
		mPosition.push_back(0.0);
	}
}

Planet::~Planet()
{
	// TODO Auto-generated destructor stub
}

std::vector<double> Planet::getPosition() const
{
    return mPosition;
}

void Planet::setPosition(double xLoc, double yLoc)
{
    mPosition[0] = xLoc;
    mPosition[1] = yLoc;
}

const double& Planet::getGravitationalParam() const
{
    return mGravitationalParam;
}

double Planet::getRadius() const
{
    return mRadius ;
}

void Planet::generatePlanetPlotData()
{
	myfile.open("Orbital_Sim/PlanetData.txt");
	double theta = 0.0;
	for (int i=0; 200 >= i; ++i)
	{
		cartesianLocation = coordConv.polarToCartesian(mRadius, theta);
		myfile<<std::scientific<<cartesianLocation[0]<<"\t"<<cartesianLocation[1]<<std::endl;
		theta += 360.0/200;
	}
	myfile.close();
}







