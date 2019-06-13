#include "administrateur.h"
#include <iostream>
#include<fstream>
#include <iomanip>
#include"date.h"
administrateur::administrateur() {
}
administrateur::administrateur(date d, date dd, string ch, string chh) :personne(d, dd, ch, chh) {
}
administrateur::administrateur(const administrateur& a) : personne(a) {
	for (int unsigned i = 0; i < tab1.size(); i++) {
		vols *v = new vols(*a.tab1[i]);
		tab1.push_back(v);
	}
}
 void administrateur::vider() {
	 for (int unsigned i = 0; i <=tab1.size(); i++) {

		 tab1.pop_back();
	 }


}
int administrateur::chercher(fstream& f, int id) {
	administrateur d;
	f >> &d;
	return d.chercher(id);
}
int administrateur::chercher(int id) {
	for (int unsigned i = 0; i < tab1.size(); i++)
	{
		if (id == tab1[i]->getID())	return i;
		return -1;
	}
}
void administrateur::annuler(fstream& f, int ind) {
	administrateur ad, ad1;
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "ffffff";
	f >> &ad;
	f.close();
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::trunc);
	if (!f.is_open())	cout << "ffffff";

	f.close();
	
	for (int unsigned i = 0; i < ad.tab1.size(); i++)
	{if(ind != ad.tab1[i]->getID())
		ad1.tab1.push_back(ad.tab1[i]);
		cout << i;
	}
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "ffffff";
	f << &ad1;

	f.close();
}
administrateur::~administrateur()
{
}
ostream& operator<<(ostream& out, administrateur* d) {
	for (int unsigned i= 0; i < d->tab1.size(); i++)
		out << d->tab1[i] << endl;
	return out;
}
ostream& operator<<(ostream& out, administrateur& d) {
	for (int unsigned i = 0; i < d.tab1.size(); i++)
		out << i + 1 << " eme vols   " << *d.tab1[i] << endl;
	return out;
}
istream& operator>>(istream& in, administrateur& d) {
	char rep;
	
	do {vols *v = new vols();
		in >> *v;
		d.tab1.push_back(v);
		cout << "tappez o pour ajoutez encors" << endl;
		cin >> rep;
	} while (rep == 'o');
	return in;
}
istream& operator>>(istream& in, administrateur* d) {
	in.seekg(0);
	while (1){	vols *v = new vols();

		in >> v; 
		if(in.eof())break;
		d->tab1.push_back(v);
		
	}
	return in;
}
/*void administrateur::enregistrer() {
	fstream f;
	f.open("c:\\fichierVOLS.txt", ios::in | ios::out | ios::trunc);
	if (!f.is_open())	exit(-1);
	f << this;
	f.close();
}*/
/*void administrateur::recuperer() {
	fstream f;
	f.open("c:\\fichierVOLS.txt", ios::in);
	if (!f.is_open())	exit(-1);
	f >> this;
	f.close();
}*/
void administrateur:: chercher1(fstream& f,string a , string b, date c,date d ) {
	administrateur d1;
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "			";
	f >> &d1;
	for (int unsigned i=0; i < d1.tab1.size(); i++)
	{
		if  ((d1.tab1[i]->getVd() == a) && (d1.tab1[i]->getVa() == b) && (d1.tab1[i]->getDd() == c) && (d1.tab1[i]->getDa() == d))
		{
			cout << "il existe un vol " << endl;
			cout << "le prix du vol  :" << d1.tab1[i]->getPrix() << endl;;
	
		}

	}

}
void administrateur::reserver(fstream& f, vols v, string a, string b, date c, date d) {
	administrateur d3;
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "			";
	f >> &d3;
	for (int unsigned i = 0; i < d3.tab1.size(); i++)
		if ((d3.tab1[i]->getVd() == a) && (d3.tab1[i]->getVa() == b) && (d3.tab1[i]->getDd() == c) && (d3.tab1[i]->getDa() == d) && (v.getP() > 0))
		{
			cout << "place reservee ";
			v.setP(1);
		}
	cout << "il n'y a pas de place disponible dans l'avion ";
}
/*vols administrateur::chercher2(fstream& f, string a, string b, date c, date d) {
	administrateur d3;
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "			";
	f >> &d3;
	for (int unsigned i=0; i< d3.tab1.size(); i++)
		if ((d3.tab1[i]->getVd() == a) && (d3.tab1[i]->getVa() == b) && (d3.tab1[i]->getDd() == c) && (d3.tab1[i]->getDa() == d))
				return *(d3.tab1[i]);
	return *(d3.tab1[0]);
}*/
bool administrateur::chercher3(fstream& f, string a, string b, date c, date d) {
	administrateur d2;
	f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
	if (!f.is_open())	cout << "	hhhhhhhhh		";
	f >> &d2;
	cout <<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"<< endl;
	for (int unsigned i = 0; i < d2.tab1.size(); i++)
		if ((d2.tab1[i]->getVd() == a) && (d2.tab1[i]->getVa() == b) && (d2.tab1[i]->getDd() == c) && (d2.tab1[i]->getDa() == d))
			return true;
	return false;
}