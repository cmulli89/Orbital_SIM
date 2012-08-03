/*
 * Planet.h
 *
 *  Created on: Mar 18, 2012
 *      Author: cmulli89
 */

#ifndef PLANET_H_
#define PLANET_H_

#include <vector>
#include "CoordinateConversions.h"
#include <fstream>
#include <cstring>
#include <iomanip>

static const int DIMENSIONS = 2;

class Planet {
public:
	Planet();
	Planet(double mass, double radius, double gravitationalParameter);

	virtual ~Planet();

    std::vector<double> getPosition() const;
    void setPosition(double xLoc, double yLoc);
    const double& getGravitationalParam() const;
    double getRadius() const;
    void generatePlanetPlotData();

private:
	double mMass;                      /// (kg)      Mass of planet
    std::vector<double> mPosition;     /// (m)       Location of center of planet
	double mRadius;                    /// (m)       Mean radius of planet
	const double mGravitationalParam;  /// (m^3/s^2) GM =~ G(M+m), planetary constant
	std::vector<double> cartesianLocation;
	CoordinateConversions coordConv;
	std::ofstream myfile;  ///Declares operator for output file functions



};

#endif /* PLANET_H_ */
