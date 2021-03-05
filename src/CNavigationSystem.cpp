/*
 * CNavigationSystem.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CNavigationSystem.h"
#include <iostream>
#include "CCSV.h"
#include "CJsonPersistence.h"


CNavigationSystem::CNavigationSystem() {
	// TODO Auto-generated constructor stub

}

void CNavigationSystem::run() {
	unsigned int choice = 0;
	while(true){
		std::cout << "Please select your persistent storage type (1- CSV stream , 2- Json stream)"
				<< std::endl;
		std::cin >> choice;
		if(choice == 1){
			m_PersistentStorage = new CCSV;
			break;
		}
		else if(choice == 2){
			m_PersistentStorage = new CJsonPersistence();
			break;
		}
		else{
			std::cout << "Wrong storage is selected, please try again" << std::endl;
		}
	}
	createDatabases();

	if(choice == 1){
		m_PersistentStorage->setMediaName("CSV4");
		m_PersistentStorage->writeData(m_WpDatabase,m_PoiDatabase);
		m_PersistentStorage->readData(m_WpDatabase,m_PoiDatabase, CPersistentStorage::MERGE);
//		m_PoiDatabase.print();
//		m_WpDatabase.print();
	}

	else if(choice == 2){
		m_PersistentStorage->setMediaName("Json-both.txt");
		m_PersistentStorage->readData(m_WpDatabase,m_PoiDatabase, CPersistentStorage::REPLACE);
//		m_PoiDatabase.print();
//		m_WpDatabase.print();
		std::cout << std::endl << std::endl;
		m_PersistentStorage->setMediaName("JsonWrite-both.txt");
		m_PersistentStorage->writeData(m_WpDatabase,m_PoiDatabase);

		m_PersistentStorage->setMediaName("JsonWrite-both.txt");
		m_PersistentStorage->readData(m_WpDatabase,m_PoiDatabase, CPersistentStorage::REPLACE);
		m_PoiDatabase.print();
		m_WpDatabase.print();
	}
//	enterRoute();
	/**
	 * print the route defined
	 */
//	printRoute();

//	printDistanceCurPosNextPoi();
}

void CNavigationSystem::enterRoute() {
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	m_route.connectToWpDatabase(&m_WpDatabase);
	/**
	 * add way points to the route
	 */
	m_route.addWaypoint("Darmstadt");
	m_route.addWaypoint("Frankfurt");
//	m_route += "Munchen";
//	m_route.addWaypoint("Karlsruhe");//invalid Waypoint

	/**
	 * add POIs to the route.
	 */
	m_route.addPoi("Krankenhaus");	//valid POI
	m_route.addPoi("BusStation");	//valid POI
//	m_route.addPoi("Deutsche Bahnhof"); //invalid POI
}

void CNavigationSystem::printRoute() {
	m_route.print();
}

void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint userWaypoint = m_GPSSensor.getCurrentPosition();
	CPOI closestPOI;
	double closestPOIDistance = m_route.getDistanceNextPoi(userWaypoint,closestPOI);

	std::cout << "closest Point of interest to entered waypoint" << std::endl;
	closestPOI.print();
	std::cout << "closest distance from entered way point to closest Point of interest = " << closestPOIDistance << std::endl;
}

void CNavigationSystem::createDatabases() {
	/**
		 * Database creation
		 */
		m_PoiDatabase.add("Pizza Hut", CPOI(CPOI::RESTAURANT,"Pizza Hut","Best pizza in darmstadt",13.45,23.65));
		m_PoiDatabase.add("Contel", CPOI(CPOI::RESTAURANT,"Contel","Budget Hotel in Darmstadt",33.61,43.07));
		m_PoiDatabase.add("Krankenhaus", CPOI(CPOI::KRANKENHAUS,"Krankenhaus","TK- Always for you",53.18,73.32));
		m_PoiDatabase.add("BusStation", CPOI(CPOI::BUSSTATION,"BusStation","Pfnor-Strasse",53.24,49.91));
		m_PoiDatabase.add("H_DA", CPOI(CPOI::SCHOOL,"H_DA","Hochschule Darmstadt - University of Applied Sciences",72.45,62.35));
		m_PoiDatabase.add("Kirche", CPOI(CPOI::MONUMENT,"Kirche","The oldest Kirche in Darmstadt",65.20,12.67));

		/**
		 * WayPoint Database creation.
		 */
		CWaypoint wp1("Darmstadt",13.45,34.67);
		m_WpDatabase.add("Darmstadt", wp1);
		CWaypoint wp2("Munchen",78.98,45.67);
		m_WpDatabase.add("Munchen", wp2);
		CWaypoint wp3("Frankfurt",89.09,12.56);
		m_WpDatabase.add("Frankfurt", wp3);
		CWaypoint wp4("Stuttgart",12.04,69.47);
		m_WpDatabase.add("Stuttgart", wp4);
}

void CNavigationSystem::writeToFile() {
	m_PersistentStorage->writeData(m_WpDatabase,m_PoiDatabase);
}

void CNavigationSystem::readFromFile() {
	m_PersistentStorage->readData(m_WpDatabase,m_PoiDatabase,CPersistentStorage::REPLACE);
}

CNavigationSystem::~CNavigationSystem() {
	// TODO Auto-generated destructor stub
}

