#pragma once
#include <vector>
#include <memory>

#include "Dessinable.h"
#include "ObjetMobile.h"
#include "ChampsForces.h"
#include "ex_vecteur.h"

class Objetcompose : public Dessinable {
	public:
	//constructeur 
	///probleme: mais alors dnas le constructeur ont y'auras un proble
	Objetcompose(): vector<ObjetMobile*> Obj(), vector<Obstacle*> Obs, vector<Objetcompose*> Objcompo {}
	
	
	/// attention est ce que ca s'ecrit comme ca ????
	//Destructeur si la methode ajoute a (qui les detruit car elle a la priorité (c'est des unique ptr donc ils sont detruit)) n'a pas été utilié
	~Objetcompose() {
		
		//pour les objet mobiles:
		if (//comment demander si une methode a ete utilisé ????
		 ){
			for (size_t i(0); i<Obj.size(); i++) {
				Obj=delete;
				cout <<"les objet mobiles ont ete detruit"<<endl;}
			}
			
		//pour les obstacles:
		if (//comment demander si une methode a ete utilisé ????
		 ){
			for (size_t i(0); i<Obs.size(); i++) {
				Obj=delete;
				cout <<"les obstacles ont ete detruit"<<endl;}
			}
			
		//pour les objetcompose
		if (//comment demander si une methode a ete utilisé ????
		 ){
			for (size_t i(0); i<Objcompo.size(); i++) {
				Obj=delete;
				cout <<"les Objetcompose ont ete detruit"<<endl;}
			}
			
		 //pour les chammps de force
		if (//comment demander si une methode a ete utilisé ????
		 ){
			for (size_t i(0); i<champsf.size(); i++) {
				Obj=delete;
				cout <<"les champs de force ont ete detruit"<<endl;}
			}
			
		 
		 };
		
	//methodes 
	 virtual void ajoute_a(Systeme S) override;

	
	private:
	vector<ObjetMobile*> Obj;
	vector<Obstacle*> Obs;
	vector<Objetcompose*> Objcompo;
	vector<ChampForces*> champsf;
};

class Ventilateur :public Objetcompose {
	
	public: ///sol actuelle non satisfaisante: je veux qu'on me donne une brique et non pas un pointeur 
	Ventilateur (Brique* bri, Vent* v) : brique(bri), vent(v) {
		Obs.puch_back(brique);
		champsf.push_back(vent);
		
		//pour forcer que la normal a la brique dans la meme direction que la normal du vent (direction du vent)
		if (not ((largeur^normal).norme()==0)) {
		Vecteur a(!normal); //a prend la direction de normal
			largeur= largeur - (largeur*a)*a;
		}
		} ///je veux qu'on donne en paramettre une prique mais que je puisse faire un push_back d'un poiteur sur une brique, comment faire ?
	
	private:
	Brique* brique;
	Vent* vent;
};
