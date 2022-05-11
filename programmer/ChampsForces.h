#pragma once
#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include <iostream>

class ChampForces {
    public:
    //les methodes
    void agit_sur(ObjetMobile& obj);
    Vecteur getintensite() const;

    //operateur : pas nécessaire mais plus visuel
	ChampForces (Vecteur F=1)
		: intensite (F) {}
    private:
    //les attributs
    Vecteur intensite;
};


std::ostream& operator<<(std::ostream& sortie, ChampForces const& C);
std::ostream& operator<<(std::ostream& sortie, ChampForces const& champF);



class Vent : public ChampForces {
	public:
	Vent (Vecteur orin, Vecteur nor, Vecteur l, Vecteur hau, double pro,double inten=1) : ChampForces(inten), origine(orin), normale(nor), largeur(l), hauteur(hau), profondeur(pro) { 
		//au cas ou les vecteurs ne soit pas perpendiculaires
		
		if (not ((largeur|normale)==0)) {
		Vecteur a(!normale); //a prend la direction de normal
			largeur= largeur - (largeur*a)*a;
		}	
		
		if (not ((hauteur|normale)==0)) {
		Vecteur a(!normale); //a prend la direction de normal
			hauteur= hauteur - (hauteur*a)*a;
		}
		
		if (not ((largeur|hauteur)==0)) { 
			 Vecteur a(!largeur); //a prend la direction de largeur
			hauteur = hauteur - (hauteur*a)*a;
		}	
	}
	//methode 
	Vecteur getnormale();
	
	private:
	Vecteur origine;
	Vecteur normale; //direction du vent 
	Vecteur largeur;
	Vecteur hauteur;
	double profondeur;
	double intensite;
	};
