#include "personne.h"

personne::personne() {

}
personne::personne(date a, date b, string c, string d) : date_depart(a), date_arrivee(b), ville_depart(c),ville_arrivee(d)
{
}
void personne::saisie() {
	cout << "saisir la date de depart " << endl;
	date_depart.saisir_date();
	cout << "saisir la date d'arrivee " << endl;
	date_arrivee.saisir_date();
	cout << "saisir la ville de depart " << endl;
	cin >> ville_depart;
	cout << "saisir la ville d'arrivee " << endl;
	cin >> ville_depart;
}
void personne::afficher() {
	cout << "la date de depart :";
	date_depart.afficher_date();
	cout << "la date d'arrivee " ;
	date_arrivee.afficher_date();
	cout << "la ville de depart  "<<ville_depart;
	cout << "la ville d'arrivee  "<<ville_depart;
}
/*bool personne::rechercher() {
	// a faire apres vol
}*/
personne::~personne()
{
}