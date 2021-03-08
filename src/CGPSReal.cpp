/*
 * CGPSReal.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#include "CGPSReal.h"

//CGPSReal::CGPSReal() {
//	// TODO Auto-generated constructor stub
//
//}

CWaypoint CGPSReal::getCurrentPosition() {

	//Some code filling the buffer
	if (m_uartDriver.getBuffer() == CNMEARingBuffer::HASMESSAGE)
	{
		m_NMEARingBuffer = m_uartDriver.getBuffer();
	}
	if (m_uartDriver.getBuffer() == CNMEARingBuffer::EMPTY)
	{
	//some error handling
	}
	CWaypoint wp;
	return wp;
}
