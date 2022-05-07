#include "Dessinable.h"
#include "Systeme.h"
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "obstacle.h"
#include "Integrateur.h"
#include <memory>

using namespace std;


void Systeme::affiche() const {
    cout << "Le système est composé de : " <<endl;

    cout<<"d'objet mobile"<<endl;
    for (size_t i(0); i < tableau_objets.size(); ++i){
        cout << *(tableau_objets[i]) << endl;		/// Verifier comment prendre la valeur du pointeur et les include suite a l utilisation d unique ptr
        cout<<endl;
    }
    cout<<"d'obstacle"<<endl;
    for (size_t i(0); i < tableau_obstacles.size(); ++i){
        cout << *(tableau_obstacles[i]) << endl;		/// Verifier comment prendre la valeur du pointeur et les include suite a l utilisation d unique ptr
        cout<<endl;
    }
    cout<<"de champs de force"<<endl;
    for(size_t i(0); i<g.taille(); ++i){
        cout<<g.getcomposante(i)<<endl;
    }
}


ostream& operator<<(ostream& sortie,Systeme Sys){
    Sys.affiche();
    return sortie;
}


void Systeme::evolue2( double dt) {


    //ajoutons les forces externes que subissent les objet mobiles (les champs de forces)
    for(size_t i(0); i<tableau_objets.size(); i++){
        ChampForces champ_g(g);
        champ_g.agit_sur(*tableau_objets[i]);                  //g est un champ de force (c'est le seul programmer)
    }

    //pour calculer le cas ou il pourrait y avoir un choc
    for(size_t i(0); i<tableau_objets.size(); i++){
        for(size_t j(i+1); j<tableau_objets.size(); j++){ //pour que les objet ne ce touche u'une fois le debut de la deuxieme boucle est i
            (*tableau_objets[i]).agit_sur((*tableau_objets[j]));
        }
    }

    //et enfin integre l'objet qui "deplace" les objets
    for(size_t k(0); k<tableau_objets.size(); k++){
        Integrateur inte(dt);
        inte.integre(*tableau_objets[k]);
    }
}

void Systeme::ajoute(ObjetMobile* objet){
    tableau_objets.push_back(unique_ptr <ObjetMobile> (objet->copie()));
}
void Systeme::ajoute(Obstacle* obstacle){
    tableau_obstacles.push_back(unique_ptr <Obstacle> (obstacle->copie()));
}
