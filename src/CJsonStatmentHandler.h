/*
 * CJsonStatmentHandler.h
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#ifndef CJSONSTATMENTHANDLER_H_
#define CJSONSTATMENTHANDLER_H_

#include "CentralStatment_cfg.h"
#include "CentralStatmentHandler_cfg.h"

class CJson_Statment_Handler {
private:

	JsonParser_ActionPtr_t m_actionFct;
	state_t m_fromState;
	state_t m_toState;
	APT::CJsonToken::TokenType m_event;
//	const STATE_Json_TransitionTable_t* m_WP_transitionTable;
//	const STATE_Json_TransitionTable_t* m_POI_transitionTable;

	const STATE_Json_TransitionTable_t* m_transitionTable;

public:

	/**
	 * Constructor, taking two configuration parameters identifying the functions which will be called in error case
	 */
	CJson_Statment_Handler();
	void Json_processEvent(APT::CJsonToken* token, APT::CJsonToken::TokenType  event);
};

#endif /* CJSONSTATMENTHANDLER_H_ */
