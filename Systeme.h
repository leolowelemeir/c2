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
    
Systeme (std::vector<std::unique_ptr<ObjetMobile>>&  tobj, std::vector<std::unique_ptr<Obstacle>>& tobs)
    : tableau_objets(), tableau_obstacles() {
   for (size_t i(0); i< tobj.size(); ++i){
   tableau_objets.push_back (std::unique_ptr <ObjetMobile> (tobj[i]->copie()));
    } 
   for (size_t i(0); i< tobs.size(); ++i){
   tableau_obstacles.push_back (std::unique_ptr <Obstacle> (tobs[i]->copie()));
}
} */


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
void ajoute(ChampForces* Champ);


void affiche() const ;


private:
std::vector<std::unique_ptr<ObjetMobile>> tableau_objets;
std::vector<std::unique_ptr<Obstacle>> tableau_obstacles;
std::vector<std::unique_ptr<ChampForces>> tableau_champs;


};

std::ostream& operator<<(std::ostream& sortie, const Systeme& Sys);
