/*
 * CConnection01.h
 *
 *  Created on: Mar 6, 2021
 *      Author: reza
 */

#ifndef CCONNECTION01_H_
#define CCONNECTION01_H_

#include "CWaypoint.h"
#include "CPOI.h"
#include "CDatabase.h"
#include <iostream>
#include <memory>

#include <string>

class CConnection01 {
public:
	enum connection
	{
		UNKNOWN,
		HIGHWAY,
		CITY,
		MOTORWAY
	};
	typedef enum connection connection_t;
	CConnection01();
	CConnection01(CWaypoint& wpfrom, CWaypoint& wpto, connection_t streetType);
	CConnection01(std::string from, std::string to, connection_t streetType);
	CConnection01(const CConnection01& orig);

	double getDistance() const;
	CWaypoint* getFrom() const;
	CWaypoint* getTo() const;
	void print() const;
	CConnection01& operator = (const CConnection01& connection);
	friend std::ostream& operator << (std::ostream& out, CConnection01& con);
	static void connect(CDatabase<CWaypoint>* pWpDB, CDatabase<CPOI>* pPoiDB);
	virtual ~CConnection01();
private:
	CWaypoint* m_pFrom;
	CWaypoint* m_pTo;
//	std::unique_ptr<CWaypoint*> m_upFrom;
//	std::unique_ptr<CWaypoint*> m_upTo;
	connection_t m_streetType;
	static CDatabase<CWaypoint>* m_pWpDB;
	static CDatabase<CPOI>* m_pPoiDB;
};

#endif /* CCONNECTION01_H_ */
