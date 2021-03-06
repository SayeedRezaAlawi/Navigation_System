/*
 * CConnection01.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: reza
 */

#include "CConnection01.h"

CDatabase<CWaypoint>* CConnection01::m_pWpDB = 0;
CDatabase<CPOI>* CConnection01::m_pPoiDB = 0;

CConnection01::CConnection01() {
}

CConnection01::CConnection01(CWaypoint &wpfrom, CWaypoint &wpto,
		connection_t streetType) {
	m_pFrom = &wpfrom;
	m_pTo = &wpto;
	m_streetType = streetType;
}

double CConnection01::getDistance() const {
	return 0;
}

CWaypoint* CConnection01::getFrom() const {
	return this->m_pFrom;
}

CWaypoint* CConnection01::getTo() const {
	return this->m_pTo;
}

void CConnection01::print() const {
	std::cout << "from " << this->m_pFrom->getName() << " to " << this->m_pTo->getName() << std::endl;
}

std::ostream& operator << (std::ostream& out, CConnection01& con){
	out << "from " << con.getFrom() << " to " << con.getTo() << std::endl;
}

void CConnection01::connect(CDatabase<CWaypoint> *pWpDB,
		CDatabase<CPOI> *pPoiDB) {
	CConnection01::m_pWpDB = pWpDB;
	CConnection01::m_pPoiDB = pPoiDB;
}

CConnection01::CConnection01(std::string from, std::string to,
		connection_t streetType) {
	CWaypoint wpFrom;
	CWaypoint wpTo;
	std::map<std::string, CWaypoint> wp_map = m_pWpDB->getReferenceToMap();
		for(auto& wp:wp_map){
			if(wp.first == from){
//				this->m_pFrom = &wp.second;
				wpFrom = wp.second;
				break;
			}
		}
		for(auto& wp:wp_map){
			if(wp.first == to){
//				this->m_pTo = &wp.second;
				wpTo=wp.second;
				break;
			}
		}
		m_pFrom = &wpFrom;
		m_pTo = &wpTo;
		m_streetType = streetType;
//		std::cout << *m_pFrom;
//		std::cout << *m_pTo;
}

CConnection01& CConnection01::operator =(const CConnection01 &connection) {
	this->m_pFrom=connection.m_pFrom;
	this->m_pTo = connection.m_pTo;
	this->m_streetType = connection.m_streetType;
	return *this;
}

CConnection01::CConnection01(const CConnection01 &orig) {
	this->m_pFrom=orig.m_pFrom;
	this->m_pTo = orig.m_pTo;
	this->m_streetType = orig.m_streetType;
}

CConnection01::~CConnection01() {
}
