/*
 * CPOI.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: reza
 */

#include "CPOI.h"
#include <iostream>

//const char* POIType_ar[] = {
//		"Restaurant",
//		"Touristic",
//		"GasStation",
//		"University",
//		"Krankenhaus",
//		"BusStation",
//		"School",
//		"Monument",
//		"NO POI exists",
//};

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
	std::cout << " of type " << poiTypeToString() << " : " << this->m_description << std::endl;
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

CPOI::t_poi CPOI::getType() {
	return m_type;
}

std::string CPOI::getDescription() {
	return m_description;
}

CPOI::~CPOI()
{
}

std::string CPOI::poiTypeToString() {
	std::string typeString;
	switch((int)m_type){
	case 0:typeString = "RESTAURANT";break;
	case 1:typeString = "TOURISTIC";break;
	case 2:typeString = "GASSTATION";break;
	case 3:typeString = "UNIVERSITY";break;
	case 4:typeString = "KRANKENHAUS";break;
	case 5:typeString = "BUSSTATION";break;
	case 6:typeString = "SCHOOL";break;
	case 7:typeString = "MONUMENT";break;
	case 8:typeString = "DEFAULT";break;
	}
	return typeString;
}
