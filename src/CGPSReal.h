/*
 * CGPSReal.h
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#ifndef CGPSREAL_H_
#define CGPSREAL_H_

#include "CGPSSensor.h"
#include "CNMEARingBuffer.h"
#include "CUartDriver.h"

class CGPSReal : public CGPSSensor {
	CNMEARingBuffer m_NMEARingBuffer;
	CUartDriver m_uartDriver;
public:
//	CGPSReal();
	CWaypoint getCurrentPosition();
};

#endif /* CGPSREAL_H_ */
