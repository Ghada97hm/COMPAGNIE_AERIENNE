#include "vols.h"
#include"avion.h"
#include"Date.h"
#include "Client.h"
#include"personne.h"
#include"administrateur.h"
#include<fstream>
#include<vector>
#include<string>
#include <iostream>
using namespace std;
void main() {
	int choix;
	fstream f;
 
	
	vols v;
	
	vector<vols*> tab1;
	personne *p;
	cout << "BIENVENUE chez M&G" << endl;
	do {
		cout << "********MENU********" << endl << "1: ADMIN" << endl << "2: VISITEUR" << endl << "3: Quitter" << endl;
		cin >> choix;
		switch (choix)
		{
		case 1: {
			int c;
			int j = 0;
			do {
				cout << "Donner le code" << endl;
				cin >> c;
				vols a;
				if (c == 1997) {
					int choi;
					do {
						cout << "Voulez vous?" << endl << "1: ajoutez" << endl << "2: afficher" << endl << "3: supprimer" << endl << "4: rechercher vol" << endl << "5: quitter" << endl;
						cin >> choi;
						switch (choi) {
						case 1: {administrateur ad;
							f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
							if (!f.is_open())	cout << "ffffff";
							cin>> ad;
							f << &ad;
							cout << ad;
							f.close();


							break;
						}
						case 2: {
							administrateur ad1;
							f.open("fichierVOLS.txt", ios::in | ios::out | ios::app);
							if (!f.is_open())	cout << "ffffff";
							f >>&ad1;
							f.close();
					       cout << ad1;
						   
							break;
						}
						case 3: {administrateur ad;
							int d;
							
							cout << "donner l'ID de l'avion a supprimer " << endl;
							
							cin >> d;
							ad.annuler(f,d); 
							break;
							
						}
						case 4:{administrateur ad;
							int x;
							cout << "donner l'ID" << endl;
							cin >> x;
							cout << "la position de vol est   " << ad.chercher(f, x) << endl; 
							break;
						}
						case 5: {break; }
						}
					} while (choix != 5);
				}
				else cout << "Code Incorrect! Ressayez" << endl;
				j++;
			} while ((j < 3) && (c != 1997));

		}
		case 2: {administrateur ad;
			fstream f1;
			date c, d;
			string a, b;
			Client c1;
			f1.open("Clients.txt", ios::in | ios::out | ios::app);
			if (!f1.is_open()) cout<<"       ";
			cout << "Bienvenue cher voyageur " << endl;
			cout << "saisir la ville de depart , ville d'arrivee , date de depart , date d'arrivee" << endl;
			cin >> a >> b >> c >> d;
			ad.chercher1(f,a,b,c,d);
				char rep;
				cout << "voulez vous reservez, tapez o si oui " << endl;
				cin >> rep;
				if (rep == 'o') {
					vols v;
					c1.saisie();
					v=ad.chercher2(f,a,b,c,d);
					c1.reserver(v);
					cout << "nbr de place devenuuuuu!!! " << v.getP() << endl;
					cout << "operation reussite " << endl;
				
			}
			f1.close();
			f.close();
			break;
		}
		default:
			break;
		}
	} while (choix != 3);

	f.close();
	system("PAUSE");
}
