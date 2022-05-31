#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "ChampsForces.h"
#include "Systeme.h"
#include <cmath>
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------------------------------------------
//pour ChampForces

    //Methodes
Vecteur ChampForces::getintensite() const {return intensite;}

  
void ChampForces::agit_sur(ObjetMobile& obj) const{
  obj.ajoute_force(intensite);
   }
 
ChampForces* ChampForces::copie() const { 
        return (new ChampForces(*this));}
        
   
void ChampForces::ajoute_a(Systeme& S){
	S.ajoute(this);
	cout <<"un Champs de force a ete ajoute au systeme"<<endl;
	}

    
	//Operateur
ostream& operator<<(ostream& sortie, ChampForces const& champF){
    sortie << "On a un champ de force: " << endl;
    sortie << champF.getintensite()  << "  #intensite";
    return sortie;}

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
	 if ( (influe (obj)) and (not obj.danschamp)){
		 obj.danschamp= true;
		 obj.setforce (obj.getforce()+intensite);
	 }
	 else if ( (not influe(obj)) and (obj.danschamp)){
		 obj.danschamp= false;
		 obj.setforce (obj.getforce() - intensite);
	 }
 } 
 

