/*
 * CConnection.h
 *
 *  Created on: Mar 5, 2021
 *      Author: reza
 */

#ifndef CCONNECTION_H_
#define CCONNECTION_H_

#include "CWaypoint.h"
#include "CPOI.h"
#include "CDatabase.h"
#include <iostream>

#include <string>

class CConnection {
public:
	enum connection
	{
		UNKNOWN,
		HIGHWAY,
		CITY,
		MOTORWAY
	};
	typedef enum connection connection_t;
	CConnection();
	CConnection(std::string from, std::string to, connection_t streetType);

	double getDistance() const;
	CWaypoint* getFrom() const;
	CWaypoint* getTo() const;
	void print() const;
	friend std::ostream& operator << (std::ostream& out, CConnection& con);
	static void connect(CDatabase<CWaypoint>* pWpDB, CDatabase<CPOI>* pPoiDB);
	virtual ~CConnection();
private:
	CWaypoint* m_pFrom;
	CWaypoint* m_pTo;
	connection_t m_streetType;
	static CDatabase<CWaypoint>* m_pWpDB;
	static CDatabase<CPOI>* m_pPoiDB;
};

#endif /* CCONNECTION_H_ */
