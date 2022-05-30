#include <iostream>
#include <vector>
#include "ObjetMobile.h"
#include "obstacle.h"
#include "constantes.h"

using namespace std;

int main() {
	//on est ici dans le cas on on gere juste le choc entre deux objets et pas un systeme l'evolution d'un systeme entier
	
	//pour les chocs entre un objet mobile est un obstacle
	
	
		//sachant qu'on a pris comme repere l'axe z qui sort du plan et l'axe y vers le haut il y a des changements

	//creation d'un champs de force 
	Vecteur F(0.0,0.0,0.0);
	ChampForces champs(F); //pour pouvoir utiliser agir sur de ChampForces et rajouter la poussé d'archimede

	//construction de la balle 1
	double masse(0.00167784948285945);
	Vecteur pos(0, 0.0465234, 0.624);
    Vecteur vit(0, -2.59108, 0.8);
    Balle b1(pos, vit,masse,masse*g,0.051111, 0.0, 3,0.8,0.01);  ///attention je suis pas sur qu'il faille ajouté g ici peut etre qu'on l'a mis deux fois !! =>non ca aurait ete si on utilisait la fonction evolue2
    cout <<"test";
    champs.agit_sur(b1); //on rajoute la poussé dArchimede
    cout<<"test2";
	///pq besoin d'une variable t ?? Poussée de l'air ?
	//changement d'axe: c'est donc l'axe y qui vaut 0
	//construction du plan 
	Vecteur ori(0.0,0.0,0.0);
	Vecteur di1(1.0,0.0,0.0); 
	Vecteur di2(0.0,0.0,1.0); 
    Plan P(ori,di1,di2);
	
	
	//affichage
	cout<<"cas 1"<<endl;
	cout<<endl;
	cout<<"vitesse="<<b1.getPd()<<endl;
	cout<<"force ="<<b1.getforce()<<endl;
	cout <<endl;
		
	//choc
	P.agit_sur(b1);  ///je coris qu'on est bien avant le pas d'integration 
	///est ce que j'integre ? (le pesne pas si on se dit que le choc se faitdans in temps negligeable (les balles (ou obstacles et balles) se touchent deja donc pas besoin de les deplacer)
	
	cout<<endl;
	cout <<endl;
	
	//------------------------------------------------------------------------------------------
	//pour les chocs entre 2 balles (les balles sont appelés balle 2 et balle 3)
	
	//construction de la balle 2
	double masse2(0.051111);
	Vecteur pos2(0,0.283821,1.36675);
    Vecteur vit2(0,0.0957368,0.715449);
    Balle b2(pos2, vit2, 0.00167784948285945 ,masse2*g,masse2, 0.0, 3.0);
    champs.agit_sur(b2); //on rajoute la poussé dArchimede

	//construction de la balle 3
	double masse3(0.05);
	Vecteur pos3(0, 0.260128, 1.46284);
    Vecteur vit3(0, 0.13874, 0.419218);
    Balle b3(pos3, vit3, 0.1 ,masse3*g,masse3, 0.0, 3.0);
    champs.agit_sur(b3); //on rajoute la poussé dArchimede

	cout<<"cas 2"<<endl;
	cout<<endl;
	cout<<"avant le choc au sol" <<endl;
	cout << "position de la balle2(appelé balle1 par le prof) = " << b2.position()<<endl;
	cout << "position de la balle3 (appelé balle2 par le prof) = " << b3.position()<<endl;

	cout<<"vitesse de la balle2 ="<<b2.getPd()<<endl;
	cout<<"vitesse de la balle3 ="<<b3.getPd()<<endl;

	cout<<"force de la balle2 ="<<b2.getforce()<<endl;
	cout<<"force de la balle3 ="<<b3.getforce()<<endl;
	cout <<endl;
	
	//choc
	cout<<"calculs: "<<endl;
	b2.agit_sur(b3); 
	 
	cout<<endl;

	//apres choc
	cout<<"apres choc: "<<endl;
	
	cout<<"vitesse de la balle2 ="<<b2.getPd()<<endl;
	cout<<"vitesse de la balle3 ="<<b3.getPd()<<endl;

	cout<<"force de la balle2 ="<<b2.getforce()<<endl;
	cout<<"force de la balle3 ="<<b3.getforce()<<endl;

///faudrait faire le test avec un pendule aussi 
	
	}
