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

  
void ChampForces::agit_sur(ObjetMobile& obj){
    Vecteur f;
    double valeurforce ((obj.getmasse()-4*M_PI*rho_air*carre(obj.getrayon())*((obj.getrayon())/3))*g.getvecteur()[1]);
    f.setvecteur({0.0, valeurforce});
    //on a mis un vecteur x=0, z=F pour que l'orientation du vecteur soit bonne vers le haut, g etant negatif, cela donne le bon sens
    obj.ajoute_force(f);}
 
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
 Vecteur Vent::getnormale() {return normale;}
 
Vent* Vent::copie() const { 
        return (new Vent(*this));}
        
        
        
