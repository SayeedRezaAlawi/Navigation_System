#ifndef CGPSSIM_H_
#define CGPSSIM_H_

#include "CGPSSensor.h"

class CGPSSim : public CGPSSensor {
public:
	CGPSSim();
	CWaypoint getCurrentPosition();
};

#endif /* CGPSSIM_H_ */
