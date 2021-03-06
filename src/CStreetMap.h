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
	void add(std::string const& from, std::string const& to, CConnection::connection_t const& c);
	void findRoute(std::string from, std::string to);
	void print();
	virtual ~CStreetMap();
};

#endif /* CSTREETMAP_H_ */
