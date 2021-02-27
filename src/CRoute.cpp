/*
 * CRoute.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CRoute.h"
#include <iostream>

CRoute::CRoute() {
	m_nextPoi = 0;
	m_nextWp = 0;
	m_pPoiDatabase = NULL;
	m_pWpDatabase = NULL;
	m_pRoute.clear();
}

CRoute::CRoute(CRoute &origin) {
	this->m_nextPoi = origin.m_nextPoi;
	this->m_nextWp = origin.m_nextWp;
	this->m_pPoiDatabase = origin.m_pPoiDatabase;
	this->m_pWpDatabase = origin.m_pWpDatabase;
}

void CRoute::connectToPoiDatabase(CPoiDatabase *pPoiDB) {
	m_pPoiDatabase = pPoiDB;
}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB){
	m_pWpDatabase = pWpDB;
}

void CRoute::addWaypoint(std::string WpName) {
	CWaypoint* ptrToWpDB;
	if(m_pWpDatabase != NULL){
		ptrToWpDB = m_pWpDatabase->getPointerToWp(WpName);
		if(ptrToWpDB  != NULL){
			m_pRoute.push_back(ptrToWpDB);
			m_nextWp++;
		}
		else{
			std::cout << "the way point is not exist in the Waypoint Database." << std::endl;
		}
	}
	else{
		std::cout << "the Waypoint Database is not connected" << std::endl;
	}
}

void CRoute::addPoi(std::string namePoi) {
	CPOI* ptrToPoiDB =NULL;
	if(m_pPoiDatabase != NULL){
		ptrToPoiDB  = m_pPoiDatabase->getPointerToPoi(namePoi);
		if(ptrToPoiDB  != NULL){
			m_pRoute.push_back(ptrToPoiDB);
			m_nextPoi++;
		}
		else{
			std::cout << "the point of interest is not exist in the POI Database." << std::endl;
		}
	}
	else{
		std::cout << "the POI Database is not connected" << std::endl;
	}
}

double CRoute::getDistanceNextPoi(const CWaypoint &wp, CPOI &poi) {
	double distance;
	double closestDistance=DEFAULT_VALUE_FOR_NO_POI;
	CPOI* closestPOI;
	if(m_nextPoi == 0)
	{
		std::cout << "NO POIs exist in defined route. Add new POIs and try again"<< std::endl;
	}
	else{
		for(auto& poi:m_pRoute){
			closestPOI = dynamic_cast<CPOI*>(poi);
			if(closestPOI != NULL){
				distance=closestPOI->calculateDistance(wp);
				if(distance < closestDistance ){
					closestDistance=distance;
				}
			}
		}
	}
	poi=*closestPOI;
	return closestDistance;
}

void CRoute::print() {
	std::cout << "Our Route has " << m_nextWp << " Waypoints and " << m_nextPoi << " Points of Interest" << std::endl;
//	for(auto& position:m_pRoute){
////		position->print(2);
//		CPOI* pPOI = dynamic_cast<CPOI*>(position);
//		pPOI->print();
//	}
	std::list<CWaypoint*>::iterator it;
	for (it = m_pRoute.begin(); it != m_pRoute.end(); ++it)
	{
		if(NULL == dynamic_cast<CPOI*>(*it))
		{
			(*it)->print(2);
		}
		else
		{
			dynamic_cast<CPOI*>(*it)->print();
			std::cout<<std::endl;
		}

	}
}

CRoute::~CRoute() {
}
