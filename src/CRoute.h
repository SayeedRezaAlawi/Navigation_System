//class CScreen;
#ifndef CROUTE_H_
#define CROUTE_H_

#include <string>
#include <list>
#include "CWaypoint.h"
#include "CPOI.h"
#include "CDatabase.h"

#define BYPOINTER 1
#define BYVALUE 2
//By setting COMPARE to either BYVALUE or to BYPOINTER the corresponding
//comparison code will be used
#define COMPARE BYPOINTER

#define DEFAULT_VALUE_FOR_NO_POI 0xFFFF


class CRoute {
public:
	typedef std::list<CWaypoint*> CWayPointList;
	CRoute();
	CRoute(CRoute& origin);
	void connectToPoiDatabase(CDatabase<CPOI>* pPoiDB);
	void connectToWpDatabase(CDatabase<CWaypoint>* pWpDB);
	void addWaypoint(std::string WpName);
	void addPoi(std::string namePoi);
	void addPoi(std::string namePoi, std::string afterWp);
	double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);
	void print();
//	void print(CScreen* screenType);
	CRoute& operator = (const CRoute& route);
	CRoute& operator += (const std::string name);
	CRoute operator + (const CRoute& route);
	bool operator == (CRoute const& rop);
	virtual ~CRoute();
private:
	unsigned int m_nextWp;
	unsigned int m_nextPoi;
	CDatabase<CWaypoint>* m_pWpDatabase;
	CDatabase<CPOI>* m_pPoiDatabase;
	CWayPointList m_pRoute;
};

#endif /* CROUTE_H_ */
