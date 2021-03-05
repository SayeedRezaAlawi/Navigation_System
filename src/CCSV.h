/*
 * CCSV.h
 *
 *  Created on: Feb 28, 2021
 *      Author: reza
 */

#ifndef CCSV_H_
#define CCSV_H_
//#include "CWpDatabase.h"
//#include "CPoiDatabase.h"
#include "CPersistentStorage.h"
#include "CDatabase.h"

class CCSV: public CPersistentStorage {
private:
	std::string m_WpFileName;
	std::string m_PoiFileName;
	void readWpObj(std::string line, std::string& name,double& latitude,double& longitude);
	void readPoiObj(const std::string& line, CPOI::t_poi& type,std::string& name, std::string& descrioption,
			double& latitude, double& longitude);
	bool setPoiType(std::string poitype,CPOI::t_poi &poi_type);
public:
	CCSV();
	void setMediaName(std::string name);
	bool writeData (const CDatabase<CWaypoint>& waypointDb,const CDatabase<CPOI>& poiDb);
	bool readData (CDatabase<CWaypoint>& waypointDb, CDatabase<CPOI>& poiDb,CPersistentStorage::MergeMode_t mode);
	enum errorType{
		WRONGDELIMITER,
		TOOFEWFIELDS,
		READPOIFAIELD,
		READWPFAILD
	};
	typedef errorType errorType_t;
private:
	std::string errorToString(errorType_t error);
//	virtual ~CCSV();
};

#endif /* CCSV_H_ */
