/*
 * CConnection.cpp
 *
 *  Created on: Mar 5, 2021
 *      Author: reza
 */

#include "CConnection.h"
#include "iostream"

CDatabase<CWaypoint>* CConnection::m_pWpDB = 0;
CDatabase<CPOI>* CConnection::m_pPoiDB = 0;

CConnection::CConnection() {
	// TODO Auto-generated constructor stub

}

CConnection::CConnection(std::string from, std::string to,
		connection_t streetType) {
	std::map<std::string, CWaypoint> wp_map = m_pWpDB->getReferenceToMap();
	for(auto& wp:wp_map){
		if(wp.first == from){
			this->m_pFrom = &wp.second;
			break;
		}
	}
	for(auto& wp:wp_map){
		if(wp.first == to){
			this->m_pTo = &wp.second;
			break;
		}
	}
	m_streetType = streetType;
//	print();
}

double CConnection::getDistance() const {
	return 0;
}

CWaypoint* CConnection::getFrom() const {
	return this->m_pFrom;
}

CWaypoint* CConnection::getTo() const {
	return this->m_pTo;
}

void CConnection::connect(CDatabase<CWaypoint> *pWpDB,
		CDatabase<CPOI> *pPoiDB) {
	CConnection::m_pWpDB = pWpDB;
	CConnection::m_pPoiDB = pPoiDB;
}

void CConnection::print() const{
//	m_pFrom->print(1);
//	m_pTo->print(1);
//	std::cout << "m_pWpDB address: " << m_pWpDB << std::endl;
//	std::cout << "m_pPoiDB address: " << m_pPoiDB << std::endl;
//	std::cout << "m_pFrom->getName(): " << m_pFrom->getName() << std::endl;
//	std::cout << "m_pTo->getName(): " << m_pTo->getName() << std::endl;
//	std::cout << "from print this->m_pFrom: " << this->m_pFrom << std::endl;
//	std::cout << "from print this->m_pTo: " << this->m_pTo << std::endl;
	std::cout << std::endl;
	std::cout << " from " << getFrom()->getName()<< " to " << getTo()->getName()<< std::endl;
	std::cout << std::endl;
}

CConnection::~CConnection() {
	// TODO Auto-generated destructor stub
}

std::ostream& operator << (std::ostream& out, CConnection& con){
	out << std::endl;
		out << " from " << con.getFrom()->getName()<< " to " << con.getTo()->getName()<< std::endl;
		out << std::endl;
		return out;
}
