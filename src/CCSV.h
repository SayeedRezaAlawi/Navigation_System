/*
 * CCSV.h
 *
 *  Created on: Feb 28, 2021
 *      Author: reza
 */

#ifndef CCSV_H_
#define CCSV_H_
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CPersistentStorage.h"

class CCSV: public CPersistentStorage {
public:
	CCSV();
	void setMediaName(std::string name);
	bool writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb);
	bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,CPersistentStorage::MergeMode_t mode);
//	virtual ~CCSV();
};

#endif /* CCSV_H_ */
