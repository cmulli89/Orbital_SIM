/*
 * CoordinateConversions.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#include "CoordinateConversions.h"

CoordinateConversions::CoordinateConversions()
{
	for( int i=0; 2 > i; ++i )
	{
		cartesianCoor.push_back(0.0);
	}
}

CoordinateConversions::~CoordinateConversions() {
	// TODO Auto-generated destructor stub
}

const std::vector<double>& CoordinateConversions::polarToCartesian(const double r, const double theta)
{
	cartesianCoor[0] = r*cos(PI/180 * theta); // X coordinate
	cartesianCoor[1] = r*sin(PI/180 * theta); // Y coordinate
	return cartesianCoor;
}
