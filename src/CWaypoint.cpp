#include "CWaypoint.h"
#include <iostream>
#include <iomanip>
#include <cmath>
/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWAYPOINT.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations

CWaypoint::CWaypoint(std::string name, double latitude, double longitude){
	set(name,latitude,longitude);
	#ifdef SHOWADDRESS
	std::cout << "the value of name: " << m_name << std::endl;
	std::cout << "the value of latitude: " << m_latitude<< std::endl;
	std::cout << "the value of longitude: " << m_longitude << std::endl;

	std::cout << "the address of object: " << this << std::endl;
	std::cout << "the address of name: " << &m_name << std::endl;
	std::cout << "the address of latitude: " << &m_latitude << std::endl;
	std::cout << "the address of longitude: " << &m_longitude << "\n\n";
	#endif
}

void CWaypoint::set(std::string name, double latitude, double longitude) {
	this->m_name=name;
	this->m_latitude=0;
	this->m_longitude=0;
	if(latitude >= -90 && latitude <= 90)
	{
		this->m_latitude=latitude;
	}
	if(longitude >= -180 && longitude <= 180)
	{
		this->m_longitude=longitude;
	}
}

double CWaypoint::getLatitude() const {
	return this->m_latitude;
}

double CWaypoint::getLongitude() const {
	return this->m_longitude;
}

const std::string& CWaypoint::getName() const {
	return this->m_name;
}

void CWaypoint::getAllDataByReference(std::string &name, double &latitude,
		double &longitude) {
	name=this->m_name;
	latitude=this->m_latitude;
	longitude=this->m_longitude;
}

double CWaypoint::calculateDistance(const CWaypoint &wp) {
	double sinLatitude_1, sinLatitude_2, cosLatitude_1, cosLatitude_2, cosLongitudeDifference;

	sinLatitude_1 = std::sin(this->m_latitude*DEG2RAD);
	sinLatitude_2 = std::sin(wp.getLatitude()*DEG2RAD);
	cosLatitude_1 = std::cos(this->m_latitude*DEG2RAD);
	cosLatitude_2 = std::cos(wp.getLatitude()*DEG2RAD);
	cosLongitudeDifference = std::cos((wp.getLongitude()*DEG2RAD) - (this->m_longitude*DEG2RAD));
	double dist = EARTH_RADIUS * acos((sinLatitude_1 * sinLatitude_2) + cosLatitude_1 * cosLatitude_2 * cosLongitudeDifference);
//	std::cout << "Distance between " << this->m_name << " and " << wp.m_name << ": " << dist << std::endl;
	return dist;
}

void CWaypoint::print(int format) {
//	switch(format){
//	case 1: std::cout << this->m_name << " on latitude = " << this->m_latitude << " and on longitude = " << this->m_longitude << std::endl;break;
//	case 2:{
//		int deg, mm;
//		double ss;
//		int deg1, mm1;
//		double ss1;
//		transformLatitude2degmmss(deg, mm, ss);
//		transformLongitude2degmmss(deg1, mm1, ss1);
//		std::cout << this->m_name << " on latitude = " << deg << "deg " << mm << "mm " << ss << "ss "<<
//				"and" << " on longitude = " << deg1 << "deg " << mm1 << "mm " << ss1 << "ss "<< std::endl;
//		break;
//	}
//	}
//	int deg, mm;
//	double ss;
//
//	#if SHOW_DEBUG_DATA == 1
//		this->transformLatitude2degmmss(deg,mm,ss);
//		std::cout << this->m_name << " on latitude = " << this->getLatitude() << "� and on longitude = " << this->getLongitude() << "�." <<std::endl ;
//	#endif
//	#if SHOW_DEBUG_DATA == 2
//		this->transformLatitude2degmmss(deg,mm,ss);
//		std::cout << this->m_name << " on latitude = " << deg << "deg " << mm << "mm " << ss << "ss ";
//		this->transformLongitude2degmmss(deg,mm,ss);
//		std::cout << "and" << " on longitude = " << deg << "deg " << mm << "mm " << ss << "ss "<< std::endl;
//	#endif
		std::cout << *this;
}

void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, double &ss) {
	deg = (int) this->m_longitude;
	double minutes= (this->m_longitude - deg) * 60;
	mm= (int) minutes;
	ss= (minutes - mm) * 60;
}

void CWaypoint::transformLatitude2degmmss(int &deg, int &mm, double &ss) {
	deg = (int) this->m_latitude;
	double minutes= (this->m_latitude - deg) * 60;
	mm= (int) minutes;
	ss= (minutes - mm) * 60;
}

CWaypoint::~CWaypoint() {
}

std::ostream& operator << (std::ostream& out, CWaypoint& wp){
	int deg, mm;
	double ss;

#if SHOW_DEBUG_DATA == 1
	wp.transformLatitude2degmmss(deg,mm,ss);
	out << wp.m_name << " on latitude = " << wp.getLatitude() << "� and on longitude = " << wp.getLongitude() << "�." << std::endl ;
#endif
#if SHOW_DEBUG_DATA == 2
	wp.transformLatitude2degmmss(deg,mm,ss);
	out << wp.m_name << " on latitude = " << deg << "deg " << mm << "mm " << ss << "ss ";
	wp.transformLongitude2degmmss(deg,mm,ss);
	out << "and" << " on longitude = " << deg << "deg " << mm << "mm " << ss << "ss "<< std::endl;
#endif

	return out;
}
