#pragma once
#include "personne.h"
#include "vols.h"
#include<vector>
#include<iostream>
using namespace std;
class administrateur :public personne
{
	vector<vols*> tab1;
public:
	administrateur();
	administrateur(date, date, string = "", string = "");
	administrateur(const administrateur &);
	//insrer
	//modifier
	vols chercher2(fstream&,string, string, date, date);
	void reserver(fstream& , vols, string, string, date, date);
	void vider();
	void chercher1(fstream& ,string, string, date, date);
	bool chercher3(fstream&,string, string, date, date);
	//void enregistrer();
	//void recuperer();
	void annuler(fstream&, int);
	//annuler
	//chercher
	int chercher(int);
	static int chercher(fstream&, int);
	friend ostream& operator<< (ostream&, administrateur&);//ecrire un admin a l'ecran
	friend ostream& operator<< (ostream&, administrateur*);//ecrire dans un fichier 
	friend istream& operator>> (istream&, administrateur&);//lire a partir du clavier 
	friend istream& operator>> (istream&, administrateur*);//lire a partir du fichier 
	~administrateur();
};