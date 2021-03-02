//============================================================================
// Name        : Navigation_System.cpp
// Author      : Sayeed Reza Alawi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CWaypoint.h"
#include "CNavigationSystem.h"
using namespace std;

int main() {

//	CNavigationSystem navObj;
//	navObj.run();
	CWpDatabase waypointDb;
	CPoiDatabase poiDb;
	CCSV csv;
	csv.setMediaName("CSV4");
	csv.readData(waypointDb, poiDb,CPersistentStorage::REPLACE);
	waypointDb.print();
	poiDb.print();
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	CWaypoint wp1 = CWaypoint{"WP1",20,123};
//	std::cout << wp1;
//	CWaypoint Amsterdam = CWaypoint{"Amsterdam",52.3676,4.9041};
//	Amsterdam.print(1);
//	Amsterdam.print(2);
//	CWaypoint Darmstadt = CWaypoint{"Darmstadt",49.8728,8.6512};
//	CWaypoint Berlin = CWaypoint{"Berlin",52.5166 ,13.4};
//	CWaypoint Tokyo= CWaypoint{"Tokyo",35.6762,139.6503};

//	Amsterdam.calculateDistance(Berlin);
//	Berlin.calculateDistance(Amsterdam);
//	std::cout << "city name is: " << Tokyo.getName() << " with latitude: " <<
//			Tokyo.getLatitude() << " and longitude: " << Tokyo.getLongitude() << std::endl;
//	string name;
//	double latitude, longitude;
//	Berlin.getAllDataByReference(name,latitude,longitude);
//	cout << "address of local name: " << &name <<", address of local latitude: " << &latitude << " and address of local longitude: " << &longitude << endl;

//	CWaypoint newWaypoint = CWaypoint();
//	#if DEGREE == 1
//	newWaypoint.print(1);
//	#endif
//
//	#if MMSS == 2
//	newWaypoint.print(2);
//	return 0;
//	#endif
}
