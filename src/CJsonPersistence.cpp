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
	bool isFileWirteSuccessful = false;

		std::ofstream file;
		CWpDatabase::Waypoin_map Wp_map = waypointDb.getWaypoints();
		CWpDatabase::Waypoin_map::iterator it;
		file.open(m_fileName);
		if(file.is_open()){
			for(it=Wp_map.begin();it!=Wp_map.end();it++){
				if (it==Wp_map.begin())
				{
					file<< "{" << "\n"  << "\"waypoints\"" << ":" <<  "[";

				}
				file << "\n" << "{" << "\n" << "\""  << "name"<< "\"" << ":" << "\"" << (*it).second.getName() << "\""
				<< "," << "\n" << "\"" << "latitude"<< "\"" << ":" << (*it).second.getLatitude()
				<< "," << "\n" << "\"" << "longitude"<< "\"" << ":" << (*it).second.getLongitude()
				<< "," << "\n" << "}";
				if(it == --Wp_map.end())
				{
					file<<"\n"<<"]"<<",";
				}
				else{
					file<<",";
				}
			}

		CPoiDatabase::POI_map Poi_map = poiDb.getPois();
		CPoiDatabase::POI_map::iterator poi_it;
		for(poi_it=Poi_map.begin();poi_it!=Poi_map.end();poi_it++){
			if (poi_it==Poi_map.begin())
			{
				file<<  "\n" << "\"pois\"" << ":"  << "[";

			}
			file << "\n" << "{" << "\n" << "\""  << "\"" << "name"<< "\"" << ":" << (*poi_it).second.getName() << "\""
					<< "," << "\n" << "\"" << "latitude"<< "\"" << ":" << (*poi_it).second.getLatitude() << "," << "\n"
					<< "\"" << "longitude"<< "\"" << ":" << (*poi_it).second.getLongitude() << "," << "\n"
					<< "\"" << "type"<< "\"" << ":" <<  "\"" << (*poi_it).second.poiTypeToString() << "\""
					<< "," << "\n" << "\"" << "description"<< "\"" << ":"
					<< "\"" << (*poi_it).second.getDescription() << "\"" << "," << "\n" << "}";


			if(poi_it == --Poi_map.end())
			{
				file<<"\n"<<"]"<<" ";
			}
			else{
				file<<",";
			}
		}
		file<<"\n"<<"}";
		isFileWirteSuccessful = true;
		file.close();
		}
		else{
			std::cout << "EROR: Write failed"<<std::endl;
		}
	return isFileWirteSuccessful;
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
