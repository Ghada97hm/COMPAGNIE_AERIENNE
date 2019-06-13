#pragma once
#include"Date.h"
class avion
{
	double vID[5]{123,2,3,4,5};
	//int nbr_places_avion = 100;
public:
	avion();
	//int getP() { return nbr_places_avion; }
	int cherchAvion(int);
	~avion();
};