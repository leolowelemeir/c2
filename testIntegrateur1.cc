#include "Integrateur.h"
#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "constantes.h"
#include <vector>
#include <iostream>

using namespace std;


int main (){
	//On a construit la balle (en 2D selon les instructions)

    Vecteur pos (0, 0);
    Vecteur vit (1.5, 2.0);
    double masse (0.127);
    Vecteur f (0, g.getvecteur()[1]);
    Balle b ( pos, vit, masse, f ) ;


    // On souhaite faire une etude du mouvement de la balle avec l integrateur sur n intervalles de 0.01s
    unsigned int n;
    do{
        cout << "Sur combien d'intervalles de temps voulez-vous étudier le mouvement de la balle? ";
        cin >> n;
    } while ( n <=0);
    
    IntegrateurEulerCromer I (0.01);
    for (size_t i(0); i < n; ++i) {
    cout << " t = " << (b.get_temps() + i*0.01) << " :"<< endl;
    I.integre (b);
    b.affiche();
    }


return 0;
}


