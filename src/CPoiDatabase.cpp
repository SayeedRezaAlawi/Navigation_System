/*
 * CPoiDatabase.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#include "CPoiDatabase.h"
#include <iostream>

CPoiDatabase::CPoiDatabase() {
}

void CPoiDatabase::addPoi(CPOI::t_poi type, std::string name,
		std::string descrioption, double latitude, double longitude) {
	CPOI poi(type, name, descrioption,latitude,longitude);
	m_POI.insert(std::pair<std::string, CPOI> (name, poi));
}

CPOI* CPoiDatabase::getPointerToPoi(std::string name) {
	CPOI* PtrToPoi = NULL;
	for(auto& poi: m_POI)
	{
		if(poi.first == name)
		{
			PtrToPoi=&poi.second;
			break;
		}
	}
	return PtrToPoi;
}

CPoiDatabase::~CPoiDatabase() {
}
