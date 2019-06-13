#pragma once
#include"vols.h"
#include "personne.h"
#include<fstream>
#include<vector>
#include <iostream>
using namespace std;
class Client :public personne
{
	string nom;
	string prenom;
	double CIN;
	double num_passeport;
	string adresse;
	string adresse_mail;
	double num_tel;
	vector<Client*>tab;
public:
	Client(date,date,string,string,string, string, double, double, string, string, double);
	Client();
	void reserver(vols);
	void annuler(vols);
	void saisie();
	friend istream& operator>>(istream&, Client&);
	friend ostream& operator<<(ostream&, Client &);
	friend istream& operator>>(istream&, Client*);
	friend ostream& operator<<(ostream&, Client *);
	~Client();
};

