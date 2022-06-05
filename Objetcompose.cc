#include "Dessinable.h"
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "ChampsForces.h"
#include "Objetcompose.h"
#include "Systeme.h"
#include <memory>

using namespace std;

 void Objetcompose::ajoute_a(Systeme& S) {
	 a_ete_ajoute=true;
	 for (size_t i(0); i<Obj.size(); i++){
		 S.ajoute(Obj[i]);
		 }
		 
	 for (size_t i(0); i<Obs.size(); i++){
		 S.ajoute(Obs[i]);
		 }
		 	 
	 for (size_t i(0); i<champsf.size(); i++){
		 S.ajoute(champsf[i]);
		 }
	 }
	void Objetcompose::ajoute (ObjetMobile const& M) {
		ObjetMobile* ob(M.copie());
		Obj.push_back(ob);
	}
	void Objetcompose::ajoute (Obstacle const& A) {
		Obstacle* ob(A.copie());
		Obs.push_back(ob);
	}
	void Objetcompose::ajoute (ChampForces const& C) {
		ChampForces* ch(C.copie());
		champsf.push_back(ch);
	}
//-----------------------------------------------------------------------------------------------

//methode pour un ventilateur
Obstacle* Ventilateur::getbrique() const {
	return Obs[0];
	}
ChampForces* Ventilateur::getvent() const {return champsf[0];}

//void Ventilateur::dessine_sur(SupportADessin& support) { support.SupportADessin::dessine(*this); }

std::ostream& operator<<(std::ostream& sortie, Ventilateur const& ventilateur){
	cout <<"voici un ventilateur" <<endl;
	(ventilateur.getvent())->affiche();
	cout << endl;
	(ventilateur.getbrique())->affiche();
	return sortie;
	}
