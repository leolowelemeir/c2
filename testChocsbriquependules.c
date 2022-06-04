#include <iostream>
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "constantes.h"
#include "obstacle.h"
#include <cmath>

using namespace std;

//Ce fichier test permet de tester l'efficacité des fonctions de chocs avec un intégrateur: on teste Balle/Balle, Pendule/Balle, Obstacle/Balle

int main () {
IntegrateurEulerCromer I (0.1);
IntegrateurNewmark K (0.05);
unsigned int n (50);
//On teste un Pendule et une brique

//On crée un nouveau pendule qu'on place à côté de la brique
Vecteur theta4();
Vecteur thetapoint4();
double m4();
double rayon4();
Vecteur ori4();
double l4();

Pendule p4 (theta4, thetapoint4, m4, vecnull, rayon4, ori4, l4, dir);


for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (p4);
    if ( brique.distance(p4) < epsilon){
		brique.agit_sur(p4);
	}
	cout << "Pendule : " << endl;
    p4.affiche();
    cout << endl;
}

