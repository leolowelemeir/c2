#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include <iostream>
using namespace std;

    
int main (){
    
    Vecteur theta (45);
    Vecteur vit_ang (5);
    double m (2.0);
    Vecteur F (m*g);
    double r (1.0);
    Vecteur Or (1.0, 1.0, 1.0);
    double longueur (5.0);
    
    Pendule p (theta, vit_ang, m, F, r, Or, longueur);
    cout << p;
    cout << p.evolution() << "  #accélération" << endl;
    
    /// Faire point_plus_proche et copieobjet() 
    
    
    return 0;
}


