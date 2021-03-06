/*
 * CWpDatabase.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CWpDatabase.h"
#include <iostream>

CWpDatabase::CWpDatabase() {
}

void CWpDatabase::addWaypoint(const CWaypoint &Wp) {
	m_Waypoints.insert(std::pair<std::string, CWaypoint>(Wp.getName(),Wp));
}

CWaypoint* CWpDatabase::getPointerToWp(std::string WpName) {
	CWaypoint* PtrToWp = NULL;
		for(auto& Wp: m_Waypoints)
		{
			if(Wp.first == WpName)
			{
				PtrToWp=&Wp.second;
				break;
			}
		}
		return PtrToWp;
}

void CWpDatabase::print() {
	for(auto& wp:m_Waypoints){
		std::cout << wp.second.getName() << ";" << wp.second.getLatitude() << ";" << wp.second.getLongitude() << std::endl;
	}
}

CWpDatabase::~CWpDatabase() {
}

CWpDatabase::Waypoin_map CWpDatabase::getWaypoints() const {

	return m_Waypoints;
}

void CWpDatabase::clearDb() {
	m_Waypoints.clear();
}
