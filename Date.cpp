#include "Date.h"
#include<iostream>
using namespace std;
date::date(int h, int mn, int j, int m, int a) {
	heure = h;
	minute = mn;
	jour = j;
	mois = m;
	annee = a;
}
void date::saisir_date() {
	cin >> jour >> mois >> annee >> heure >> minute;
}
void date::afficher_date() {
	cout << jour << "/" << mois << "/" << annee << "   " << heure << ":" << minute << endl;
}
ostream& operator<<(ostream& out, date& d) {
	
	out << d.heure << "/" << d.minute << "/" << d.jour << "/" << d.mois << "/" << d.annee << endl;
	return out;
}
istream& operator>>(istream& in, date& d) {
	cout << "donner heure minute jour mois jour annee" << endl;
	in >> d.heure >> d.minute >> d.jour >> d.mois >> d.annee;
	return in;
}
ostream& operator<<(ostream& out, date* d) {
	out << d->heure << "/" << d->minute << "/" << d->jour << "/" << d->mois << "/" << d->jour << "/" << d->annee << endl;
	return out;
}
istream& operator>>(istream& in, date* d) {
	char c;
	in >> d->heure >>c>> d->minute >>c>> d->jour >>c>> d->mois >>c>> d->annee;
	return in;
}
date::~date() {
}
bool date::operator==(const date& d) {
	return ((d.jour == jour) && (d.mois == mois) && (d.annee == annee) && (d.heure == heure) && (d.minute == d.minute));
}