#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include "Integrateur.h"
#include <iostream>
using namespace std;

    
int main (){
    //creation d'un pendule
    Vecteur theta (45);
    Vecteur vit_ang (5);
    double m (2.0);
    Vecteur F (m*g);

    double r (1.0);
    Vecteur Or (1.0, 1.0, 1.0);
    double longueur (5.0);
    
    Pendule p (theta, vit_ang, m, F, r, Or, longueur);
    cout <<"Nous avons : " <<endl;
    p.affiche();
    cout << p.evolution() << "  #accélération" << endl;
    cout<<endl;
    
    //creation d'un integrateur
     IntegrateurEulerCromer I (0.1);

    //faisons avancer le pendule
   
    cout << "L'integrateur 1 donne : "<<endl;
     I.integre (p);
     p.affiche();

	
    
    
    /// Faire point_plus_proche et copieobjet() 
    
    
    return 0;
}


