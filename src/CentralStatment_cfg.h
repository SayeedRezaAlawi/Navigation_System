/*
 * CentralStatmentHandler_cfg.h
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#ifndef CENTRALSTATMENT_CFG_H_
#define CENTRALSTATMENT_CFG_H_

#include "CJsonToken.h"

typedef void (*JsonParser_ActionPtr_t)();
void Json_dispatch_DbName();
void Json_dispatch_AttributeName();
void Json_dispatch_AttributeValue();

enum state { IDLE, WAIT_FOR_FIRSTTOKEN, WAIT_FOR_DBNAME, WAIT_FOR_NAMESEPARATOR, WAIT_FOR_VALUESEPARATOR, WAIT_FOR_BEGINARRAY,
		WAIT_FOR_BEGINOBJECT, WAIT_FOR_ATTRIBUTENAME, WAIT_FOR_ATTRIBUTEVALUE, WAIT_FOR_ENDARRAY, WAIT_FOR_ENDOBJECT };
typedef state state_t;

enum attribute_store_state { STORE_NAME, STORE_LATITUDE, STORE_LONGITUDE};
typedef attribute_store_state attribute_store_state_t;

typedef struct
{
    APT::CJsonToken::TokenType       	event;
    state_t       						fromState;
    state_t       						toState;
	JsonParser_ActionPtr_t   			actionTransition;

} STATE_Json_Transition_t;

typedef STATE_Json_Transition_t  STATE_Json_TransitionTable_t[];

#endif /* CENTRALSTATMENT_CFG_H_ */
