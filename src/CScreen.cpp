/*
 * CScreen.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: reza
 */

#include "CScreen.h"
//#include "CRoute.h"

CScreen::CScreen() {
	// TODO Auto-generated constructor stub

}

CScreen::~CScreen() {
	// TODO Auto-generated destructor stub
}

void CScreen::connectToRoute(CRoute *route) {
	m_pRoute = route;
}
