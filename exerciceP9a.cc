#include "Integrateur.h"
#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "Systeme.h"
#include "obstacle.h"
#include <vector>
#include <iostream>
#include <memory>
using namespace std;


int main (){
	///est ce que j'utilise bien le constructeur la ?? (je veux farie comme si j'avais initialiser dans le constructeur des tableaux nuls
    Systeme le_systeme;
	//vector<unique_ptr<ObjetMobile>> tab1;
	//vector<unique_ptr<Obstacle>> tab2;
	//pb ici que je comprned pas (jetais en train de fair un test 
	//Systeme le_systeme1(tab1,tab2);
    
    //On a construit la balle (en 2D selon les instructions de l'exercice de P7)
    Vecteur pos (0, 0);
    Vecteur vit (1.5, 2.0);
    double masse (0.127);
    Vecteur f (0, -9.81);
    Balle b (pos,vit,masse,f);

    // on va utiliser la copie polymorphique avec des unique ptr
    le_systeme.ajoute(new Balle (b));
    
    //construction d'un obstacle (ici un plan)
	Vecteur orig({0.0,0.0,0.0});
	Vecteur di1({0.0,1.0,0.0}); 
	Vecteur di2({1.0,0.0,0.0}); 
    Plan P(orig,di1,di2);
	
    //meme idee qu'avant mais ici on ajoute un systeme
    le_systeme.ajoute(new Plan (P));
    
    //construction d'un systeme
	//Systeme S(tab_objet,tab_obstacle);

    // On souhaite faire une etude du mouvement de la balle avec l integrateur sur n intervalles de 0.01s car on utilise les meme condition que l'exercice P7
    unsigned int n;
    do{
        cout << "Sur combien d'intervalles de temps voulez-vous étudier le mouvement de la balle? ";
        cin >> n;
    } while ( n <=0);
    
    IntegrateurEulerCromer I (0.01);
    for (size_t i(0); i < n; ++i) {
    cout << " t = " << b.get_temps() + i*n << " :"<< endl;
    I.integre (b);
    cout << b;
    }


return 0;
}



