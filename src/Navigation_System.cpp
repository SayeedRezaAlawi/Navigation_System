//============================================================================
// Name        : Navigation_System.cpp
// Author      : Sayeed Reza Alawi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "CWaypoint.h"
#include "CNavigationSystem.h"
#include "CJsonScanner.h"
#include <string>
#include "CJsonStatmentHandler.h"
#include "CConnection01.h"
using namespace std;



int main() {

//	CNavigationSystem navObj;
//	navObj.run();

	CDatabase<CConnection> m_connectionDatabase;
	CDatabase<CConnection01> m_connection01Database;
	CDatabase<CWaypoint> m_wpDatabase;
	CDatabase<CPOI> m_poiDatabase;

	std::cout << "step 01: " << std::endl;
		//Build up the WP Pool
	m_wpDatabase.add("Amsterdam", CWaypoint("Amsterdam",52.3731,4.8922));
	m_wpDatabase.add("Darmstadt", CWaypoint("Darmstadt", 49.850,8.6527));
	m_wpDatabase.add("Berlin", CWaypoint("Berlin", 52.5166,13.4));
	m_wpDatabase.add("Wroclav", CWaypoint("Wroclav", 52.21,21.03));
	m_wpDatabase.add("Moscou", CWaypoint("Moscou", 55.75, 37.4));
	m_wpDatabase.add("Prague", CWaypoint("Prague", 50.1,14.4));\
	m_wpDatabase.add("Amsterdam", CWaypoint("Amsterdam",53.3731,10.8922));

	std::map<std::string, CWaypoint> wpDb= m_wpDatabase.getReferenceToMap();
	CWaypoint wp;
	for(auto con:wpDb){
//			con.second.print();
//			std::cout << con.first << std::endl;
			wp = con.second;
			std::cout << wp << std::endl;
//			std::cout << (con.second).getFrom() <<  "\t" << (con.second).getTo() << std::endl;
//			conn.print();
			}
//	for(auto con:m_wpDatabase.getReferenceToMap()){
//				con.second.print(2);
//			}

	CConnection01::connect(&m_wpDatabase,&m_poiDatabase);

//	CWaypoint wp1("Darmstadt", 49.850,8.6527);
//	CWaypoint wp2("Amsterdam",52.3731,4.8922);
//	CWaypoint wp3("Berlin", 52.5166,13.4);
//	CWaypoint wp4("Wroclav", 52.21,21.03);
//	CWaypoint wp5("Wroclav", 52.21,21.03);
//	CWaypoint wp6("Moscou", 55.75, 37.4);
//	CWaypoint wp7("Prague", 50.1,14.4);
//	CWaypoint wp8("Moscou", 55.75, 37.4);
//
//	CConnection01 connection1(wp1, wp2, CConnection01::HIGHWAY);
//	CConnection01 connection2(wp3, wp4, CConnection01::HIGHWAY);
//	CConnection01 connection3(wp5, wp6, CConnection01::HIGHWAY);
//	CConnection01 connection4(wp7, wp8, CConnection01::HIGHWAY);
////	connection.print();
//	m_connection01Database.add("Darmstadt", connection1);
//	m_connection01Database.add("Berlin", connection2);
//	m_connection01Database.add("Wroclav", connection3);
//	m_connection01Database.add("Prague", connection4);
//	for(auto con:m_connection01Database.getReferenceToMap()){
//			con.second.print();
//		}
//		std::cout << "step 02: " << std::endl;
//		//Let's add some Connections
//		m_connectionDatabase.add("Darmstadt", CConnection("Darmstadt", "Amsterdam", CConnection::HIGHWAY));
//		m_connectionDatabase.add("Berlin", CConnection("Berlin", "Wroclav", CConnection::HIGHWAY));
//		m_connectionDatabase.add("Wroclav", CConnection("Wroclav", "Moscou", CConnection::HIGHWAY));
//		m_connectionDatabase.add("Prague", CConnection("Prague", "Moscou", CConnection::HIGHWAY));

	m_connection01Database.add("Darmstadt", CConnection01("Darmstadt", "Amsterdam", CConnection01::HIGHWAY));
	m_connection01Database.add("Berlin", CConnection01("Berlin", "Wroclav", CConnection01::HIGHWAY));
	m_connection01Database.add("Wroclav", CConnection01("Wroclav", "Moscou", CConnection01::HIGHWAY));
	m_connection01Database.add("Prague", CConnection01("Prague", "Moscou", CConnection01::HIGHWAY));

	std::map<std::string, CConnection01> db = m_connection01Database.getReferenceToMap();
	std::cout << "pointer to Darmstadt: " << m_connection01Database.get("Darmstadt") << std::endl;
//	m_connection01Database.get("Darmstadt")->print();
	std::cout << "pointer to Berlin: " << m_connection01Database.get("Berlin") << std::endl;
	std::cout << "pointer to Wroclav: " << m_connection01Database.get("Wroclav") << std::endl;
	std::cout << "pointer to Prague: " << m_connection01Database.get("Prague") << std::endl;
	CConnection01 conn;
		for(auto con:db){
//			con.second.print();
//			std::cout << con.first << std::endl;
			std::cout << con.second << std::endl;
//			std::cout << (con.second).getFrom() <<  "\t" << (con.second).getTo() << std::endl;
//			conn.print();
		}

//	CWpDatabase waypointDb;
//	CPoiDatabase poiDb;
//	CCSV csv;
//	csv.setMediaName("CSV4");
//	csv.readData(waypointDb, poiDb,CPersistentStorage::REPLACE);
//	waypointDb.print();
//	poiDb.print();
//	CJsonStatmentHandler handler;
//	string fileName = "Json-both.txt";
//	string line;
//	ifstream file;
//	file.open(fileName);
//	APT::CJsonScanner scanner(file);
//	bool validToken= true;
//	while(validToken == true){
//	APT::CJsonToken* token;
//	token = scanner.nextToken();
//		if(token == NULL){
//			validToken = false;
//		}
//		else{
////			cout << "current Token is: " << token->str() << endl;
////			handler.Json_processEvent(token);
//			CJsonStatmentHandler::Json_processEvent(token);
//		}
//	}
//	std::list<CWaypoint> wplist = CJsonStatmentHandler::getWpList();
//	for(auto& wp:wplist){
//		std::cout << wp;
//	}
//	std::list<CPOI> poilist = CJsonStatmentHandler::getPoiList();
//	for(auto& poi:poilist){
//		std::cout << poi;
//	}
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
