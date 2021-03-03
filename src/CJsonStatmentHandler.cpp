/*
 * CJsonStatmentHandler.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#include "CJsonStatmentHandler.h"
#include <memory>
#include <iostream>

APT::CJsonToken* CJsonStatmentHandler::m_token = 0;
std::string CJsonStatmentHandler::m_dbName="";
std::string CJsonStatmentHandler::m_attributeName;
std::string CJsonStatmentHandler::m_name;
double CJsonStatmentHandler::m_latitude;
double CJsonStatmentHandler::m_longitude;
std::string CJsonStatmentHandler::m_type;
std::string CJsonStatmentHandler::m_description;
unsigned int CJsonStatmentHandler::m_noReadAttribute = 0;
std::list<CWaypoint> CJsonStatmentHandler::m_WpList;
std::list<CPOI> CJsonStatmentHandler::m_PoiList;

void Json_dispatch_DbName(){
	CJsonStatmentHandler::Json_dispatch_DbName();
}

void Json_dispatch_AttributeName(){
	CJsonStatmentHandler::Json_dispatch_AttributeName();
}

void Json_dispatch_AttributeValue()
{
	CJsonStatmentHandler::Json_dispatch_AttributeValue();
}

CJsonStatmentHandler::CJsonStatmentHandler() {
	m_fromState = IDLE;
	m_toState = IDLE;
	m_actionFct = 0;
	m_event = APT::CJsonToken::BEGIN_OBJECT;
	m_transitionTable = (STATE_Json_TransitionTable_t*)&STATE_Json_Transition_Table;
}


void CJsonStatmentHandler::Json_processEvent(APT::CJsonToken* token) {
	m_token = token;
	m_event = token->getType();
	int tableSize = 18;
	for (uint16_t i = 0; i < tableSize; i++)
	{
		if ((*m_transitionTable)[i].event == m_event)
		{
			if((*m_transitionTable)[i].fromState == m_fromState)
			{
				//Transition is valid
				m_actionFct = (*m_transitionTable)[i].actionTransition;
				m_toState = (*m_transitionTable)[i].toState;
				m_fromState = m_toState;
			}
		}
	}
	if (0 != m_actionFct){
		m_actionFct();
	}
//	m_fromState = m_toState;
}

void CJsonStatmentHandler::Json_dispatch_DbName() {
	APT::CJsonStringToken* token;
	token = dynamic_cast<APT::CJsonStringToken*>(CJsonStatmentHandler::m_token);
	CJsonStatmentHandler::m_dbName = token->getValue();
}

void CJsonStatmentHandler::Json_dispatch_AttributeName() {

	APT::CJsonStringToken* token;
	token = dynamic_cast<APT::CJsonStringToken*>(CJsonStatmentHandler::m_token);
	CJsonStatmentHandler::m_attributeName = token->getValue();
}

std::list<CPOI>& CJsonStatmentHandler::getPoiList() {
	return m_PoiList;
}

std::list<CWaypoint>& CJsonStatmentHandler::getWpList() {
	return m_WpList;
}

void CJsonStatmentHandler::Json_dispatch_AttributeValue() {

	if(CJsonStatmentHandler::m_attributeName == "name"){
		APT::CJsonStringToken* token = dynamic_cast<APT::CJsonStringToken*>(CJsonStatmentHandler::m_token);
		CJsonStatmentHandler::m_name = token->getValue();;
		CJsonStatmentHandler::m_noReadAttribute++;
	}
	if(CJsonStatmentHandler::m_attributeName == "latitude"){
		APT::CJsonNumberToken* token = dynamic_cast<APT::CJsonNumberToken*>(CJsonStatmentHandler::m_token);
		CJsonStatmentHandler::m_latitude = token->getValue();
		CJsonStatmentHandler::m_noReadAttribute++;
	}
	if(CJsonStatmentHandler::m_attributeName == "longitude"){
		APT::CJsonNumberToken* token = dynamic_cast<APT::CJsonNumberToken*>(CJsonStatmentHandler::m_token);
		CJsonStatmentHandler::m_longitude = token->getValue();
		CJsonStatmentHandler::m_noReadAttribute++;
	}
	if(CJsonStatmentHandler::m_attributeName == "type"){
		APT::CJsonStringToken* token = dynamic_cast<APT::CJsonStringToken*>(CJsonStatmentHandler::m_token);
		CJsonStatmentHandler::m_type = token->getValue();
		CJsonStatmentHandler::m_noReadAttribute++;
	}
	if(CJsonStatmentHandler::m_attributeName == "description"){
		APT::CJsonStringToken* token = dynamic_cast<APT::CJsonStringToken*>(CJsonStatmentHandler::m_token);
		CJsonStatmentHandler::m_description = token->getValue();
		CJsonStatmentHandler::m_noReadAttribute++;
	}
	if(CJsonStatmentHandler::m_dbName == "waypoints"){
		if(m_noReadAttribute == 3){
			m_WpList.push_back(CWaypoint{m_name, m_latitude,m_longitude});
			m_noReadAttribute = 0;
//			for(auto& wp:m_WpList){
//				std::cout << wp << std::endl;
//			}
		}
	}
	if(CJsonStatmentHandler::m_dbName == "pois"){
		if(m_noReadAttribute == 5){
			m_PoiList.push_back(CPOI{CJsonStatmentHandler::getPoiType(m_type), m_name,m_description, m_latitude,m_longitude});
			m_noReadAttribute = 0;
//			for(auto& poi:m_PoiList){
//				std::cout << poi << std::endl;
//			}
		}
	}
}

CPOI::t_poi CJsonStatmentHandler::getPoiType(std::string type) {
	CPOI::t_poi poi_type = CPOI::RESTAURANT;
	if(type == "RESTAURANT" )
		poi_type =CPOI::RESTAURANT;
	else if(type == "TOURISTIC")
		poi_type =CPOI::TOURISTIC;
	else if(type == "GASSTATION")
		poi_type =CPOI::GASSTATION;
	else if(type == "UNIVERSITY")
		poi_type =CPOI::UNIVERSITY;
	else if(type == "KRANKENHAUS")
		poi_type =CPOI::KRANKENHAUS;
	else if(type == "BUSSTATION")
		poi_type =CPOI::BUSSTATION;
	else if(type == "SCHOOL")
		poi_type =CPOI::SCHOOL;
	else if(type == "MONUMENT")
		poi_type =CPOI::MONUMENT;
	else if(type == "DEFAULT")
		poi_type =CPOI::DEFAULT;
	else
	{
//		std::cout <<"Error: Setting enum values\n";
////		err_code = BAD_PARAM;
//		result = false;
	}
	return poi_type;
}
