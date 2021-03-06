/*
 * CStreetMap.cpp
 *
 *  Created on: Mar 5, 2021
 *      Author: reza
 */

#include "CStreetMap.h"
#include "iostream"

CStreetMap::CStreetMap() {
//	std::cout << "m_wpDatabase address: " << &m_wpDatabase << std::endl;
//	std::cout << "m_poiDatabase address: " << &m_poiDatabase << std::endl;
//	CConnection::connect(&m_wpDatabase, &m_poiDatabase);
}

CStreetMap::route_t CStreetMap::findNextRouteElement(route_t route, std::string to) {
	std::cout << "step 08: " << std::endl;
	std::map<std::string, CConnection> db = m_connectionDatabase.getReferenceToMap();
//	std::map<std::string, CWaypoint> wp_map = m_wpDatabase.getReferenceToMap();
//	for(auto& wp:wp_map){
//		wp.second.print(1);
//	}
//	for(auto& c:db){
//		std::cout << "step 09: " << std::endl;
//		CConnection con = c.second;
//		con.print();
//		std::cout << "step 10: " << std::endl;
//	}
	std::string lastElement = route.back()->getName();
	std::cout << "lastElement: " << lastElement << std::endl;
	bool deadend = true;

	for(std::map<std::string, CConnection>::iterator it = db.begin(); it != db.end(); ++it){
		CWaypoint* lpfrom = it->second.getFrom();
		std::cout << "lpfrom: " << lpfrom->getName() << std::endl;
		CWaypoint* lpto = it->second.getTo();
		std::cout << "lpto: " << it->second.getTo() << std::endl;
		if(lpfrom == 0 || lpto == 0){
			return route;
		}
		if(lpfrom->getName() == lastElement){
			deadend = false;
			if(lpto->getName() == to){
				route.push_back(lpto);
			}
			else {
				std::vector<CWaypoint*> newroute = route;
				newroute.push_back(lpto);
				newroute = findNextRouteElement(newroute, to);
				if(newroute.back() != 0){
					return newroute;
				}
			}
			if(route.back()->getName() == to){
				return route;
			}
		}
		if(deadend){
			route.push_back(0);
		}
		return route;
	}
}

void CStreetMap::printRoute(std::string headline, route_t route) {
	std::cout << headline;
	for(auto& point:route){
		std::cout << point->getName();
				if(point != *route.end()){
					std::cout << ",";
				}
	}
	std::cout << std::endl;
}

void CStreetMap::add(const CWaypoint &data) {
	m_wpDatabase.add(data.getName(), data);
}

void CStreetMap::add(const CPOI &data) {
	m_poiDatabase.add(data.getName(), data);
}

void CStreetMap::add(std::string from, std::string to,
		CConnection::connection_t c) {
	m_connectionDatabase.add(from,CConnection(from,to,c));
}

void CStreetMap::findRoute(std::string from, std::string to) {
	route_t route;
	std::map<std::string, CWaypoint> wp_map = m_wpDatabase.getReferenceToMap();
	std::cout << "wp_map size: " << wp_map.size() << std::endl;

	std::cout << "from findRoute m_connectionDatabase.getNoAdd(): " << m_connectionDatabase.getNoAdd() << std::endl;
//	m_connectionDatabase.print();
	CWaypoint* wp;
	std::map<std::string, CConnection> db = m_connectionDatabase.getReferenceToMap();
	std::cout << "db.size(): " << db.size() << std::endl;
	std::map<std::string, CConnection>::iterator it;
//	for(it=db.begin();it != db.end();++it){
////		std::cout << it->second.getFrom()->getName() << std::endl;
////		std::cout << it->first << std::endl;
////		std::cout << " it->second.getFrom(): "  << it->second.getFrom() << std::endl;
//		wp = (it->second.getFrom());
//		wp->print(1);
//	}
	for(auto& con:m_connectionDatabase.getReferenceToMap()){
		std::cout << " con.second.getFrom(): "  << con.second.getFrom()->getName() << std::endl;
//		wp = con.second.getFrom();
//		wp->print(1);
	}
	CWaypoint* start = m_wpDatabase.get(from);
	std::cout << "start: " << start->getName() << std::endl;
	if(start != 0){
		std::cout << "step 05: " << std::endl;
		route.push_back(start);
		route = findNextRouteElement(route, to);
		if(route.back() != 0){
			printRoute("Route found:" , route);
		}
		else{
			std::cout << "no valid connection found" << std::endl;
		}
	}
}

void CStreetMap::print() {
	for(auto& con:m_connectionDatabase.getReferenceToMap()){
			con.second.print();
		}
}

CDatabase<CPOI>& CStreetMap::getPoiDatabase()  {
	return m_poiDatabase;
}

CDatabase<CConnection>& CStreetMap::getConnectionDatabase()  {
	return m_connectionDatabase;
}

CDatabase<CWaypoint>& CStreetMap::getWpDatabase()  {
	return m_wpDatabase;
}

CStreetMap::~CStreetMap() {
	// TODO Auto-generated destructor stub
}

