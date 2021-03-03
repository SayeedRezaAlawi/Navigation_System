///*
// * JSonStatment.cpp
// *
// *  Created on: Mar 2, 2021
// *      Author: reza
// */
//
//#include "JSonStatment.h"
//
//void Json_processEvent(
//		const STATE_stateOuterTransitionTable_t *const transitionTable,
//		const STATE_stateOuterAction_t *const actionTable,
//		APT::CJsonToken::TokenType ev, state_t *localstate,
//		Json_eProcessType_t processtype) {
//
//	    //LOG_I("processEvent","");
//	    int guard = 0;
//	    JsonParser_ActionPtr_t acTransition = 0;
//	    JsonParser_ActionPtr_t acEntry = 0;
//	    JsonParser_ActionPtr_t acExit = 0;
//
//	    //Read the state from the watchdog object;
//	    state_t currentState = *localstate;
//	    state_t toState = currentState; //Just in case
//
//	    //Calculate the table index of the outer table
//	    uint16_t index = (uint16_t)currentState;
//
//	    if(processtype == PROCESS_DbObject)
//	    {
//	        index-=5;
//	    }
//	    //This should never happen
//	    if (index >= (uint16_t)APT::CJsonToken::JSON_NULL)
//	    {
//
//	    }
//		//Todo: CHeck for valid pointers
//	    STATE_stateInnerTransitionTable_t const* const pInnerTable = (*transitionTable)[index].pInnerTransitionTable;
//	    uint16_t innerTableSize = (*transitionTable)[index].size;
//	    if (0 == pInnerTable || 0 == innerTableSize)
//	    {
//	        //No transitions in this state
//
//	    }
//	    //Iterate through the inner table and find correct transition
//	    for (uint16_t i = 0; i < innerTableSize; i++)
//	    {
//	        if ((*pInnerTable)[i].event == ev)
//	        {
//	            //Transition found, let's check the guard
//	            guard = (*pInnerTable)[i].guard;
//	            if (0 == guard)
//	            {
//	                //Transition is valid
//	                acTransition = (*pInnerTable)[i].actionTransition;
//	                toState = (*pInnerTable)[i].toState;
//
//	                //Now lets find the entry and exit actions
//	                uint16_t actionTableSize = actionTable->size;
//	                for (uint16_t j = 0; j < actionTableSize; j++)
//	                {
//	                    if (currentState == (*actionTable->pInnerStateTable)[j].state)
//	                    {
//	                        acExit = (*actionTable->pInnerStateTable)[j].actionExit;
//							//if (0 != acExit) acExit();
//	                    }
//	                    if (toState == (*actionTable->pInnerStateTable)[j].state)
//	                    {
//	                        acEntry = (*actionTable->pInnerStateTable)[j].actionEntry;
//							//if (0 != acEntry) acEntry();
//	                    }
//	                }
//	                //Lets call the actions
//	                if (0 != acExit) acExit();
//	                if (0 != acTransition) acTransition();
//	                if (0 != acEntry) acEntry();
//	                *localstate = toState;
//	            }
//	        }
//	    }
//}
