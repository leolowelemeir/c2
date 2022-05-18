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
