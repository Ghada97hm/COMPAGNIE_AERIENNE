#pragma once
#include<fstream>
#include <iostream>
using namespace std;
class date {
	int heure;
	int minute;
	int jour;
	int mois;
	int annee;
public:
	date(int = 0, int = 0, int = 0, int = 0, int = 0);
	~date();
	void saisir_date();
	void afficher_date();
	friend ostream& operator<<(ostream&, date&);
	friend istream& operator>>(istream&, date&);
	friend ostream& operator<<(ostream&, date*);
	friend istream& operator>>(istream&, date*);
	bool operator==(const date&);

};