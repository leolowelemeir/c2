#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include "SupportADessin.h"
#include "Systeme.h"
#include "ChampsForces.h"
using namespace std;


// Ce document sert a definir les methodes propres a tous les objets mobiles de facon generale ainsi que ChampForce


//ObjetMobile
//Methodes
 double ObjetMobile::masse_vol() const {return (masse/((4*M_PI)/3)*carre(rayon)*rayon); }
    
 void ObjetMobile::ajoute_force(Vecteur  df){    //const&
        force+=df;}

double ObjetMobile::getmasse() const {return masse;}
double ObjetMobile::getrayon() const {return rayon;}
Vecteur ObjetMobile::getPd() const{return Pd;}
Vecteur ObjetMobile::getP() const {return P;};
Vecteur ObjetMobile::getforce() const{return force;}
double ObjetMobile::get_temps() const {return temps;}
double ObjetMobile::getalpha() const {return alpha;}
double ObjetMobile::getfrottement_choc() const {return frottement_choc;}


void ObjetMobile::setP (Vecteur nouv_pos){ P=nouv_pos; }
void ObjetMobile::setPd (Vecteur nouv_der){ Pd=nouv_der;}
void ObjetMobile::setforce(Vecteur nouv_force){force=nouv_force;}




void ObjetMobile::ajoute_a(Systeme& S){
	ObjetMobile* M;
	S.ajoute(M);
	cout << "un objet mobile est ajouté au systeme"<<endl;
	 }

///void ObjetMobile::dessine_sur(SupportADessin& support) { support.SupportADessin::dessine(*this); }
  

//Operateur
ostream& operator<<(ostream& sortie,const ObjetMobile& M){
    sortie << "L'objet mobile est constitué de " << endl;
    sortie << M.position();
    sortie << "   #position"<<endl;
    sortie << M.getPd();
    sortie << "   #vitesse" <<endl;
    sortie << M.getmasse() << "  #masse" << endl;
    sortie << M.masse_vol();
    sortie << "   #masse volumique"<<endl;
    sortie << M.getrayon();
    sortie << "   #rayon" << endl;
    sortie << M.getforce();
    sortie <<"  # force" <<endl;
	sortie << endl;
    return sortie;
    }


//_______________________________________________________________________________________________

//Balle
    //les methodes : Balle
    Vecteur Balle::position() const {return P;}

    void Balle::setposition (Vecteur a) { P = a;}
        
    Vecteur Balle::getvitesse() const {return Pd;}
    void Balle::setvitesse (Vecteur a) { Pd = a;}
    
    Vecteur Balle::evolution() {
			Vecteur Pdd; //derivée seconde de la position 
			Pdd=force*(1/masse);
			return Pdd;
	}
	
	Vecteur Balle::point_plus_proche(const ObjetMobile& M){
		Vecteur point_proche(M.position()-P);
		return point_proche;
	}
	
	void Balle::agit_sur(ObjetMobile& obj){  
		//soit l'objet 2 celui passé en parametre
		
		//verification qu'il y ai bien un choc 
		if (((P-obj.position()).norme())<=(rayon-obj.getrayon())) {
			
			//mise à jour les forces s’exerçant sur les objets
            Vecteur normal(!(P-obj.position()));//vecteur (unitaire) normal au point de choc
			
			double Fn1 (normal|force);
			Vecteur a(obj.getforce());
			double Fn2(a|normal);

			if (Fn1<0) {
				force-=(Fn1*normal); 
                obj.setforce(obj.getforce()+(Fn1*normal));
			}
			
			if (Fn2>0) {
				force+=(Fn2*normal); 
                obj.setforce(obj.getforce()-(Fn2*normal));
			}
			
			//valeur neccesaire au calcul de la vitesse relative du point de contact
			double alpha_general(alpha+obj.getalpha());
			double lambda (alpha_general*(obj.getmasse()/(masse+obj.getmasse())));
			double frottement_general(frottement_choc+obj.getfrottement_choc());
			
			//calcul vitesse relative du point de contact
			double v_etoile((obj.getPd()-Pd)|normal);
			Vecteur v_contact((Pd-obj.getPd())+(v_etoile*normal));
            Vecteur delta_v;
            double condition(7*frottement_general*(1+alpha_general)*v_etoile);
            if (condition>=2*v_contact.norme()){
                delta_v=(lambda*v_etoile*normal-((2*obj.getmasse()/(7*(masse+obj.getmasse())))*v_contact));
			}else if (v_contact.norme()!=0){
                    delta_v=lambda*v_etoile*(normal-frottement_general*(!v_contact));}
			
			//mise à jour des vitesses
			Pd=Pd+delta_v;
			setPd(getPd()+(masse/getmasse())*delta_v);
             
             //affichage
             cout <<"calcul:"<<endl;
             cout<<"n= "<<normal<<endl;
             cout<<"lambda :"<<	lambda<<endl;
             cout<<"Fn1"<<Fn1<<endl;
             cout<<"Fn2"<<Fn2<<endl;
             cout <<"vstar= "<<v_etoile<<endl;
             cout <<"vc= "<<v_contact<<endl;
             cout <<"7 mu (1+alpha) vstar"<< condition<<endl;
             cout <<"2*vc.norme()"<<2*v_contact.norme()<<endl;
             cout <<"dv"<<delta_v<<endl;
             
             cout<<endl;
             cout <<"apres choc : :"<<endl;
             cout<<"vitesse balle1= "<<Pd <<endl;
             cout << "vitesse balle2= "<< obj.getPd() <<endl;
             cout <<"force balle1 "<< force<<endl;
             cout<<"force balle2 "<<obj.getforce()<<endl;
             
             
            
		
	}
}                           

	

