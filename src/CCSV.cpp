/*
 * CCSV.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: reza
 */

#include "CCSV.h"
#include <iostream>
#include <fstream>
#include <algorithm>

CCSV::CCSV() {
	// TODO Auto-generated constructor stub

}

void CCSV::setMediaName(std::string name) {
	m_WpFileName = name + "-wp.txt";
	m_PoiFileName = name + "-poi.txt";
}

bool CCSV::writeData(const CWpDatabase &waypointDb, const CPoiDatabase &poiDb) {
	bool isFileWirteSuccessful = false;

	std::ofstream file;
	CWpDatabase::Waypoin_map Wp_map = waypointDb.getWaypoints();
	file.open(m_WpFileName);
	if(file.is_open()){
		for(auto& wp: Wp_map){
			file << wp.second.getName() << ";" << wp.second.getLatitude() << ";" << wp.second.getLongitude() << std::endl;
		}
		isFileWirteSuccessful = true;
		file.close();
	}
	else {
		std::cout << "EROR: waypoint File write failed"<<std::endl;
	}

	isFileWirteSuccessful =false;
	CPoiDatabase::POI_map Poi_map = poiDb.getPois();
	file.open(m_PoiFileName);
	if(file.is_open()){
		for(auto& poi:Poi_map){
			file << poi.second.poiTypeToString()<< ";" << poi.second.getName() << ";" << poi.second.getDescription() << ";"
					<< poi.second.getLatitude() << ";" << poi.second.getLongitude() << std::endl;
		}
		isFileWirteSuccessful = true;
		file.close();
	}
	else {
		std::cout << "EROR: Point of interests File write failed"<<std::endl;
	}

	return isFileWirteSuccessful;
}

bool CCSV::readData(CWpDatabase &waypointDb, CPoiDatabase &poiDb,CPersistentStorage::MergeMode_t mode) {
	if(mode == CPersistentStorage::REPLACE){
		waypointDb.clearDb();
		poiDb.clearDb();
	}
	std::string name;
	double latitude,longitude;
	CPOI::t_poi type;
	std::string descrioption;
	int lineAddress=0;

	bool isFileReadSuccessful = false;
	std::ifstream file;
	std::string line;

	file.open(m_WpFileName);
	if(file.is_open()){
		while(true){
			std::getline(file,line);
			lineAddress++;
			if (file.eof() || line == "") {
				break;
			}
			if(std::count(line.begin(),line.end(),';') < 2 && std::count(line.begin(),line.end(),',') == 0)
			{
				std::cout << "Error:" << errorToString(CCSV::TOOFEWFIELDS)<< " in line " <<  lineAddress << " " <<  line << std::endl;
				continue;
			}
			if(std::count(line.begin(),line.end(),',') > 0)
			{
				std::cout << "Error:" << errorToString(CCSV::WRONGDELIMITER) << " in line " <<  lineAddress << " " <<  line << std::endl;
				continue;
			}
			else{
				readWpObj(line, name, latitude, longitude);
				waypointDb.addWaypoint(CWaypoint{name,latitude,longitude});
			}
		}
		isFileReadSuccessful =true;
		file.close();
	}
	else{
		std::cout << "Error:" << errorToString(CCSV::READWPFAILD ) <<std::endl;
	}
	isFileReadSuccessful = false;
	lineAddress = 0;
	file.open(m_PoiFileName);
	if(file.is_open()){
		while(true){
			std::getline(file,line);
			lineAddress++;
			if (file.eof() || line == "") {
				break;
			}
			if(std::count(line.begin(),line.end(),';') < 4 && std::count(line.begin(),line.end(),',') == 0)
			{
				std::cout << "Error:" << errorToString(CCSV::TOOFEWFIELDS) << " in line " <<  lineAddress << " " << line << std::endl;
				continue;
			}
			if(std::count(line.begin(),line.end(),',') > 0)
			{
				std::cout << "Error:" << errorToString(CCSV::WRONGDELIMITER )<< " in line " <<  lineAddress << " " <<line << std::endl;
				continue;
			}
			else{
				readPoiObj(line, type, name, descrioption, latitude, longitude);
				poiDb.addPoi(type,name,descrioption, latitude, longitude);
			}

		}
		isFileReadSuccessful =true;
		file.close();
	}
	else{
		std::cout << "Error:" << errorToString(CCSV::READPOIFAIELD ) <<std::endl;
	}
	return isFileReadSuccessful;
}

void CCSV::readWpObj(std::string line, std::string& name,double& latitude,double& longitude)
{
	int sempos,nextsempos;
	sempos = line.find(";");
	name = line.substr(0, sempos);
	nextsempos=line.find(";",sempos+1);
	latitude = std::stod(line.substr(sempos+1, nextsempos-sempos-1));
	sempos = nextsempos;
	nextsempos=line.find(";",sempos+1);
	longitude = std::stod(line.substr(sempos+1, nextsempos-sempos-1));
}

void CCSV::readPoiObj(const std::string& line, CPOI::t_poi& type,std::string& name, std::string& descrioption,
		double& latitude, double& longitude){
	int sempos,nextsempos;
	std::string typestr;

	sempos = line.find(";");
	typestr = line.substr(0, sempos);
	setPoiType(typestr,type);
	nextsempos=line.find(";",sempos+1);
	name = line.substr(sempos+1, nextsempos-sempos-1);
	sempos = nextsempos;

	nextsempos=line.find(";",sempos+1);
	descrioption = line.substr(sempos+1, nextsempos-sempos-1);
	sempos = nextsempos;

	nextsempos=line.find(";",sempos+1);
	latitude = std::stod(line.substr(sempos+1, nextsempos-sempos-1));
	sempos = nextsempos;

	nextsempos=line.find(";",sempos+1);
	longitude = std::stod(line.substr(sempos+1, nextsempos-sempos-1));
}


bool CCSV::setPoiType(std::string poitype,CPOI::t_poi &poi_type){
	bool result = true;
	if(poitype == "RESTAURANT" )
		poi_type =CPOI::RESTAURANT;
	else if(poitype == "TOURISTIC")
		poi_type =CPOI::TOURISTIC;
	else if(poitype == "GASSTATION")
		poi_type =CPOI::GASSTATION;
	else if(poitype == "UNIVERSITY")
		poi_type =CPOI::UNIVERSITY;
	else if(poitype == "KRANKENHAUS")
		poi_type =CPOI::KRANKENHAUS;
	else if(poitype == "BUSSTATION")
		poi_type =CPOI::BUSSTATION;
	else if(poitype == "SCHOOL")
		poi_type =CPOI::SCHOOL;
	else if(poitype == "MONUMENT")
		poi_type =CPOI::MONUMENT;
	else if(poitype == "DEFAULT")
		poi_type =CPOI::DEFAULT;
	else
	{
		std::cout <<"Error: Setting enum values\n";
//		err_code = BAD_PARAM;
		result = false;
	}

return result;
}

std::string CCSV::errorToString(errorType_t error) {
	std::string result;
	switch((int) error){
	case 0: result = "WRONGDELIMITER";break;
	case 1: result = "TOOFEWFIELDS";break;
	case 2: result = "READPOIFAIELD";break;
	case 3: result = "READWPFAILD";break;
	}
	return result;
}
