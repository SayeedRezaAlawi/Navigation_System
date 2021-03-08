/*
 * CUartDriver.h
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#ifndef CUARTDRIVER_H_
#define CUARTDRIVER_H_

#include "CNMEARingBuffer.h"
#include <string>

#define DEFULTSIZEOFNMEARINGBUFFER 100

class CUartDriver {
private:
	CNMEARingBuffer m_buffer;
public:
	CUartDriver();
	void isr_rx();
	virtual ~CUartDriver();
	const CNMEARingBuffer& getBuffer() const;
};

#endif /* CUARTDRIVER_H_ */
