/*
 * CScreen.h
 *
 *  Created on: Mar 8, 2021
 *      Author: reza
 */
//class CRoute;
#ifndef CSCREEN_H_
#define CSCREEN_H_
#include "CRoute.h"


class CScreen {
protected:
	CRoute* m_pRoute;
public:
	CScreen();
	void connectToRoute(CRoute* route);
//	virtual void drawRoute() = 0;
	virtual ~CScreen();
};

#endif /* CSCREEN_H_ */
