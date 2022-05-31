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
        
      public:
        //Constructeur
        ObjetMobile (Vecteur param, Vecteur derparam, double m,  Vecteur F,double r, double t, int deg_ , double alp, double fchoc)
            : P (param), Pd (derparam), masse (m), force (F), rayon (r), temps (t), degl(deg_), alpha(alp), frottement_choc(fchoc) {
				//On place comme force par défaut le poids et la force d'Archimède pour tous les ObjetsMobiles
				 Vecteur f( (m - (4*M_PI*rho_air*r*r*r)/3)*g );
				force = f+F;
				
				///
				danschamp = false;
			}
            
       //destructeur
       virtual ~ObjetMobile() {}
            
      //  virtual double distance(const ObjetMobile& obj) = 0; // calculer distance entre objets
        
        ///Cet attribut est placé en public car il n'a besoin d'aucune encapsulation. il permet juste de déterminer si l'objet est influencé par un ChampForce
        bool danschamp;

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
		double getmasse() const;
        double getrayon() const;
        double get_temps () const;
        double getfrottement_choc() const;
        void setP (Vecteur nouv_pos);
        void setPd (Vecteur nouv_der);
        void setforce(Vecteur nouv_force);
		virtual void affiche()=0;

		//pour ajouter des objets au systeme
		void ajoute_a(Systeme& S);

        //pour la covariance 
   virtual ObjetMobile* copie() const = 0;
   
    
};




class Balle : public ObjetMobile {
    public:
    // les constructeurs
    Balle (Vecteur pos, Vecteur vit,  double masse, Vecteur F, double r=1.0, double t=0.0,  int deg_=3, double alp=1, double fchoc=0)
    : ObjetMobile (pos,vit, masse, F, r, t, deg_,alp,fchoc) {}
    
    
    
    //les methodes 
    virtual Vecteur position() const override;
    virtual Vecteur vitesse() const override;
 
    void setposition(Vecteur const& a);
    
    Vecteur getvitesse() const;
    virtual void setvitesse(Vecteur const& a) override;
    
    Vecteur evolution() const override;
    virtual Vecteur point_plus_proche(const ObjetMobile& M) override;
	
	virtual void affiche() override;

    ///virtual void dessine_sur(SupportADessin& support) override;
    
	//methode pour la covariance
    virtual Balle* copie() const override;

    };







class Pendule : public ObjetMobile {
    public:
    //Constructeur
    Pendule (Vecteur param, Vecteur derparam, double m, Vecteur F, double r, Vecteur Or, double l, Vecteur dir, double alp=1, double fchoc=0, double t = 0, int deg_=1, double fr = 0.0)
    : ObjetMobile ( param, derparam, m, F, r, t, deg_, alp, fchoc), origine (Or), longueur (l),  d (dir), frottement(fr)
    {/*ajoute_force(m*g);*/ ///Cette information permettrait de mettre par defaut l action de la gravite sur le pendule
		//On n'accepte l'angle theta que si il est inférieur à pi/2, par souci de concetption pour la méthode evolution()
		if (abs (param.getcomposante(0)) - M_PI/2 >= epsilon){
			if (param.getcomposante(0) > epsilon){
				param.set_coord(0, ( M_PI/2 - epsilon ) );
			}else{
				param.set_coord(0, (-M_PI/2 + epsilon) );
			}
		}
		
		d = (!dir);
    }
    
    Pendule (Pendule const&) = default;
    /* Le theta est la seule donnée de position necessaire pour le pendule, etant donne que la longueur et l'origine sont fixes.
   
    Il y a donc un seul degre de liberte. On utilise donc P de dimension 1 (degl = 1) pour decrire la position du pendule et Pd pour sa vitesse angulaire
    */
    
    Vecteur Madirection () const;
    virtual Vecteur position() const override;
    virtual Vecteur vitesse() const override;
    virtual void setvitesse(Vecteur const& a) override;
	Vecteur dir() const;

    
    // methodes get, necessaires pour l operateur d affichage << et pour la fonction agir_sur
    Vecteur getP() const;
    Vecteur getorigine() const;
    double getfrottement() const;
	double getlongueur() const ;
	
	virtual Vecteur evolution() const override;
	
	virtual Vecteur point_plus_proche(const ObjetMobile& M) override;
    ///virtual void dessine_sur(SupportADessin& support) override;
	virtual void affiche() override;

    //pour la covariance
    virtual Pendule* copie() const override;
	
	

	
    private:
    //attributs     
    Vecteur origine;
    double longueur;
    Vecteur d;	//d correspond à un vecteur orthogonal à la verticale pour déterminer le plan dans lequel le pendule est contraint
    double frottement;
};











