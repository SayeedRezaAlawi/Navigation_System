/*
 * CNavigationSystem.h
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"
#include "iostream"
#include "CCSV.h"

class CNavigationSystem {
private:
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPoiDatabase m_PoiDatabase;
	CWpDatabase m_WpDatabase;
	CCSV m_CSV;
	void enterRoute();
	void printRoute();
	void printDistanceCurPosNextPoi();
public:
	CNavigationSystem();
	void run();
	void createDatabases();
	void writeToFile();
	void readFromFile();
	virtual ~CNavigationSystem();
};

#endif /* CNAVIGATIONSYSTEM_H_ */
