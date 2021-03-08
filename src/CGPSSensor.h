/*
 * CGPSSensor.h
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_
#include "CWaypoint.h"

class CGPSSensor {
public:
	virtual CWaypoint getCurrentPosition() = 0;
//	virtual ~CGPSSensor() ;
};

#endif /* CGPSSENSOR_H_ */
