#include <iostream>
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "constantes.h"
#include <cmath>

using namespace std;

//Ce fichier test permet de tester l'efficacité des fonctions de chocs avec un intégrateur: on teste Balle/Balle, Pendule/Balle, Obstacle/Balle

int main () {

// On commence par tester les chocs Balle/Balle
Vecteur pos1 (0,0,0);
Vecteur vit1 (7*sqrt(2), 7*sqrt(2), 0);
Vecteur pos2 (2,2,0);
Vecteur vit2 (0, 0, 0);
double masse1(1);
double masse2(2);

Balle b1 (pos1, vit1, masse1, vecnull);
Balle b2 (pos2, vit2, masse2, vecnull);

cout << "balle 1: " << endl;
b1.affiche();
cout << endl;
cout << "balle 2 : " << endl;
b2.affiche();
cout << endl;

unsigned int n (1000);

//On utilise un intégrateur différent pour chaque balle: EulerCromer pour b1 et Newmark pour b2
IntegrateurEulerCromer I (0.01);
IntegrateurNewmark K (0.01);


    for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (b1);
    K.integre (b2);
    if (((b1.position()-b2.position()).norme() - (b1.getrayon() + b2.getrayon())) < epsilon){
		b1.agit_sur(b2);
	}
   // b1.affiche();
    //cout << endl;
    b2.affiche();
    cout << endl;
    }
    
 
/* 
 
//On fait désormais les chocs Pendule/Balle

Vecteur theta1();
Vecteur thetapoint1();
double m1();
double rayon1();
Vecteur ori1();
double l1();
Vecteur dir(1,0,1);

Pendule p1 (theta, thetapoint, m, vecnull, rayon, ori, l, dir);

//on redéfinit la position et vitesse de base de la balle 1 pour la faire collisionner avec le pendule:
b1.setposition();
b1.setvitesse();

for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (p1);
    K.integre (b1);
    if (((p1.position()-b1.position()).norme() - (p1.getrayon() + b1.getrayon())) < epsilon){
		p1.agit_sur(b1);
	}
	cout << "Balle : " << endl;
    b1.affiche();
    cout << endl;
    cout << "Pendule : " << endl;
    p1.affiche();
    cout << endl;
}


//On teste deux pendules ensemble:
Vecteur theta2();
Vecteur thetapoint2();
double m2();
double rayon2();
Vecteur ori2();
double l2();

Pendule p2 (theta2, thetapoint2, m2, vecnull, rayon2, ori2, l2, dir);

Vecteur theta3();
Vecteur thetapoint3();
double m3();
double rayon3();
Vecteur ori3();
double l3();

Pendule p3 (theta3, thetapoint3, m3, vecnull, rayon3, ori3, l3, dir);

for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (p2);
    K.integre (p3);
    if (((p2.position()-p3.position()).norme() - (p2.getrayon() + p3.getrayon())) < epsilon){
		p2.agit_sur(p3);
	}
	cout << "Pendule 1 : " << endl;
    p2.affiche();
    cout << endl;
    cout << "Pendule 2 : " << endl;
    p3.affiche();
    cout << endl;
}


//On teste une Balle et un Plan

//On reutilise la balle b2
b2.setposition();
b2.setvitesse();

Vecteur ori_plan();
Vecteur di1();
Vecteur di2();
Plan plan(ori_plan, di1, di2);


for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (b2);
    if ( plan.distance(b2) < epsilon){
		plan.agit_sur(b2);
	}
	cout << "Balle : " << endl;
    b2.affiche();
    cout << endl;
}

//On teste une Balle et une Brique

b2.setposition();
b2.setvitesse();

Vecteur ori_brique();
Vecteur longueur();
Vecteur largeur();
double hauteur();
Brique brique (ori_brique, longueur, largeur, hauteur);


for (size_t i(1); i < n; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (b2);
    if ( brique.distance(b2) < epsilon){
		brique.agit_sur(b2);
	}
	cout << "Balle : " << endl;
    b2.affiche();
    cout << endl;
}


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




*/

return 0;
}
