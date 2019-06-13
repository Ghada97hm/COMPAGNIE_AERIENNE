#pragma once
#include <iostream>
#include<string>
#include"Date.h"
using namespace std;
class personne
{
protected:
	date date_arrivee;
	date date_depart;
	string ville_depart;
	string ville_arrivee;
public:
	personne();
	personne(date , date ,string ,string);
	virtual void saisie();
	virtual void afficher();
	/*virtual void anuuler()=0;
	virtual bool rechercher();
	*/
	virtual ~personne();
};

