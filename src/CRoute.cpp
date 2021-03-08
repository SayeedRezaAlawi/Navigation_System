/*
 * CRoute.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CRoute.h"
#include <iostream>
#include "CScreen.h"

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

void CRoute::connectToPoiDatabase(CDatabase<CPOI> *pPoiDB) {
	m_pPoiDatabase = pPoiDB;
}

void CRoute::connectToWpDatabase(CDatabase<CWaypoint>* pWpDB){
	m_pWpDatabase = pWpDB;
}

void CRoute::addWaypoint(std::string WpName) {
	CWaypoint* ptrToWpDB;
	if(m_pWpDatabase != NULL){
		ptrToWpDB = m_pWpDatabase->get(WpName);
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
		ptrToPoiDB  = m_pPoiDatabase->get(namePoi);
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
	std::cout << "Our Route has " << m_nextWp << " Waypoints and "
			<< m_nextPoi << " Points of Interest" << std::endl;
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

void CRoute::addPoi(std::string namePoi, std::string afterWp) {
	bool MatchFound = false;
	CPOI* ptrTpPoi;
	if(m_pPoiDatabase != NULL)
	{
		ptrTpPoi = m_pPoiDatabase->get(namePoi);
		if(ptrTpPoi != NULL){
			CWayPointList::reverse_iterator re_it;

			for(re_it = m_pRoute.rbegin(); re_it != m_pRoute.rend() && !MatchFound; ++re_it){
				if(((*re_it)->getName() == afterWp) && (m_pPoiDatabase->get((*re_it)->getName()) == NULL)){
					m_pRoute.insert(re_it.base(),ptrTpPoi);
					m_nextPoi++;
					MatchFound=true;
					break;
				}
			}
			if(!MatchFound){
				std::cout<<" ERROR:: The afterWp "<<afterWp<<" not found in DB"<<std::endl;
				m_pRoute.push_back(ptrTpPoi);
				m_nextPoi++;
			}
	}
	else {
		std::cout<<"ERROR: "<<namePoi<< "  POI not found in database, POI not in the POOL."<<std::endl;
	}
	}
	else {
		std::cout<<" POI Database not connected"<<std::endl;
	}
}

CRoute& CRoute::operator +=(const std::string name) {
	addWaypoint(name);
	addPoi(name, name);
	return *this;
}

CRoute& CRoute::operator =(const CRoute &route) {
	this->m_nextPoi = route.m_nextPoi;
	this->m_nextWp = route.m_nextWp;
	this->m_pPoiDatabase = route.m_pPoiDatabase;
	this->m_pRoute = route.m_pRoute;
	this->m_pWpDatabase = route.m_pWpDatabase;
	return *this;
}

CRoute CRoute::operator +(const CRoute &route) {
	CRoute newRoute;
	if(route.m_pPoiDatabase != NULL && route.m_pWpDatabase != NULL){
		if(this->m_pPoiDatabase == route.m_pPoiDatabase && this->m_pWpDatabase == route.m_pWpDatabase){
			newRoute.m_nextWp = this->m_nextWp + route.m_nextWp;
			newRoute.m_nextPoi = this->m_nextPoi + route.m_nextPoi;
			newRoute.m_pRoute.insert(newRoute.m_pRoute.end(),route.m_pRoute.begin(),route.m_pRoute.end());
			newRoute.m_pRoute.insert(newRoute.m_pRoute.end(), this->m_pRoute.begin(), this->m_pRoute.end());
		}
		else{
			std::cout << "Routed are not connected to the same Databases." << std::endl;
			newRoute =CRoute();
	}
	}
	else{
		std::cout << "Databases are not connected" << std::endl;
	}
	return newRoute;
}

CRoute::~CRoute() {
}

//void CRoute::print(CScreen *screenType) {
//}

bool CRoute::operator ==(const CRoute &rop) {

	bool elementFound = false;

	if (m_pRoute.size() != rop.m_pRoute.size()) return false;

	for(CWayPointList::const_iterator source = m_pRoute.begin(); source != m_pRoute.end(); ++source){
		for(CWayPointList::const_iterator dest = rop.m_pRoute.begin(); dest != rop.m_pRoute.end(); ++dest){
#if COMPARE == BYPOINTER
			if ((*dest) == (*source))
				elementFound = true;
#elif COMPARE == BYVALUE
//			if ((*(*dest)) == (*(*source)))
				elementFound = true;
#else
#error Wrong configuration of the compare directive
#endif
		}
		if (!elementFound) return false;
	}
	return true;
}
