/*
 * CWpDatabase.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CWpDatabase.h"

CWpDatabase::CWpDatabase() {
	// TODO Auto-generated constructor stub

}

void CWpDatabase::addWaypoint(const CWaypoint &Wp) {
	m_Waypoint.insert(std::pair<std::string, CWaypoint>(Wp.getName(),Wp));
}

CWaypoint* CWpDatabase::getPointerToWp(std::string WpName) {
	CWaypoint* PtrToWp = NULL;
		for(auto& Wp: m_Waypoint)
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
}

CWpDatabase::~CWpDatabase() {
	// TODO Auto-generated destructor stub
}

