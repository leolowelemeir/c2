#include <iostream>
#include <vector>
#include "ObjetMobile.h"
#include "obstacle.h"
#include "constantes.h"

using namespace std;

int main() {
	//pour les chocs entre un objet mobile est un obstacle
	
	///ATTENTION LA J'AI LAISSER AVEC LE Z EN HAUT DONC LES RESULTATS PEUT ETRE DIFFERENT 
	//construction de la balle 1
	Vecteur pos(0, 1.36675, 0.283821);
    Vecteur vit(0, 0.715449, 0.0957368);
    Balle b1(pos, vit, 0.00167784948285945 ,g,0.051111, 0.0, 3.0); 
	
	//constrution du plan 
	Vecteur ori(0.0,0.0,0.0);
	Vecteur di1({0.0,1.0,0.0}); 
	Vecteur di2({1.0,0.0,0.0}); 
	Vecteur p({1.0,0.0,0.0});  /// a quoi ca correspond deja ?
	Plan P(ori,di1,di2,p);
	
	
	//affichage
	cout<<"cas 1"<<endl;
	cout<<endl;
	cout<<"vitesse="<<vit;
	cout<<"force"<<g;
	
	cout<<"calculs: "<<endl;
	
	//choc
	P.agit_sur(b1);  ///je coris qu'on est bien avant le pas d'integration 
	
	
	//pour les choc entre 2 balles 
	}
