#pragma once
#include"avion.h"
#include <string>
#include <iostream>
using namespace std;
class vols
{
	int id;
	date date_depart_vol;
	date date_arrivee_vol;
	double prix;
	int place_reservee;
	string  ville_depart_vol;
	string ville_arrivee_vol;
public:
	int getP() { return place_reservee; }
	void setP(int x) { place_reservee -= x; }
	double getPrix() { return prix; }
	friend ostream& operator<<(ostream&, vols&);
	friend istream& operator>>(istream&, vols&);
	friend ostream& operator<<(ostream&, vols*);
	friend istream& operator>>(istream&, vols*);
//	static void afficher(fstream&);
	//static fstream creer();
	string getVd() { return ville_depart_vol; }
	string getVa() { return ville_arrivee_vol; }
	date getDd() { return date_depart_vol; }
	date getDa() { return date_arrivee_vol; }
	vols(int=5,date=(8,2,2,2,2), date=(8, 2, 2, 2, 2), double=5, int = 0, string = "f", string = "ss");
	bool place_disponible();
	int getID() { return id; }
	~vols();
};

