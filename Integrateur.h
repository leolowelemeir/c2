#pragma once

#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"

/// Deux choix: le premier est le plus logique mais le plus vide et inutile
///dans le sens où si c est juste pour une methode ca sert a rien d en faire une classe
///Le deuxieme place les integrateurs comme sous classe des objets mobiles ce qui n a aucun sens
///mais est plus esthetique et permet une vraie construction de classe avec attributs


class Integrateur {
// Represente un integrateur quelconque
	public:
	// Constructeur
	Integrateur (double t_ = 0.1)
	 : dt(t_) {}
	
	
	virtual void integre(ObjetMobile& M);
	
	protected:
	double dt; // laps de temps pour integrer
	
	

};



class IntegrateurEulerCromer : public Integrateur {
		public:

	IntegrateurEulerCromer (double t =0.1)
	: Integrateur (t) {}
	
	virtual void integre(ObjetMobile& M) override;
	
	
	
	
};
void integre(Obstacle& Ob);


/*class IntegrateurNewmark : public Integrateur {
	public:
	virtual void integre(ObjetMobile& M) override;

	
	
	private:
	Vecteur q;
	Vecteur r;
	Vecteur s;
	
	};

class Integrateur : public ObjetMobile {
// Represente un integrateur quelconque
	public:
	
	// Constructeur
	Integrateur (Vecteur param, Vecteur derparam, double t_, Vecteur F, double r, double rho, int deg_, double delta_t = 1)
	: ObjetMobile(param, derparam, t_, F, r, rho, deg_), dt (delta_t) {}
	
	protected:
	
	virtual void integre(){
		P =  ( P + (dt*Pd) );
		Pd = ( Pd + (dt*evolution() ) ); 
	}
	
	private:
	double dt;	// laps de temps pour integrer

};

*/
