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

CConnection::CConnection(std::string from, std::string to,
		connection_t streetType) {
	m_streetType = streetType;
	if (0 == m_pWpDB)
	throw std::string("CCONNECTION: WayppointDB not connected!");
	if (0 == m_pPoiDB)
	throw std::string("CCONNECTION: PoiDB not connected!");
	if (0 == (m_pFrom = m_pWpDB->get(from)))
	throw std::string("CCONNECTION: From " + from + " not found");
	if (0 == (m_pTo = m_pWpDB->get(to)))
	throw std::string("CCONNECTION: To " + to + " not found");
	m_streetType = streetType;
}

void CConnection::connect(CDatabase<CWaypoint>* pWpDb,
		CDatabase<CPOI>* pPoiDb) {
	m_pWpDB = pWpDb;
	m_pPoiDB = pPoiDb;
}

std::ostream& operator << (std::ostream& out, CConnection& con){
	out << std::endl;
		out << " from " << con.getFrom()->getName()<< " to " << con.getTo()->getName()<< std::endl;
		out << std::endl;
		return out;
}
