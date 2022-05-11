#pragma once
#include <iostream>
#include <vector>
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"
#include "Dessinable.h"

/*struct Face{
    array<int,6> num{origine,origine,origine,origine+longueur*a,origine+largeur*a;
    Vecteur coincoin;
    Vecteur normal;
    double l;
    Vecteur ELg;
    double largeur;
    Vecteur ELg} */
    
class Obstacle : public Dessinable {
    public:    
        // Constructeur
    Obstacle(Vecteur ori)
     : obs_origine(ori) {}
    
    
    Vecteur getobs_origine() const;
   
    
    virtual Vecteur point_plus_proche(const ObjetMobile& M) = 0;
    double distance(const ObjetMobile&);
	virtual void agit_sur(ObjetMobile& obj);

    ///virtual void dessine_sur(SupportADessin& support) override;
	
	//pour la covariance
    virtual Obstacle* copie() const = 0;

	
	
    protected:
    Vecteur obs_origine;
    
};



class Plan :public Obstacle {
    public:
    //constructeur 
    Plan (Vecteur ori, Vecteur di1, Vecteur di2, Vecteur p)
    : Obstacle(ori), dir1(di1), dir2(di2), point(p){}
    
    Vecteur point_plus_proche(const ObjetMobile& M);
    Vecteur n() const;
    
    ///virtual void dessine_sur(SupportADessin& support) override;
    
    //pour la covariance
    virtual Plan* copie() const override;

	//pour ajouter au systeme un objet
     virtual void ajoute_a(Systeme& S) override;

    private:
    Vecteur dir1;
    Vecteur dir2;
    Vecteur point;
    
};


class Brique : public Obstacle {
	public:
    //constructeur
    Brique (Vecteur ori, Vecteur lon, Vecteur lar, double haut) : Obstacle(ori), longueur(lon), largeur(lar), hauteur(haut) {
        Vecteur a(!longueur); //a prend seulement la direction de longueur
        Vecteur b(!largeur); //b prend seulement la direction de largeur
        if(not ((b|a) == 0)) {
            largeur = largeur - (largeur*a)*a; /// peut etre a verifier avec la formule
            }
        }                                   
        
        //methode
    Vecteur getlongueur() const;
    Vecteur getlargeur() const;
    double gethauteur() const;
   
    Vecteur point_plus_proche(const ObjetMobile& M) override;
    Vecteur n() const;
	
///	virtual void dessine_sur(SupportADessin& support) override;

	//pour la covariance
    virtual Brique* copie() const override;


	//pour ajouter au systeme un objet
     virtual void ajoute_a(Systeme& S) override;
  
    
    private:
    // de plus il herite d'une origine
    Vecteur longueur;
    Vecteur largeur;
    double hauteur;
};
std::ostream& operator<<(std::ostream& sortie,const Obstacle& M);
std::ostream& operator<<(std::ostream& sortie,const Plan& M);
std::ostream& operator<<(std::ostream& sortie,const Brique& b);

