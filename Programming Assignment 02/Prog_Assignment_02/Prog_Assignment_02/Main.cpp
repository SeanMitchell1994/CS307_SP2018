/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Main.cpp
*   Author: Sean Mitchell
*   Desc: Main for the program
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>

#include "Simulation.h"

using namespace std;

int main()
{
	//cout << "Main Working!" << endl;

	Simulation *sim = new Simulation();
	delete sim;

	system("pause");
	return 0;
}