/*
 * CGPSSensor.h
 *
 *  Created on: Feb 27, 2021
 *      Author: reza
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWaypoint.h"

class CGPSSensor {
public:
	CGPSSensor();
	CWaypoint getCurrentPosition();
	virtual ~CGPSSensor();
};

#endif /* CGPSSENSOR_H_ */