///void Balle::dessine_sur(SupportADessin& support) { support.dessine(*this); }



Balle* Balle::copie() const { //pour pouvoir utiliser la methode copieobjet
        return (new Balle(*this));}



	
	
// Les operateurs d affichage
ostream& operator<<(ostream& sortie,const Balle& M){
    sortie << "la balle est constituée de :" << endl;
    sortie << M.position();
    sortie << "  #position"<<endl;
    sortie << M.getPd();
    sortie << "  #vitesse" <<endl;
    sortie << M.getmasse();
    sortie << "  #masse" << endl;
    sortie << M.masse_vol();
    sortie << "  #masse volumique "<<endl;
    sortie << M.getrayon();
    sortie << "  #rayon" << endl;
    sortie << M.getforce();
    sortie <<" #force" <<endl;
    sortie << endl;
    return sortie;
    }
//____________________________________________________________
//Pendule

//Methodes
Vecteur Pendule::getP() const{return P;}
Vecteur Pendule::getorigine()const {return origine;}
double Pendule::getfrottement() const {return frottement;}
double Pendule::getlongueur() const {return longueur;}

Vecteur Pendule::Madirection() const {
    Vecteur dir (P);
    return !dir;}
    
Vecteur Pendule::position() const { //direction de l'axe
    Vecteur laposition (longueur * sin(P.getvecteur()[0]), -(longueur*cos(P.getvecteur()[0])), 0.0);
    laposition += origine;
    return laposition;
    }

Vecteur Pendule::point_plus_proche(const ObjetMobile& M){
		Vecteur point_proche(M.position()-position());
		return point_proche;
	}


Vecteur Pendule::evolution() {
	Vecteur Pdd;
	Vecteur sin_P (sin (P.getvecteur()[0]));
	Vecteur cos_P (cos (P.getvecteur()[0]));
	
	//vecteur pour les deux degres de liberte (ils sont sur le bas coté mais on les aime bien quand meme)
	Vecteur bas(0.0,1.0,0.0);
	Vecteur cote(1.0,0.0,0.0);
	
	Pdd=1/(masse*longueur)*(cos_P*force*cote-sin_P*force*bas-(b/longueur)*Pd); 
	return  Pdd; } 

void Pendule::agit_sur(ObjetMobile& obj){
    cout << "A FINIR" << endl;}                                             ///A FINIR

/// void Pendule::dessine_sur(SupportADessin& support){ support.dessine(*this); }

Pendule* Pendule::copie() const { //pour pouvoir utiliser la methode copieobjet
        return (new Pendule(*this));}





//operateur
ostream& operator<<(ostream& sortie,const Pendule& p){
    sortie << "Le pendule a pour caractéristiques: " << endl;
    sortie << p.getmasse() << "  #masse du pendule" << endl;
    sortie << p.getlongueur();
    sortie << "   #longueur du pendule" << endl;
    sortie << p.getorigine();
    sortie << "  #origine du pendule" << endl;
    sortie << p.position() << "  #position au bout du pendule" << endl;
    sortie << p.Madirection() << "  #direction du pendule" << endl;
    sortie << p.getP();
    sortie << "   #theta du pendule"<<endl;
    sortie << p.getPd();
    sortie << "   #theta point du pendule" <<endl;
    sortie << p.getforce();
    sortie <<"  #force appliquée sur le pendule" <<endl;
    sortie << p.getfrottement();
    sortie << "  #frottement du pendule" << endl;
    sortie << endl;
    return sortie;
  }








