/*
 * CNMEARingBuffer.h
 *
 *  Created on: Mar 7, 2021
 *      Author: reza
 */

#ifndef CNMEARINGBUFFER_H_
#define CNMEARINGBUFFER_H_

//Start of protocol characters
#define SOP1 '!'
#define SOP2 '$'
//End of protocol character
#define EOP 10

class CNMEARingBuffer {
private:
	unsigned char* m_buffer;
	unsigned short m_fillLevel;
	unsigned short m_readIdx;
	unsigned short m_writeIdx;
	unsigned short m_size;
	bool hasMessage() const;
public:
	//Bufferstate enum
	enum bufferState_t{EMPTY, HASMESSAGE};

	CNMEARingBuffer();
	CNMEARingBuffer(unsigned short size);
	bool put(unsigned char element);
	bool get(unsigned char& element);
	CNMEARingBuffer& operator=(const CNMEARingBuffer& other);
	bool operator +=(unsigned char& element);
	bool operator ==(bufferState_t bufferstate) const;
	void clear();
	virtual ~CNMEARingBuffer();
	void setSize(unsigned short size);
};

#endif /* CNMEARINGBUFFER_H_ */
