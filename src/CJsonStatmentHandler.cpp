/*
 * CJsonStatmentHandler.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#include "CJsonStatmentHandler.h"

void Json_dispatch_DbName(){

}

void Json_dispatch_AttributeName(){

}

void Json_dispatch_AttributeValue()
{

}

CJson_Statment_Handler::CJson_Statment_Handler() {
	// TODO Auto-generated constructor stub
//	m_WP_transitionTable = (STATE_Json_TransitionTable_t*)&STATE_Json_WP_Transition_Table;
////	m_WP_transitionTable = NULL;
//	m_POI_transitionTable = NULL;
//	m_transitionTable
	m_transitionTable = (STATE_Json_TransitionTable_t*)&STATE_Json_WP_Transition_Table;
}

void CJson_Statment_Handler::Json_processEvent(
		APT::CJsonToken* token,	APT::CJsonToken::TokenType event) {
//	token->
	int tableSize = 17;
	for (uint16_t i = 0; i < tableSize; i++)
		    {
		        if ((*m_transitionTable)[i].event == event)
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
}
