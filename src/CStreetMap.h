/*
 * CStreetMap.h
 *
 *  Created on: Mar 5, 2021
 *      Author: reza
 */

#ifndef CSTREETMAP_H_
#define CSTREETMAP_H_

#include "CDatabase.h"
#include "CConnection.h"
#include <vector>

class CStreetMap {
private:
	CDatabase<CConnection> m_connectionDatabase;
	CDatabase<CWaypoint> m_wpDatabase;
	CDatabase<CPOI> m_poiDatabase;
	typedef std::vector<CWaypoint*> route_t;
	route_t findNextRouteElement(route_t route, std::string to);
	void printRoute(std::string headline, route_t route);
public:
	CStreetMap();
	void add(CWaypoint const& data);
	void add(CPOI const& data);
	void add(std::string from, std::string to, CConnection::connection_t c);
	void findRoute(std::string from, std::string to);
	void print();

	virtual ~CStreetMap();
	CDatabase<CPOI>& getPoiDatabase() ;
	CDatabase<CWaypoint>& getWpDatabase() ;
	CDatabase<CConnection>& getConnectionDatabase() ;
};

#endif /* CSTREETMAP_H_ */
