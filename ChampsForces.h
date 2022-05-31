#pragma once
#include "ObjetMobile.h"
#include "ex_vecteur.h"
#include "Systeme.h"
#include "constantes.h"
#include <iostream>

class ChampForces {
    public:

	ChampForces (Vecteur F)
		: intensite (F) {}
		
	//Destructeur 
	virtual ~ChampForces() {}
	
	//methodes 
	void ajoute_a(Systeme& S);
    virtual void agit_sur(ObjetMobile& obj) const ;
    Vecteur getintensite() const;
    virtual ChampForces* copie() const;
    
    protected:
    //les attributs
    Vecteur intensite;
};


std::ostream& operator<<(std::ostream& sortie, ChampForces const& champF);



class Vent : public ChampForces {
	public:
	Vent (Vecteur inten,Vecteur orin, Vecteur l, Vecteur hau, double pro)
	: ChampForces(inten), origine(orin), largeur(l), hauteur(hau), profondeur(pro) { 
		
		//au cas ou les vecteurs ne soient pas perpendiculaires
		
		n = (!intensite);
		
		if ((largeur|n) > epsilon) {
			largeur= largeur - (largeur|n)*n;
		}	
		
		if ((hauteur|n) > epsilon) {
			hauteur= hauteur - (hauteur|n)*n;
		}
		
		if ((largeur|hauteur) > epsilon) { 
			 Vecteur a(!largeur);
			hauteur = hauteur - (hauteur|a)*a;
		}	
	}
	//methode 
	Vecteur getnormale();
	virtual Vent* copie() const override;
	virtual void agit_sur(ObjetMobile& obj) const override;
	bool influe (ObjetMobile const& obj) const;

	
	private:
	Vecteur origine;
	Vecteur n; //direction du vent 
	Vecteur largeur;
	Vecteur hauteur;
	double profondeur;
	};
