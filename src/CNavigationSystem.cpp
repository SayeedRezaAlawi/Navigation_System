/*
 * CNavigationSystem.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CNavigationSystem.h"
#include <iostream>

CNavigationSystem::CNavigationSystem() {
	// TODO Auto-generated constructor stub

}

void CNavigationSystem::run() {
	createDatabases();
	m_CSV.setMediaName("CSV4");
//	m_CSV.writeData(m_WpDatabase,m_PoiDatabase);
	m_CSV.readData(m_WpDatabase,m_PoiDatabase, CPersistentStorage::MERGE);
	m_PoiDatabase.print();
	m_WpDatabase.print();
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
		m_PoiDatabase.addPoi(CPOI::RESTAURANT,"Pizza Hut","Best pizza in darmstadt",13.45,23.65);
		m_PoiDatabase.addPoi(CPOI::RESTAURANT,"Contel","Budget Hotel in Darmstadt",33.61,43.07);
		m_PoiDatabase.addPoi(CPOI::KRANKENHAUS,"Krankenhaus","TK- Always for you",53.18,73.32);
		m_PoiDatabase.addPoi(CPOI::BUSSTATION,"BusStation","Pfnor-Strasse",53.24,49.91);
		m_PoiDatabase.addPoi(CPOI::SCHOOL,"H_DA","Hochschule Darmstadt - University of Applied Sciences",72.45,62.35);
		m_PoiDatabase.addPoi(CPOI::MONUMENT,"Kirche","The oldest Kirche in Darmstadt",65.20,12.67);

		/**
		 * WayPoint Database creation.
		 */
		CWaypoint wp1("Darmstadt",13.45,34.67);
		m_WpDatabase.addWaypoint(wp1);
		CWaypoint wp2("Munchen",78.98,45.67);
		m_WpDatabase.addWaypoint(wp2);
		CWaypoint wp3("Frankfurt",89.09,12.56);
		m_WpDatabase.addWaypoint(wp3);
		CWaypoint wp4("Stuttgart",12.04,69.47);
		m_WpDatabase.addWaypoint(wp4);
}

void CNavigationSystem::writeToFile() {
	m_CSV.writeData(m_WpDatabase,m_PoiDatabase);
}

void CNavigationSystem::readFromFile() {
	m_CSV.readData(m_WpDatabase,m_PoiDatabase,CPersistentStorage::REPLACE);
}

CNavigationSystem::~CNavigationSystem() {
	// TODO Auto-generated destructor stub
}

