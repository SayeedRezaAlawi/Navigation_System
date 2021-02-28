/*
 * CPOI.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: reza
 */

#include "CPOI.h"
#include <iostream>

const char* POIType_ar[] = {
		"Restaurant",
		"Touristic",
		"GasStation",
		"University",
		"Krankenhaus",
		"BusStation",
		"School",
		"Monument",
		"NO POI exists",
};

CPOI::CPOI(t_poi type, std::string name, std::string description,
		double latitude, double longitude){
			this->m_type = type;
			this->m_name = name;
			this->m_description = description;
			this->m_latitude = latitude;
			this->m_longitude = longitude;
}

void CPOI::print() {
	std::cout << "Point of Interest" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << " of type " << POIType_ar[m_type] << " : " << this->m_description << std::endl;
	CWaypoint::print(2);
}

void CPOI::getAllDataByReference(std::string &name, double &latitude,
		double &longitude, t_poi &type, std::string &description) {
	type = this->m_type;
	name = this->m_name;
	description = this->m_description;
	latitude = this->m_latitude;
	longitude = this->m_longitude;
}

CPOI::CPOI() {
}

CPOI::~CPOI()
{
}
