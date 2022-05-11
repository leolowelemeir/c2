#pragma once
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "obstacle.h"
#include "ChampsForces.h"
#include "Objetcompose.h"
#include <vector>
#include <memory>

class Systeme :public Dessinable {
public:
//constructeur
Systeme() = default;
/*Systeme (std::vector<std::unique_ptr<ObjetMobile>>  tobj, std::vector<std::unique_ptr<Obstacle>> tobs)
    : tableau_objets(make_unique <ObjetMobile> (*tobj)), tableau_obstacles(make_unique <Obstacle> (*tobs)) {}
*/
Systeme (std::vector<std::unique_ptr<ObjetMobile>>&  tobj, std::vector<std::unique_ptr<Obstacle>>& tobs)
    : tableau_objets(), tableau_obstacles() {
   for (size_t i(0); i< tobj.size(); ++i){
   tableau_objets.push_back (std::unique_ptr <ObjetMobile> (tobj[i]->copie()));
    }
   for (size_t i(0); i< tobs.size(); ++i){
   tableau_obstacles.push_back (std::unique_ptr <Obstacle> (tobs[i]->copie()));
    }
}


virtual ~Systeme() = default;
Systeme(Systeme const&)            = default;
Systeme& operator=(Systeme const&) = default;
Systeme(Systeme&&)                 = default;
Systeme& operator=(Systeme&&)      = default;


//méthodes

/*virtual void dessine_sur(SupportADessin& support) override
{ support.dessine(*this); } */

void evolue2(double dt);

//Pour pouvoir cacher les pointeurs
void ajoute(ObjetMobile* objet);
void ajoute(Obstacle* obstacle);

//On suppose ici qu'on peut ajouter un systeme à un systeme pour en faire un grand systeme
virtual void ajoute_a(Systeme& S) override;

void affiche() const ;

std::vector<std::unique_ptr<ObjetMobile>> get_tab_obj();
std::vector<std::unique_ptr<Obstacle>> get_tab_obs();

template <typename Type>
std::vector<std::unique_ptr<Type>> copie_unique(std::vector<std::unique_ptr<Type>> tableau){
	std::vector<std::unique_ptr<Type>> tab;
	for (size_t i(0); i<tableau.size();i++){
		tab.push_back (std::unique_ptr<Type> (tableau[i]->copie()));
	}
	return tab;
}


private:
std::vector<std::unique_ptr<ObjetMobile>> tableau_objets;
std::vector<std::unique_ptr<Obstacle>> tableau_obstacles;
std::vector<std::unique_ptr<ChampForces>> tableau_champs;


};

std::ostream& operator<<(std::ostream& sortie, const Systeme& Sys);
