#include "vols.h"
#include<fstream>
#include<iomanip>
ostream& operator<<(ostream& out, vols& v) {
	cout << "\n id";
	out << v.id;
	cout << "\n date ";
	out << v.date_depart_vol;
		cout << "\n date "; 
		out<<v.date_arrivee_vol;
	cout << "\n prix ";
	out << v.prix;
	cout << "\n place ";
	out<< v.place_reservee;
	cout << "\n ville_depart_vol ";
	out << v.ville_depart_vol;
		cout << "\n ville_arrivee_vol "; 
	out<< v.ville_arrivee_vol;
	return out;
}
ostream& operator<<(ostream& out, vols* v) {
	out <<setw(7)<<v->id<< setw(15) << v->date_depart_vol << setw(15) << v->date_arrivee_vol << setw(7) << v->prix << setw(7) << v->place_reservee << setw(15) << v->ville_depart_vol << setw(15) << v->ville_arrivee_vol;
	return out;
}
istream& operator>> (istream& in, vols& v) {
	cout << "saisir les informations d'un vol " << endl;
	cout << "\n donner id";
	in >> v.id;
	cout << "\n donner date de depart ";

	in >> v.date_depart_vol;
	cout << "\n donner date d arrive ";

	in >> v.date_arrivee_vol;
	cout << "\n donner prix ";

	in >> v.prix;
	cout << "\n donner nbre place ";
	in >> v.place_reservee;
	cout << "\n donner ville depart";

	in >> v.ville_depart_vol;
	cout << "\n donner ville arrive ";
	in>> v.ville_arrivee_vol;
	return in;
}
istream& operator>> (istream& in, vols* v) {
	
	in >> v->id >> &v->date_depart_vol >> &v->date_arrivee_vol >> v->prix >> v->place_reservee >> v->ville_depart_vol >> v->ville_arrivee_vol;
	return in;
}
vols::vols(int x, date d1,date d2,double z, int t, string e, string f) {
	id = x;
	date_depart_vol = d1;
	date_arrivee_vol = d2;
	prix = z;
	place_reservee = t;
	ville_depart_vol = e;
	ville_arrivee_vol = f;

}

/*bool vols::place_disponible() {
	avion a;
	if (a.cherchAvion(id) - place_reservee > 0) {
		place_reservee++;
		return 1;
	}
	return 0;
}*/
vols::~vols()
{
}
/*void vols::afficher(fstream& f) {
	vols v;
	f.seekg(0);
	while (1)
	{
		f >> &v;
		if (f.eof()) break;
		cout << v << endl;
	}
}*/
