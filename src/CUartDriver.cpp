/*
 * CUartDriver.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#include "CUartDriver.h"
#include <string>

CUartDriver::CUartDriver() {
	// TODO Auto-generated constructor stub

}

void CUartDriver::isr_rx() {
	m_buffer.setSize(DEFULTSIZEOFNMEARINGBUFFER);
	std::string data = "$GPGGA,92750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76<LF>";
	for(auto& c:data){
		m_buffer.put(c);
	}
}

const CNMEARingBuffer& CUartDriver::getBuffer() const {
	return m_buffer;
}

CUartDriver::~CUartDriver() {
	// TODO Auto-generated destructor stub
}

