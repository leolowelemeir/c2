#include "Integrateur.h"
#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "constantes.h"
#include "ChampsForces.h"
#include <vector>
#include <iostream>

using namespace std;


int main (){
	ChampForces champ (g);
    Vecteur pos (vecnull);
    Vecteur vit (0, 0.1, 0.2);
    double masse (0.100530964914873);
    Vecteur f (0, -0.591725259488945, 0);
    Balle b ( pos, vit, masse, f ) ;

cout << champ << endl;
b.affiche();
cout << endl;

   /*IntegrateurEulerCromer I (0.01);
    
    for (size_t i(1); i < 5; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    I.integre (b);
    b.affiche();
    cout << endl;
    }
    */
    IntegrateurNewmark K (0.01);
    
    for (size_t i(1); i < 1000; ++i) {
    cout << "l'intégration " << i << " donne :" << endl;
    K.integre (b);
    b.affiche();
    cout << endl;
    }

return 0;
}


