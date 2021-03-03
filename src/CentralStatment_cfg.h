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

//typedef struct
//{
//	state_t 											fromstate;
//    STATE_stateInnerTransitionTable_t const *  const 	pInnerTransitionTable;
//    uint16_t                          const 			size;
//} STATE_stateOuterTransition_t;
//
//typedef STATE_stateOuterTransition_t  STATE_stateOuterTransitionTable_t[];
//
//typedef struct
//{
//	state_t       				state;              /**< \brief The state */
//	JsonParser_ActionPtr_t   	actionEntry;        /**< \brief Entry Action of the state */
//	JsonParser_ActionPtr_t   	actionExit;         /**< \brief Exit Action of the state */
//} STATE_stateInnerAction_t;
//
//typedef STATE_stateInnerAction_t  STATE_stateInnerActionTable_t[];

//typedef struct
//{
//    STATE_stateInnerActionTable_t   const * const pInnerStateTable;         /**< \brief The state */
//	uint16_t                        const         size;                     /**< \brief Size of the inner table */
//} STATE_stateOuterAction_t;
//
//enum eProcessType{
//    PROCESS_JsonObject,
//    PROCESS_DbObject,
//};
//typedef enum eProcessType Json_eProcessType_t;

//extern const STATE_Json_TransitionTable_t STATE_Json_WP_Transition_Table;


#endif /* CENTRALSTATMENT_CFG_H_ */
