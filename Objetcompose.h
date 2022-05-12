#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "ChampsForces.h"
#include "ex_vecteur.h"
#include "obstacle.h"
class Objetcompose : public Dessinable {
	public:
	//constructeur 
	///probleme: mais alors dnas le constructeur ont y'auras un proble
	Objetcompose()=default;
	
	
	/// attention est ce que ca s'ecrit comme ca ????
	//Destructeur si la methode ajoute a (qui les detruit car elle a la priorité (c'est des unique ptr donc ils sont detruit)) n'a pas été utilié
	~Objetcompose() {
		
		//pour les objet mobiles:
		if (true
		 ){
			for (size_t i(0); i<Obj.size(); i++) {
				delete Obj[i];
				std::cout <<"les objet mobiles ont ete detruit"<<std::endl;}
			}
			
		//pour les obstacles:
		if ( true
		 ){
			for (size_t i(0); i<Obs.size(); i++) {
				delete Obs[i];
				std::cout <<"les obstacles ont ete detruit"<< std::endl;}
			}
			
		//pour les objetcompose
		if (true 
		 ){
			for (size_t i(0); i<Objcompo.size(); i++) {
				delete Objcompo[i];
				std::cout <<"les Objetcompose ont ete detruit"<<std::endl;}
			}
			
		 //pour les chammps de force
		if ( true
		 ){
			for (size_t i(0); i<champsf.size(); i++) {
				delete champsf[i];
				std::cout <<"les champs de force ont ete detruit"<<std::endl;}
			}
			
		 
		 };
		
	//methodes 
	 void ajoute_a(Systeme& S);

	
	protected:
	std::vector<ObjetMobile*> Obj;
	std::vector<Obstacle*> Obs;
	std::vector<Objetcompose*> Objcompo;
	std::vector<ChampForces*> champsf;
};


class Ventilateur :public Objetcompose {
	
	public: ///sol actuelle non satisfaisante: je veux qu'on me donne une brique et non pas un pointeur 
	Ventilateur (Brique bri, Vent v) : brique(), vent() {
		(*brique) = bri;
		(*vent) = v;
		Obs.push_back(brique);
		champsf.push_back(vent);
		
		//pour forcer que la normal a la brique dans la meme direction que la normal du vent (direction du vent)
		/*if ((largeur^normal).norme()> 0.001) {
		Vecteur a(!normal); //a prend la direction de normal
			largeur= largeur - (largeur*a)*a;
		}*/
		} ///je veux qu'on donne en paramettre une prique mais que je puisse faire un push_back d'un poiteur sur une brique, comment faire ?
	
	private:
	Brique* brique;
	Vent* vent;
};
