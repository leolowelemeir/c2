#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "ChampsForces.h"
#include "Systeme.h"
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

//----------------------------------------------------------------------------------------------------------------
//pour ChampForces

    //Methodes
Vecteur ChampForces::getintensite() const {return intensite;}

void ChampForces::ajoute_a(Systeme& S){
	S.ajoute(this); //  pour pouvoir ajouter un ChampForces  a un Systeme , le plus simple c'est d'appeler une methode propre au Systeme qui ajoutera ce ChampForces au bon endroit 
	cout <<"un Champs de force a ete ajoute au systeme"<<endl;
	}
	
int ChampForces::compteur(0); 	//on initialise le compteur à 0
int ChampForces::getnumero() const { return numero; }


	

//--------------------------------------------------------------------------------------------------------------
//pour Vent

	//methodes
 Vecteur Vent::getnormale() {return n;}
 
 Vent* Vent::copie() const { 
        return (new Vent(*this));}
 
 bool Vent::influe(ObjetMobile const& obj) const{
	 Vecteur dist (obj.position() - origine);
	 //On verifie que l'objet se trouve dans le champ d'action du vent
		if ((  (largeur.norme()- (dist|(!largeur))) > epsilon) and ( (hauteur.norme()- (dist|(!hauteur))) > epsilon ) and ((profondeur- (dist|n)) > epsilon) and ((dist|n)> epsilon) and ((dist|(!largeur))> epsilon) and ((dist|(!hauteur))>epsilon) ){
			return true;
		}
		else {return false;}
 }
 
 void Vent::agit_sur(ObjetMobile& obj) const {
	 Vecteur F;
	 F = 3.77*obj.getrayon()*obj.getrayon()*intensite.norme()*intensite.norme()*n;	//on suit la formule donée dans le complement mathématique du projet
	 bool a(obj.getdanschamp(this->getnumero()));
	 if ( (influe (obj)) and (not a)){ // si l'objet est dans le champs et que le champs n'a pas deja été ajouté alors :
		 obj.setdanschamp(this->getnumero(), true); //dire pour la suite que le champs a deja été ajouté
		 obj.setforce (obj.getforce()+F);
	 }
	 else if ( (not influe(obj)) and (a)){
		 obj.setdanschamp(this->getnumero(), false);
		 obj.setforce (obj.getforce() - F);
	 }
 } 

 void Vent::affiche() const {
	cout << "Ce champ de force a pour caractéristiques: "<<endl;
	cout << "intensité: " << intensite << endl;
	cout << "origine : " << origine << endl;
	cout << "direction du vent n : " << n << endl;
	cout << "hauteur : " << hauteur << endl;
	cout << " largeur : " << largeur << endl;
	cout << "profondeur : " << profondeur << endl;

	
   }

ostream& operator<<(ostream& sortie, Vent const& vent){
    vent.affiche();
    return sortie;
    }
