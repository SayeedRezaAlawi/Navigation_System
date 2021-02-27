/*
 * CWpDatabase.h
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_
#include <string>
#include <map>
#include "CWaypoint.h"

class CWpDatabase {
public:
	typedef std::map<std::string, CWaypoint> Waypoin_map;
	CWpDatabase();
	void addWaypoint(CWaypoint const&  Wp);
	CWaypoint* getPointerToWp(std::string WpName );
	void print();
	virtual ~CWpDatabase();
private:
	Waypoin_map m_Waypoint;
};

#endif /* CWPDATABASE_H_ */
