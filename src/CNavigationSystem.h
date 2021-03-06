#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPOI.h"
#include "CWaypoint.h"
#include "iostream"
#include "CPersistentStorage.h"
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
	CPersistentStorage* m_PersistentStorage;
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
