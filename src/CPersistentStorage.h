/*
 * CPersistentStorage.h
 *
 *  Created on: Feb 28, 2021
 *      Author: reza
 */

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_
#include <string>
//#include "CWpDatabase.h"
//#include "CPoiDatabase.h"
#include "CWaypoint.h"
#include "CPOI.h"
#include "CDatabase.h"

class CPersistentStorage {
public:
	enum MergeMode { MERGE, REPLACE };
	typedef MergeMode MergeMode_t;
	virtual void setMediaName(std::string name) = 0;
	virtual bool writeData (const CDatabase<CWaypoint>& waypointDb,const CDatabase<CPOI>& poiDb) = 0;
	virtual bool readData (CDatabase<CWaypoint>& waypointDb, CDatabase<CPOI>& poiDb,MergeMode_t mode) = 0;
//	virtual ~CPersistentStorage() = 0;
};

#endif /* CPERSISTENTSTORAGE_H_ */
