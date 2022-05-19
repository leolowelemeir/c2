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
		if (a_ete_ajoute){
			for (size_t i(0); i<Obj.size(); i++) {
				delete Obj[i];
				std::cout <<"les objet mobiles ont ete detruit"<<std::endl;}
			}
			
		//pour les obstacles:
		if (a_ete_ajoute){
			for (size_t i(0); i<Obs.size(); i++) {
				delete Obs[i];
				std::cout <<"les obstacles ont ete detruit"<< std::endl;}
			}
			
		/*//pour les objetcompose
		if (true 
		 ){
			for (size_t i(0); i<Objcompo.size(); i++) {
				delete Objcompo[i];
				std::cout <<"les Objetcompose ont ete detruit"<<std::endl;}
			}*/
			
		 //pour les chammps de force
		if (a_ete_ajoute){
			for (size_t i(0); i<champsf.size(); i++) {
				delete champsf[i];
				std::cout <<"les champs de force ont ete detruit"<<std::endl;}
			}
			
		 
		 };
		
	//methodes 
	void ajoute_a(Systeme& S);
	//virtual void dessine_sur (SupportADessin& )	
	
	protected:
	std::vector<ObjetMobile*> Obj;
	std::vector<Obstacle*> Obs;
	//std::vector<Objetcompose*> Objcompo;
	std::vector<ChampForces*> champsf;
	//changement dans la conceptio: si un objett composé est composé d'objets composee chaqu'un des elements de l'objet composé sera rajouter au tableau correpondant
	bool a_ete_ajoute; //pour savoir si l'objet composé a été ajouter au systeme 
};


class Ventilateur :public Objetcompose  {
	
	public:
	Ventilateur (Brique bri, Vent v) : brique(), vent()  {
		(*brique) = bri;
		(*vent) = v;
		Obs.push_back(brique);
		champsf.push_back(vent);
		/*
		//pour forcer que la normale a la brique dans la meme direction que la normale du vent (direction du vent)
		if ((largeur^normal).norme()> 0.001) {
		Vecteur a(!normal); //a prend la direction de normal
			largeur= largeur - (largeur*a)*a;
		}*/
		} 

	// virtual void dessine_sur(SupportADessin& support) override;

	private:
	Brique* brique;
	Vent* vent;
};
