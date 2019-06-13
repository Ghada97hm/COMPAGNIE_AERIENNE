#include "Client.h"
#include"administrateur.h"
Client::Client()
{ 
}
Client::Client(date dd, date da, string vd, string va, string a, string b, double c, double d, string e, string f, double g) :personne(dd, da, vd, va), nom(a),
prenom(b), CIN(c), num_passeport(d), adresse(e), adresse_mail(f), num_tel(g)
{
}

void Client::reserver(vols v) {		

	if  (v.getP() > 0) cout << "place reservee ";
	 v.setP(1);
	cout << "il n'y a pas de place disponible dans l'avion ";
}

void Client::saisie() {
	Client c;
	personne::saisie();
	cin >> c;
}
istream& operator>>(istream& in, Client& c ) {
	cout << "saisir vos coordonnées  : nom , prenom , numero CIN , num passeport , adresse , adresse mail et numero de telephone : " << endl;
	in >> c.nom;
	in >> c.prenom;
	in >> c.CIN;
	in >> c.num_passeport;
	in >> c.adresse;
	in >> c.adresse_mail;
	in >> c.num_tel;
	/*Client*c = new Client();
	in >> *c;
	c.tab.push_back(c);*/
		return in;
}
istream& operator>>(istream& in, Client *c) {//lire du fichier 
	
	in.seekg(0);
	while(1){
	if (in.eof()) break;
	Client* c = new Client();
	in >> *c;
	c->tab.push_back(c);
	}
return in;
}
ostream& operator<<(ostream& out, Client *c) //ecrire dans un fichier 
	
 {	
	for (int i = 0; i < c->tab.size(); i++)
		out << *c->tab[i] << endl;
	return out;
}
ostream& operator<<(ostream& out, Client &c)
{
	out << " " << c.nom << " " << c.prenom << " " << c.CIN << " " << c.num_passeport << " " << c.adresse << " " << c.adresse_mail << " " << c.num_tel << endl;
	return out;
}
void Client::annuler(vols v) {
	int C;
	cout << "donner votre CIN " << endl;
	cin >> C;
	for (int i=0;i<tab.size();i++)
		if (tab[i]->CIN == C) {
			delete tab[i];
			tab.erase(tab.begin() + i);
		//appel de la fonction erease 
		}
}
Client::~Client()
{
}