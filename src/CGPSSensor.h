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
