#include <iostream>
#include <vector>
#include <array>
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include "obstacle.h"
using namespace std;

int main (){
	
	//pour initialiser la balle
	Vecteur vit({1.0 , 1.0 , 0.0});
	Vecteur pos({1.2,-0.4,0.3});
	Vecteur F({0,0,-0.591725259488945});
	Balle b(pos,vit,0.100530964914873,F,0.2);
	cout << b;
	
	//pour initialiser le plan
	Vecteur orig({0.0,0.0,0.0});
	Vecteur di1({0.0,1.0,0.0}); 
	Vecteur di2({1.0,0.0,0.0}); 
	Vecteur p({1.0,0.0,0.0});
	Plan P(orig,di1,di2,p);
	cout << P;
	
	//pour initialisé la brique 
	Vecteur ori({0.0,0.0,0.5});
	Vecteur lalongueur({0.0,-0.6,0.0}); 
	Vecteur lalargeur({0.8,0.0,0.0}); 
	double hauteur(0.5);
	Brique B(ori,lalongueur,lalargeur,hauteur);
	cout << B;
	
	//pour point le plus proche
	cout<<"test"<<endl;
	P.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	P.distance(b);
	cout<<"#distance"<<endl;

	B.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	B.distance(b);
	cout<<"#distance"<<endl;
	
	//-----------------------------------------------
	b.setposition({1.2,-0.4,1.3});
	cout<<"je deplace la balle en 1.2 -0.4 1.3";
	cout<<b;
	
	cout<<"test"<<endl;
	P.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	P.distance(b);
	cout<<"#distance"<<endl;

	B.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	B.distance(b);
	cout<<"#distance"<<endl;
	
		//-----------------------------------------------
	b.setposition({0.2,-0.4,1.3});
	cout<<"je deplace la balle en 1.2 -0.4 1.3";
	cout<<b;
	
	cout<<"test"<<endl;
	P.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	P.distance(b);
	cout<<"#distance"<<endl;

	B.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	B.distance(b);
	cout<<"#distance"<<endl;
	
			//-----------------------------------------------

	b.setposition({0.2,-1.4,1.3});
	cout<<"je deplace la balle en 0.2 -1.4 1.3";
	cout<<b;
	
	cout<<"test"<<endl;
	P.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	P.distance(b);
	cout<<"#distance"<<endl;

	B.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	B.distance(b);
	cout<<"#distance"<<endl;
	
//-----------------------------------------------
	b.setposition({0.2,-1.4,1.3});
	cout<<"je deplace la balle en 1.2 -1.4 1.3";
	cout<<b;
	
	cout<<"test"<<endl;
	P.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	P.distance(b);
	cout<<"#distance"<<endl;

	B.point_plus_proche(b);
	cout<<"#point le plus proche du plan"<<endl;
	B.distance(b);
	cout<<"#distance"<<endl;
	//faire les tests avec
	return 0;}
