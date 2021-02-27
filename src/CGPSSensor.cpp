/*
 * CGPSSensor.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CGPSSensor.h"
#include <string>
#include <iostream>

CGPSSensor::CGPSSensor() {
	// TODO Auto-generated constructor stub

}

CWaypoint CGPSSensor::getCurrentPosition() {
	double latitude,longitude;
	std::string name = "USER_CURRENT_LOCATION";
	do{
		std::cout << "Enter a valid latitude(-90 <= latitude <= 90" << std::endl;
		std::cin >> latitude;
	}while (latitude < -90 || latitude > 90);

	do{
		std::cout << "Enter a valid longitude(-180 <= longitude <= 180" << std::endl;
		std::cin >> longitude;
	}while (longitude < -180 || longitude > 180);

	CWaypoint userWapoint(name,latitude,longitude);
	return userWapoint;
}

CGPSSensor::~CGPSSensor() {
	// TODO Auto-generated destructor stub
}

