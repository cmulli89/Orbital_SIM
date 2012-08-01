/*
 * CoordinateConversions.h
 *
 *  Created on: Jul 1, 2012
 *      Author: cmulli89
 */

#ifndef COORDINATECONVERSIONS_H_
#define COORDINATECONVERSIONS_H_

#define PI 3.14159265

#include <vector>
#include <cmath>

class CoordinateConversions {
public:
	CoordinateConversions();
	virtual ~CoordinateConversions();

	const std::vector<double>& polarToCartesian(const double r, const double theta) ;

private:
	std::vector<double> cartesianCoor;

};

#endif /* COORDINATECONVERSIONS_H_ */
