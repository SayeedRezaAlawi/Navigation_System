/*
 * CNMEARingBuffer.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#include "CNMEARingBuffer.h"
#include "string"
#include <algorithm>

CNMEARingBuffer::CNMEARingBuffer(unsigned short size) {
	m_size = size;
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;
	m_buffer = new unsigned char[m_size];
}

bool CNMEARingBuffer::put(unsigned char element) {
	bool result = false;
	if(m_fillLevel < m_size ){
		m_buffer[m_writeIdx++] = element;
		m_writeIdx %= m_size;
		m_fillLevel++;
		result = true;
	}
	else{
		throw std::string("The buffer is full.");
	}
	return result;
}

bool CNMEARingBuffer::get(unsigned char& element) {
	bool result = false;
	if(m_fillLevel > 0 ){
		element = m_buffer[m_readIdx++];
		m_readIdx %= m_size;
		m_fillLevel--;
		result = true;
	}
	else{
		throw std::string("The buffer is empty.");
	}
	return result;
}

void CNMEARingBuffer::clear() {
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;
}

bool CNMEARingBuffer::operator +=(unsigned char &element) {
	bool result = false;
	if(m_fillLevel < m_size){
		m_buffer[m_writeIdx++] = element;
		m_writeIdx %= m_size;
		m_fillLevel++;
		result = true;
	}
	else{
		throw std::string("The buffer is full.");
	}
}

bool CNMEARingBuffer::operator ==(bufferState_t bufferstate) const {
	bool result = false;
	switch(bufferstate){
	case CNMEARingBuffer::HASMESSAGE: result = hasMessage();break;
	case CNMEARingBuffer::EMPTY: result = !hasMessage();break;
	}
	return result;
}

bool CNMEARingBuffer::hasMessage() const{
	bool startCharFound = false;
	bool hasmessage = false;
	bool result = false;
	for(unsigned short i = m_readIdx; i != m_writeIdx; i++){
		i %= m_size;
		if(m_buffer[i] == EOP && !startCharFound){
			hasmessage = false;
			break;
		}
		if(m_buffer[i] == SOP1 || m_buffer[i] == SOP2){
			startCharFound = true;
		}
		if(m_buffer[i] == EOP && startCharFound){
			hasmessage = true;
			break;
		}
	}
	return result = hasmessage;
}

CNMEARingBuffer::CNMEARingBuffer() {
		m_fillLevel = 0;
		m_readIdx = 0;
		m_writeIdx = 0;
}

CNMEARingBuffer& CNMEARingBuffer::operator =(const CNMEARingBuffer &other) {
	if (this != &other)
	{
	 // Free the existing resource.
		delete[] m_buffer;

		m_size = other.m_size;
		m_fillLevel = other.m_fillLevel;
		m_readIdx = other.m_readIdx;
		m_writeIdx = other.m_writeIdx;
		m_buffer = new unsigned char[m_size];
		for (unsigned short i = 0; i < m_size; i++) {
			m_buffer[i] = other.m_buffer[i];
		}
	  }
	  return *this;
}

void CNMEARingBuffer::setSize(unsigned short size) {
	m_size = size;
	m_buffer = new unsigned char[m_size];
}

CNMEARingBuffer::~CNMEARingBuffer() {
	delete [] m_buffer;
}

