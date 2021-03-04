/*
 * CJsonPersistence.h
 *
 *  Created on: Mar 4, 2021
 *      Author: reza
 */

#ifndef CJSONPERSISTENCE_H_
#define CJSONPERSISTENCE_H_

#include "CPersistentStorage.h"
#include <string>

class CJsonPersistence : public CPersistentStorage{
private:
	std::string m_fileName;
public:
	void setMediaName(std::string name);
	bool writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb);
	bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,CPersistentStorage::MergeMode_t mode);
	enum errorType{
		WRONGDELIMITER,
		TOOFEWFIELDS,
		READPOIFAIELD,
		READWPFAILD
	};
	typedef errorType errorType_t;
};

#endif /* CJSONPERSISTENCE_H_ */
