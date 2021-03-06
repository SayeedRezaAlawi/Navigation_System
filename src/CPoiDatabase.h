#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
#include <map>
#include <string>
#include "CPOI.h"

class CPoiDatabase {
public:
	typedef std::map<std::string, CPOI> POI_map;
	CPoiDatabase();
	void addPoi(CPOI::t_poi type,std::string name, std::string descrioption, double latitude, double longitude);
	CPOI* getPointerToPoi(std::string name );
	POI_map getPois() const;
	void print();
	void clearDb();
	virtual ~CPoiDatabase();
private:
	POI_map m_POI;
};

#endif /* CPOIDATABASE_H_ */
