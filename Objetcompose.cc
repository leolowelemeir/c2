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
//-----------------------------------------------------------------------------------------------

//methode pour un ventilateur
Brique Ventilateur::getbrique() const {return *brique;}
Vent Ventilateur::getvent() const {return *vent;}

//void Ventilateur::dessine_sur(SupportADessin& support) { support.SupportADessin::dessine(*this); }

std::ostream& operator<<(std::ostream& sortie, Ventilateur const& ventilateur){
	cout <<"voici un ventilateur" <<endl;
	cout << ventilateur.getvent() << endl;
	cout << endl;
	cout << ventilateur.getbrique() << endl;
	}
