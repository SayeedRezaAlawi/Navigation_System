class CScreen;
#ifndef CPOI_H_
#define CPOI_H_

#include <string>
#include "CWaypoint.h"

class CPOI : public CWaypoint
{
public:
	enum poi_type
	{
		RESTAURANT,
		TOURISTIC,
		GASSTATION,
		UNIVERSITY,
		KRANKENHAUS,
		BUSSTATION,
		SCHOOL,
		MONUMENT,
		DEFAULT,
		MaxPOI
	};
	typedef enum poi_type t_poi;

	CPOI();
	CPOI(t_poi type, std::string name, std::string description, double latitude, double longitude);
	void print(int format = 2);
	void print(int format, CScreen* screenType);
	void getAllDataByReference(std::string& name, double& latitude, double& longitude, t_poi& type, std::string& description);
	t_poi getType();
	std::string getDescription();
	std::string poiTypeToString();
	friend std::ostream& operator << (std::ostream& out, CPOI& wp);
	virtual ~CPOI();
private:
	t_poi m_type;
	std::string m_description;
};

#endif /* CPOI_H_ */
