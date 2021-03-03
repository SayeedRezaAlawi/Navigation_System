/*
 * CentralStatmentHandler_cfg.h
 *
 *  Created on: Mar 3, 2021
 *      Author: reza
 */

#ifndef CENTRALSTATMENTHANDLER_CFG_H_
#define CENTRALSTATMENTHANDLER_CFG_H_

#include "CentralStatment_cfg.h"

const STATE_Json_TransitionTable_t STATE_Json_Transition_Table = {
/*    Event                            		FromState         	    	ToState                  		Action              */
	{ APT::CJsonToken::BEGIN_OBJECT,    IDLE,    					WAIT_FOR_FIRSTTOKEN,   	     			0					},
	{ APT::CJsonToken::STRING,          WAIT_FOR_FIRSTTOKEN,    	WAIT_FOR_DBNAME,   	     	Json_dispatch_DbName			},
    { APT::CJsonToken::NAME_SEPARATOR,  WAIT_FOR_DBNAME,     		WAIT_FOR_NAMESEPARATOR,           		0      	 			},
    { APT::CJsonToken::BEGIN_ARRAY,     WAIT_FOR_NAMESEPARATOR, 	WAIT_FOR_BEGINARRAY,           			0        			},
    { APT::CJsonToken::BEGIN_OBJECT,    WAIT_FOR_BEGINARRAY,    	WAIT_FOR_BEGINOBJECT,           		0        			},
    { APT::CJsonToken::STRING, 			WAIT_FOR_BEGINOBJECT,   	WAIT_FOR_ATTRIBUTENAME,  	Json_dispatch_AttributeName		},
    { APT::CJsonToken::NAME_SEPARATOR,  WAIT_FOR_ATTRIBUTENAME, 	WAIT_FOR_NAMESEPARATOR,           		0    				},
	{ APT::CJsonToken::STRING,     		WAIT_FOR_NAMESEPARATOR, 	WAIT_FOR_ATTRIBUTEVALUE, 	Json_dispatch_AttributeValue    },
	{ APT::CJsonToken::NUMBER,    		WAIT_FOR_NAMESEPARATOR, 	WAIT_FOR_ATTRIBUTEVALUE, 	Json_dispatch_AttributeValue    },
	{ APT::CJsonToken::VALUE_SEPARATOR, WAIT_FOR_ATTRIBUTEVALUE,	WAIT_FOR_VALUESEPARATOR,  				0					},
	{ APT::CJsonToken::END_OBJECT, 		WAIT_FOR_ATTRIBUTEVALUE,	WAIT_FOR_ENDOBJECT,  					0					},
	{ APT::CJsonToken::BEGIN_OBJECT, 	WAIT_FOR_ENDOBJECT,	        WAIT_FOR_BEGINOBJECT,  					0					},
	{ APT::CJsonToken::VALUE_SEPARATOR, WAIT_FOR_ENDOBJECT,			WAIT_FOR_VALUESEPARATOR,  				0					},
	{ APT::CJsonToken::STRING,  		WAIT_FOR_VALUESEPARATOR,	WAIT_FOR_ATTRIBUTENAME,     Json_dispatch_AttributeName    	},
	{ APT::CJsonToken::BEGIN_OBJECT, 	WAIT_FOR_VALUESEPARATOR,	WAIT_FOR_BEGINOBJECT,  					0					},
	{ APT::CJsonToken::END_ARRAY, 		WAIT_FOR_ENDOBJECT,   		WAIT_FOR_ENDARRAY,  					0					},
	{ APT::CJsonToken::END_OBJECT, 		WAIT_FOR_ENDARRAY,   		IDLE,  									0					},
};
#endif /* CENTRALSTATMENTHANDLER_CFG_H_ */
