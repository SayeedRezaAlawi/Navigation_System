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
//#include "CPoiDatabase.h"
//#include "CWpDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"
#include "iostream"
//#include "CCSV.h"
#include "CPersistentStorage.h"
//#include "CJsonPersistence.h"
#include "CDatabase.h"
#include "CStreetMap.h"
#include "CConnection.h"

class CNavigationSystem {
private:
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CDatabase<CPOI> m_PoiDatabase;
	CDatabase<CWaypoint> m_WpDatabase;
	CDatabase<CConnection> m_connectionDatabase;
	CStreetMap m_map;
//	CPoiDatabase m_PoiDatabase;
//	CWpDatabase m_WpDatabase;
//	CCSV m_CSV;
//	CJsonPersistence m_JsonStream;
	CPersistentStorage* m_PersistentStorage;
//	CPersistentStorage* m_pPersistentStorgage;
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
