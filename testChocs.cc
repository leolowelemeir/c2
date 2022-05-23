#include <iostream>
#include <vector>
#include "ObjetMobile.h"
#include "obstacle.h"
#include "constantes.h"

using namespace std;

int main() {
	//pour les chocs entre un objet mobile est un obstacle
	
	
		//sachant qu'on a pris comme repere l'axe z qui sort du plan et l'axe y vers le haut il y a des changements

	//construction de la balle 1
	Vecteur pos(0, 0.0465234, 0.624);
    Vecteur vit(0, -2.59108, 0.8);
    Balle b1(pos, vit, 0.00167784948285945 ,g,0.051111, 0.0, 3); 
	
	//changement d'axe: c'est donc l'axe y qui vaut 0
	//construction du plan 
	Vecteur ori(0.0,0.0,0.0);
	Vecteur di1(1.0,0.0,0.0); 
	Vecteur di2(0.0,0.0,1.0); 
    Plan P(ori,di1,di2);
	
	
	//affichage
	cout<<"cas 1"<<endl;
	cout<<endl;
	cout<<"vitesse="<<vit;
	cout<<"force"<<g;
	
	cout<<"calculs: "<<endl;
	
	//choc
	P.agit_sur(b1);  ///je coris qu'on est bien avant le pas d'integration 
	
	cout<<"vitesse="<<vit;
	cout<<"force"<<g;
	
	//------------------------------------------------------------------------------------------
	//pour les chocs entre 2 balles (les balles sont appelés balle 2 et balle 3)
	
	//construction de la balle 2
	Vecteur pos2(0,0.283821,1.36675);
    Vecteur vit2(0,0.0957368,0.715449);
    Balle b2(pos2, vit2, 0.00167784948285945 ,g,0.051111, 0.0, 3.0);
    
	//construction de la balle 3
	Vecteur pos(0, 1.36675, 0.283821);
    Vecteur vit(0, 0.715449, 0.0957368);
    Balle b1(pos, vit, 0.00167784948285945 ,g,0.051111, 0.0, 3.0);
	
	}
