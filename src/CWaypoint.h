/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWAYPOINT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CWAYPOINT_H
#define CWAYPOINT_H
#include <string>

#define EARTH_RADIUS 6378.17
#define LOGLEVEL 0
#define SHOW_DEBUG_DATA 1
#define DEGREE 0
#define MMSS 0
#define PI 3.14159265358979323846
#define DEG2RAD 0.0174532 // (PI/180)

#if LOGLEVEL == 1
#define SHOWADDRESS 1
#endif

class CWaypoint {
protected:
    double m_latitude;
    double m_longitude;
    std::string m_name;
public:

    CWaypoint(std::string name="default", double latitude=0, double longitude=0);
    void set(std::string name, double latitude, double longitude);
	double getLatitude() const;
	double getLongitude() const;
	const std::string& getName() const;
	void getAllDataByReference(std::string& name, double& latitude, double& longitude);
	double calculateDistance(const CWaypoint& wp);
	virtual void print(int format);
	virtual ~CWaypoint();
protected:
	void transformLongitude2degmmss(int& deg, int& mm, double& ss);
	void transformLatitude2degmmss(int& deg, int& mm, double& ss);
	friend std::ostream& operator << (std::ostream& out, CWaypoint& wp);
};

//std::ostream& operator << (std::ostream& out, CWaypoint& wp);
/********************
**  CLASS END
*********************/
#endif /* CWAYPOINT_H */
