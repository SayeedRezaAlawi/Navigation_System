/*
 * CJsonStatmentHandler.h
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#ifndef CJSONSTATMENTHANDLER_H_
#define CJSONSTATMENTHANDLER_H_

#include "CentralStatmentHandler_cfg.h"
#include <list>
#include "CPOI.h"

class CJsonStatmentHandler {
private:
	static APT::CJsonToken* m_token;
	static std::string m_dbName;
	static std::string m_attributeName;
	static std::string m_name;
	static double m_latitude;
	static double m_longitude;
	static std::string m_type;
	static std::string m_description;
	static unsigned int m_noReadAttribute;
	static std::list<CWaypoint> m_WpList;
	static std::list<CPOI> m_PoiList;

	static JsonParser_ActionPtr_t m_actionFct;
	static state_t m_fromState;
	static state_t m_toState;
	static APT::CJsonToken::TokenType m_event;
	static const STATE_Json_TransitionTable_t* m_transitionTable;
	static unsigned int getSizeOfTransitionTabel();

public:
	CJsonStatmentHandler();
	static void Json_processEvent(APT::CJsonToken* token);
	static void Json_dispatch_DbName();
	static void Json_dispatch_AttributeName();
	static void Json_dispatch_AttributeValue();
	static CPOI::t_poi getPoiType(std::string type);
	static std::list<CPOI>& getPoiList() ;
	static std::list<CWaypoint>& getWpList() ;
	static void setStatmentTable(const STATE_Json_TransitionTable_t* transitionTable);
};

#endif /* CJSONSTATMENTHANDLER_H_ */
