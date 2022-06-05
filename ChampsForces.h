#pragma once
#include "ex_vecteur.h"
#include "Systeme.h"
#include "constantes.h"
#include <iostream>

class ObjetMobile;
class Systeme;

class ChampForces {
    public:

	ChampForces (Vecteur F)
		: intensite (F) {
			numero = compteur; // l'explication de cette partie est dans les attributs
			++compteur;

			}
	
	ChampForces (ChampForces const& C) {numero = compteur;  ++ compteur; } // si on fait une copie on crée quand meme bien un champs de force donc le compteur doit augmenter (voir explication dans attributs)
	//Destructeur 
	virtual ~ChampForces() {}
	
	//methodes 
	void ajoute_a(Systeme& S); //pour ajouter un champs de force a un systeme 
    virtual void agit_sur(ObjetMobile& obj) const ; //
    Vecteur getintensite() const;
    virtual ChampForces* copie() const; //utile pour pouvoir faire des copies profondes polymorphiques
    int getnumero() const;
    virtual void affiche() const;

    protected:
    //les attributs
    Vecteur intensite;
    static int compteur;	//le compteur permet de donner un numéro à chaque instance ChampForce crée pour se retrouver dans la map de danschamp et déterminer quel champ influence ou non l'objet
    int numero;
};




class Vent : public ChampForces {
	public:
	Vent (Vecteur inten,Vecteur orin, Vecteur l, Vecteur hau, double pro)
	: ChampForces(inten), origine(orin), largeur(l), hauteur(hau), profondeur(pro) { 
		
		//au cas ou les vecteurs ne soient pas perpendiculaires, on les rend perpendiculaires entre eux (ex: largeur doit etre perpendiculaire a n)
		
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
	Vecteur getnormale(); // renvoie la direction du vent
	virtual Vent* copie() const override; //utile pour pouvoir faire des copies profondes polymorphiques
	virtual void agit_sur(ObjetMobile& obj) const override; //si il y a besoin on rajoute l'intensite du vent aux forces de l'objet (on a par exemple pas besoin de rajouter deux fois un vent si l'objet s'est juste deplace dans le vent) 
	bool influe (ObjetMobile const& obj) const; //pour verifier si l'objet est dans le champs
	virtual void affiche() const override; 

	
	//pour un vent l'intensite peut etre associe a la vitesse du vent Vo
	private:
	Vecteur origine;
	Vecteur n; //direction du vent 
	Vecteur largeur;
	Vecteur hauteur;
	double profondeur;
	};
	
std::ostream& operator<<(std::ostream& sortie, Vent const& vent); // utilise les fonctions affiche() et on a pas mis que les fonctions affiche() pour le graphisme 
