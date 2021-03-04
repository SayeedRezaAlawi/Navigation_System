/*
 * CJsonPersistence.cpp
 *
 *  Created on: Mar 4, 2021
 *      Author: reza
 */

#include "CJsonPersistence.h"
#include "CJsonStatmentHandler.h"
#include "CJsonScanner.h"
#include <fstream>

void CJsonPersistence::setMediaName(std::string name) {
	m_fileName = name;
}

bool CJsonPersistence::writeData(const CWpDatabase &waypointDb,
		const CPoiDatabase &poiDb) {

	return true;
}

bool CJsonPersistence::readData(CWpDatabase &waypointDb, CPoiDatabase &poiDb,
		CPersistentStorage::MergeMode_t mode) {
	if(mode == CPersistentStorage::REPLACE){
		waypointDb.clearDb();
		poiDb.clearDb();
	}
	std::ifstream file;
	file.open(m_fileName);
	APT::CJsonScanner scanner(file);
	bool validToken= true;
	while(validToken == true){
	APT::CJsonToken* token;
	token = scanner.nextToken();
		if(token == NULL){
			validToken = false;
		}
		else{
			CJsonStatmentHandler::Json_processEvent(token);
		}
	}
	std::list<CWaypoint> wplist = CJsonStatmentHandler::getWpList();
	for(auto& wp:wplist){
//		std::cout << wp;
		waypointDb.addWaypoint(wp);
	}
	std::list<CPOI> poilist = CJsonStatmentHandler::getPoiList();
	for(auto& poi:poilist){
//		std::cout << poi;
		poiDb.addPoi(poi.getType(), poi.getName(),
				poi.getDescription(),poi.getLatitude(), poi.getLongitude());
	}
	return true;
}
