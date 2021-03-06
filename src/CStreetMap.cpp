/*
 * CStreetMap.cpp
 *
 *  Created on: Mar 5, 2021
 *      Author: reza
 */

#include "CStreetMap.h"
#include "iostream"

CStreetMap::CStreetMap() {
	CConnection::connect(&m_wpDatabase,&m_poiDatabase);
}

CStreetMap::route_t CStreetMap::findNextRouteElement(route_t route, std::string to) {

	std::map<std::string, CConnection> db = m_connectionDatabase.getReferenceToMap();
	std::string lastElement = route.back()->getName();
	bool deadend = true;

	for(std::map<std::string, CConnection>::iterator it = db.begin(); it != db.end(); ++it){
		CWaypoint* lpfrom = it->second.getFrom();
		CWaypoint* lpto = it->second.getTo();
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
	}
	if(deadend){
		route.push_back(0);
	}
	return route;
}

void CStreetMap::printRoute(std::string headline, route_t route) {
	std::cout << headline;
	std::vector<CWaypoint*>::iterator it;
	for(it = route.begin(); it != route.end(); ++it){
		std::cout << (*it)->getName();
		if(it == route.end()-1){
			std::cout << std::endl;
		}
		else{
			std::cout << ", ";
		}
	}

}

void CStreetMap::add(const CWaypoint &data) {
	m_wpDatabase.add(data.getName(), data);
}

void CStreetMap::add(const CPOI &data) {
	m_poiDatabase.add(data.getName(), data);
}

void CStreetMap::add(std::string const& from, std::string const& to,
		CConnection::connection_t const& c) {
	try{
	CConnection connection(from, to, c);
	std::string keyString = from + "-" + to;
	m_connectionDatabase.add(keyString, connection);
	}
	catch(std::string& err){
		std::cerr << err;
	}
}

void CStreetMap::findRoute(std::string from, std::string to) {
	route_t route;
	CWaypoint* start = m_wpDatabase.get(from);

	if(start != 0){
		route.push_back(start);
		route = findNextRouteElement(route, to);
		if(route.back() != 0){
			printRoute("Route found: " , route);
		}
		else{
			std::cout << "no valid connection found" << std::endl;
		}
	}
}

void CStreetMap::print() {
	std::map<std::string, CConnection> connectiondb = m_connectionDatabase.getReferenceToMap();
	for(auto& con:connectiondb){
			std::cout << con.second;
		}
}

CStreetMap::~CStreetMap() {
}

