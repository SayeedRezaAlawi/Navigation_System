/*
 * CPersistentStorage.h
 *
 *  Created on: Feb 28, 2021
 *      Author: reza
 */

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_
#include <string>
#include "CWpDatabase.h"
#include "CPoiDatabase.h"

class CPersistentStorage {
public:
	enum MergeMode { MERGE, REPLACE };
	typedef MergeMode MergeMode_t;
	virtual void setMediaName(std::string name) = 0;
	virtual bool writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb) = 0;
	virtual bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode_t mode) = 0;
//	virtual ~CPersistentStorage() = 0;
};

#endif /* CPERSISTENTSTORAGE_H_ */
