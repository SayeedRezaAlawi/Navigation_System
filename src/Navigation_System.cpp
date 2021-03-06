//============================================================================
// Name        : Navigation_System.cpp
// Author      : Sayeed Reza Alawi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "CWaypoint.h"
#include "CNavigationSystem.h"
#include "CJsonScanner.h"
#include <string>
#include "CJsonStatmentHandler.h"
using namespace std;



int main() {
	CNavigationSystem navObj;
	navObj.run();
}
