#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "ex_vecteur.h"
#include "constantes.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Systeme.h"
#include "ChampsForces.h"
#include "constantes.h"
#include <map>

class ObjetMobile: public Dessinable {
    protected:
        //attributs
        Vecteur P;
        Vecteur Pd;
        double masse;
        Vecteur force;
        double rayon;
        double temps;
        int degl;
        double alpha; //coefficient de restitution choc 
        double frottement_choc; // le coefficient μ de frottement entre corps pour chocs
        std::map<int, bool> danschamp; //Ce booléen correspond à l'information si oui ou non l'ObjetMobile est actuellement influencé par un ChampForce


      public:
        //Constructeur
        ObjetMobile (Vecteur param, Vecteur derparam, double m,  Vecteur F,double r, int deg_ , double alp, double fchoc)
            : P (param), Pd (derparam), masse (m), force (F), rayon (r), degl(deg_), alpha(alp), frottement_choc(fchoc) {
				//On place comme force par défaut le poids et la force d'Archimède pour tous les ObjetsMobiles
				 Vecteur f( (m - (4*M_PI*rho_air*r*r*r)/3)*g );
				force= f+F;	
			}
            
       //destructeur
       virtual ~ObjetMobile() {}
            
      //  virtual double distance(const ObjetMobile& obj) = 0; // calculer distance entre objets
		bool getdanschamp(size_t i);
		void setdanschamp(size_t i, bool a);


        // Methodes dans balle a l origine
    
        virtual Vecteur position () const = 0 ;
        virtual Vecteur vitesse() const = 0 ;
        virtual void setvitesse(Vecteur const& a) = 0 ;
        virtual Vecteur evolution() const = 0;
        void agit_sur(ObjetMobile& obj);
//      virtual void dessine_sur(SupportADessin&) =0;
        virtual Vecteur point_plus_proche (const ObjetMobile& obj) = 0; //calculer le point le plus proche

        double masse_vol() const;
        void ajoute_force(Vecteur  df);    ///const& ?

        Vecteur getP() const;
        Vecteur getPd() const;
        Vecteur getforce() const;
		double getalpha() const;
		double getfrottement_choc() const;
		double getmasse() const;
        double getrayon() const;
        double get_temps () const;
        void setP (Vecteur nouv_pos);
        void setPd (Vecteur nouv_der);
        void setforce(Vecteur nouv_force);

		virtual void affiche() const=0;

		//pour ajouter des objets au systeme
		void ajoute_a(Systeme& S);

        //pour la covariance 
   virtual ObjetMobile* copie() const = 0;
   
    
};




class Balle : public ObjetMobile {
    public:
    // les constructeurs
    Balle (Vecteur pos, Vecteur vit,  double masse, Vecteur F, double r=0.1, int deg_=3, double alp=1, double fchoc=0)
    : ObjetMobile (pos,vit, masse, F, r, deg_,alp,fchoc) {}
    
    
    
    //les methodes 
    virtual Vecteur position() const override;
    virtual Vecteur vitesse() const override;
 
    void setposition(Vecteur const& a);
    
    Vecteur getvitesse() const;
    virtual void setvitesse(Vecteur const& a) override;
    
    Vecteur evolution() const override;
    virtual Vecteur point_plus_proche(const ObjetMobile& M) override;
	
	virtual void affiche() const override;

    ///virtual void dessine_sur(SupportADessin& support) override;
    
	//methode pour la covariance
    virtual Balle* copie() const override;

    };







class Pendule : public ObjetMobile {
    public:
    //Constructeur
    Pendule (Vecteur param, Vecteur derparam, double m, Vecteur F, double r, Vecteur Or, double l, Vecteur dir, double alp=1, double fchoc=0, int deg_=1, double fr = 0.0)
    : ObjetMobile ( param, derparam, m, F, r, deg_, alp, fchoc), origine (Or), longueur (l),  d (dir), frottement(fr)
    {	std::cout << " longueur " << l << std::endl;
		if (l < epsilon ) {	//un pendule ne peut pas avoir une longueur nulle
			longueur = 0.1;
			std::cout << "La longueur donnée est nulle ou négative, on la met donc par défaut à 0.1 ." <<std::endl;
			}
		
		Vecteur direction(d);

		if((d|g) > epsilon) {
			Vecteur y(0,1.0,0);
            direction -=  (!((d|y)*y));                // Le vecteur d n'a pas de composante en y (il est orthogonal à l'axe Y), on supprime donc la deuxieme composante de dir.

            		//On prend le vecteur directeur pour que la norme de d n'influence pas les calculs, on a juste besoin de la direction du vecteur
            } 
	d = (!direction);

    }
    
    Pendule (Pendule const&) = default;
    /* Le theta est la seule donnée de position necessaire pour le pendule, etant donne que la longueur et l'origine sont fixes.
   
    Il y a donc un seul degre de liberte. On utilise donc P de dimension 1 (degl = 1) pour decrire la position du pendule et Pd pour sa vitesse angulaire
    */
    
    Vecteur Madirection () const;
    virtual Vecteur position() const override;
    virtual Vecteur vitesse() const override;
    virtual void setvitesse(Vecteur const& a) override;
	//Vecteur dir() const;

    
    // methodes get, necessaires pour l operateur d affichage << et pour la fonction agir_sur
    Vecteur getP() const;
    Vecteur getorigine() const;
    //double getfrottement() const;
	double getlongueur() const ;
	
	virtual Vecteur evolution() const override;
	
	virtual Vecteur point_plus_proche(const ObjetMobile& M) override;
    ///virtual void dessine_sur(SupportADessin& support) override;
	virtual void affiche() const override;

    //pour la covariance
    virtual Pendule* copie() const override;
	
	

	
    private:
    //attributs     
    Vecteur origine;
    double longueur;
    Vecteur d;	//d correspond à un vecteur orthogonal à la verticale pour déterminer le plan dans lequel le pendule est contraint
    double frottement;
};


std::ostream& operator<<(std::ostream& sortie, Balle const& b);
std::ostream& operator<<(std::ostream& sortie, Pendule const& p);








