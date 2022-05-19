#include <iostream>
#include <array>
#include <vector>
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "obstacle.h"
#include "SupportADessin.h"
#include "Systeme.h"

using namespace std;


//methodes obstacle
	Vecteur Obstacle::getobs_origine() const { return obs_origine;}


    double Obstacle::distance(const ObjetMobile& M){
        Vecteur dist (point_plus_proche(M) - M.getP());
        double distance ( dist.norme() - M.getrayon());
        return distance;
    }
    
    void Obstacle::agit_sur(ObjetMobile& obj){
		
		//verification qu'il y ai bien un choc 
		if (distance(obj)<=(obj.getrayon())) {
			
			//mise à jour les forces s’exerçant sur l'objet
            Vecteur normal(!(obj.position()-point_plus_proche(obj)));//vecteur (unitaire) normal au point de choc

			Vecteur a(obj.getforce());
			double Fn1(a|normal);
			
			if (Fn1<0) {
				obj.getforce()-=(Fn1*normal); 
			} ///pourquoi on ne fait pas quans Fn1 est positif ?
			
			//calcul vitesse relative du point de contact
			double v_etoile(-obj.getPd()|normal);
			Vecteur v_contact((obj.getPd())+(v_etoile*normal));
            Vecteur delta_v;
            double condition(7*obj.getfrottement_choc()*(1+obj.getalpha())*v_etoile);
            if (condition>=2*v_contact.norme()){
				delta_v=(1+obj.getalpha())*v_etoile*normal-(2/7)*v_contact;
			} 
			else{
                delta_v=(1+obj.getalpha())*v_etoile*(normal-obj.getfrottement_choc()*(!v_contact));
			}
			
		obj.setPd(obj.getPd()+delta_v);
		
		//affichage
		cout <<"calcul:"<<endl;
             
             cout <<"vstar= "<<v_etoile<<endl;
             cout <<"vc= "<<v_contact<<endl;
             cout <<"7 mu (1+alpha) vstar"<< condition<<endl;
             cout <<"dv"<<delta_v<<endl;
             
             cout<<endl;
             cout <<"apres rebond au sol : :"<<endl;
             cout << "vitesse balle= "<< obj.getPd() <<endl;
             cout<<"force balle "<<obj.getforce()<<endl;
		
		
		}
   }

void Obstacle::ajoute_a(Systeme& S){
	S.ajoute(this);
	cout << "une brique est ajouté au systeme"<<endl;
	 }



//__________________________________________________________________________________________________________________________
// Plan
	//methodes Plan
	
	// On définit la normale au plan
 Vecteur Plan::n() const {
     Vecteur n (dir1);
     n = (n^dir2);
     return n;
 }


//on redefinit la methode de point le plus proche
    Vecteur Plan::point_plus_proche(const ObjetMobile& M){
        Vecteur point2 (obs_origine-M.getP());
																///juste pour savoir si c'est bon et apres on peut supprimer
        /*point2*n(); 
        point2*n();
        point2+=M.getP();*/ //modifier en:
        
        point2=point2|dir1; //on cherche la projection de point2 sur le plan: 
        point2+=point2|dir2; //on prend la composante selon dir1 de point2, puis celle selon dir2 et on les somme
        
    return point2;
    }
    
    
Plan* Plan::copie() const { //pour pouvoir utiliser la methode copieobjet
        return (new Plan(*this));}

	 
   //Operateur
void Plan::affiche(){
	cout << "Un plan est constitué de: " << endl;
		
		cout << obs_origine << "  #origine" << endl;
		for (size_t i(0); i< n().taille();i++){
			cout << n().getcomposante(i) << " ";}
		cout << "  #normale" << endl;
		cout << endl;
}


//void Plan::dessine_sur(SupportADessin& support) override { support.dessine(*this); }

    
//______________________________________________________________________________________________________________________________________________
//Brique    
    
    /// a retirer si ca marche avec la methode de plan
    Vecteur Brique::n() const {
     Vecteur n (longueur);
     n = (n^largeur);
     return n;
 }


    Vecteur Brique::point_plus_proche(const ObjetMobile& M){
        // faire le point le plus proche de chque face puis garder la plus petite distance
         int meilleur_distance(-1); //il ne peut pas avoir de distance negative donc ca permet de savoir dans le programme si on parle d'une distance calculer ou de l'initialisation
         Vecteur point_proche;
         Vecteur a(!longueur); //a donne la direction de la longueur
         Vecteur b(!largeur); //b donne la direction de la largeur
         array<array<Vecteur,6>,6> tableau ({obs_origine,n(),longueur,a,largeur,b,
                                obs_origine,-b,hauteur,-n(),longueur,a,
                                obs_origine,-a,largeur,b,hauteur,-n(),
                                obs_origine+longueur*a,a,hauteur,-n(),largeur,b,
                                obs_origine+largeur*b,b,longueur,a,hauteur,-n(),
                                obs_origine+hauteur*b,-n(),largeur,b,longueur,a});
                            
        //l'idee est de faire une boucle pour trouver quelle est la face la plus proche
        for (int i(1);i<6; i++){
            
            //calcule pour un plan infini
            Vecteur point2 (tableau[i][1]-M.getP());
            point2*tableau[i][2];
            point2*tableau[i][2];
            point2+=M.getP();
            
            //calcul des coordonnées:
            double xLg( (point2-tableau[i][1]) | tableau[i][4] ); //Pour faire le projeté sur la longueur
            double xlar ( (point2-tableau[i][1]) | tableau[i][6] );//Pour faire le projeté sur la largeur
            
            if (xLg>tableau[i][3].norme()){ //si xLg >L alors on modifie pour retrouver le point le plus proche
                point2-=(xLg-tableau[i][3].norme())*tableau[i][4];
                }
            else if (xlar>tableau[i][5].norme()){point2-=(xlar-tableau[i][5].norme()) * tableau[i][6];}
            else if (xLg<0){point2-=xLg;}
            else if (xlar<0) {point2-=xlar;}
            
            //pour savoir quelle est la meilleur distance
            if (meilleur_distance==-1) {
                meilleur_distance=(point2-M.getP()).norme();
                point_proche=point2;}
            else if (meilleur_distance>(point2-M.getP()).norme()) {
                meilleur_distance=(point2-M.getP()).norme();
                point_proche=point2;}
            
        }
        return meilleur_distance;
        }

Vecteur Brique::getlongueur() const { return longueur;}
Vecteur Brique::getlargeur() const {return largeur;}
double Brique::gethauteur() const {return hauteur;}


Brique* Brique::copie() const { 
        return (new Brique(*this));}



//Operateur
void Brique::affiche(){
	cout <<"Une brique constituée de: " << endl;
		for (size_t i(0); i< getobs_origine().taille();i++){
			cout << obs_origine.getcomposante(i) << "  ";}
	cout << "  #origine"<< endl;
		
		for (size_t i(0); i< getlongueur().taille();i++){
			cout << longueur.getcomposante(i) << "  ";}
		cout << "  #longueur"      << endl;
		
		for (size_t i(0); i < getlargeur().taille();i++){
		cout << getlargeur().getcomposante(i) << "  ";}
		cout << "  #largeur" << endl;

		cout << gethauteur() << "  #hauteur" << endl;
		cout << endl;
	}
	


///void Brique::dessine_sur(SupportADessin& support) { support.dessine(*this); }
