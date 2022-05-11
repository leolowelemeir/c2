

#include <iostream>   
#include <vector>
#include "ex_vecteur.h"
#include <cmath>
using namespace std;


    double Vecteur::getcomposante(double i) const {return vecteur[i];}

    size_t Vecteur::taille() const {return vecteur.size();}
    
    
    
   vector<double> Vecteur::getvecteur() const {return vecteur;}
   
   void Vecteur::setvecteur(vector<double> vec){vecteur=vec;}



    void Vecteur::augmente(double aug){
        //ajoute une dimention au vecteur et donne ca valeur
        vecteur.push_back(aug);
    }
   
//__________________________________________________________________________________________________
    
    void Vecteur::set_coord(int coord, double valeur){
        vecteur[coord]=valeur;
    }

//_____________________________________________________________________________________________________

    /*void Vecteur::affiche() const {
        for (size_t i(0);i<vecteur.size();i++){
            cout<<vecteur[i]<<" "<<endl;
        }
    } */
    

 ostream& operator<<(ostream& sortie, Vecteur const& v){
for (size_t i(0); i<v.taille();i++) {
sortie << v.getcomposante(i) << " ";
}
return sortie;

}

//__________________________________________________________________________________________________

    /*bool Vecteur::compare(Vecteur v) const {
        int n (0);
        if (vecteur.size() != v.vecteur.size()){
            //les vecteurs sont differents
            return false;
            }else{
                for (size_t i(0);i<vecteur.size();i++){
                        if (vecteur[i]!=v.vecteur[i]){
                            n+=1;
                        }
                    }
                }
                if (n == 0){
                  //  les vecteurs sont pareils
                    return true;
                }else{
                   // les vecteurs sont differents
                    return false;
                }
    
            }
    */

//methode interne
bool Vecteur::operator==(const Vecteur& v) const {
    if (vecteur.size() != v.getvecteur().size()){
        //les vecteurs sont differents
        return false;
    }else{
    int a(0);
    for(size_t i(0);i<v.taille();i++){
        if (vecteur[i]-v.vecteur[i] > 0.001){
            a=1;
        }
    }
    if (a==0) {return true;}
    else {return false;}
    }
}
 
//_____________________________________________________________________________________________

 /*   Vecteur Vecteur::addition(Vecteur autre) const {
        //On egalise les vecteurs pour qu ils aient la meme dimension
        //On ne peut pas modifier les vecteurs donc on cree des copies ( pas genial pour la memoire...)
        size_t nv (vecteur.size());
        size_t na (autre.vecteur.size());
        
        Vecteur copie;
        Vecteur autrecopie;
        
        copie.vecteur = vecteur;
        autrecopie.vecteur = autre.vecteur;
        
        if (nv != na){
            if (nv > na){
                for (size_t i(na); i < nv; ++i){
                    autrecopie.vecteur.push_back(0.0);
                }
            }else{
                for (size_t i(nv); i < na; ++i){
                    copie.vecteur.push_back(0.0);
                }
            }
        }
        
        // Pas besoin de creer un nouveau vecteur!
        for (size_t i(0); i < copie.vecteur.size(); ++i){
                    copie.vecteur[i] += autrecopie.vecteur[i];
        }
                
        return copie;
}

*/
   Vecteur Vecteur::operator+=(const Vecteur& autre){
        double valeur;
        Vecteur autrecopie;
        size_t nv (taille());
        size_t na (autre.taille());
        if (nv != na){
			cout << "Attention les vecteurs sont de tailles différentes!" << endl;
			if (nv != na){
            if (nv > na){
                for (size_t i(na); i < nv; ++i){
                    autrecopie.vecteur.push_back(0.0);
                }
                
            }else{
                for (size_t i(nv); i < na; ++i){
                    vecteur.push_back(0.0);
                }
            }
		}
		}
        for (size_t i(0); i < taille() ; ++ i ){
               valeur=(*this).getcomposante(i)+autre.getcomposante(i);
               set_coord(i,valeur);
               }
             return (*this);
        }
    
    Vecteur Vecteur::operator+(const Vecteur& autre){
        return (*this)+= autre;
    }

//________________________________________________________________________________________

    /*Vecteur Vecteur::oppose() const {
        Vecteur opp;
        for (size_t i(0); i < vecteur.size() ; ++ i ){
                opp.vecteur.push_back(-vecteur[i]);
        }
        return opp;
    }*/
    
    Vecteur Vecteur::operator-(){
        for (size_t i(0); i < taille() ; ++ i ){
                vecteur[i]= -vecteur[i];
        }
        return (*this);
        }
//_______________________________________________________________________________________________________________________

    /*Vecteur Vecteur::soustraction (Vecteur autre) const {
        Vecteur opp;
        Vecteur soust;
        opp = autre.oppose();
        soust = addition(opp);    // Tjrs le mm pb, mettre vecteur.addition ou addition???
        
        return soust;
    } */

    //methode interne
 
    
    Vecteur Vecteur::operator-=(const Vecteur& autre){
        double valeur;                    
         for (size_t i(0); i < taille() ; ++ i ){
               valeur=(*this).getcomposante(i)-autre.getcomposante(i);
               set_coord(i,valeur);
         }
        return (*this);
        }
             
    Vecteur Vecteur::operator-(const Vecteur& autre){
        return (*this)-= autre;
    }
    
//______________________________________________________________________________________________________________-

/*    Vecteur Vecteur::mult (double a) const {
        Vecteur multiplie;
        
        for (size_t i(0); i < vecteur.size(); ++i){
            multiplie.vecteur.push_back(a*vecteur[i]);
        }
        return multiplie;
    }     // Tres handicapant car force a recreer a chaque fois un Vecteur
    */
    
    Vecteur Vecteur::operator*=(const Vecteur& autre){
        double valeur;                    
        for (size_t i(0); i < taille() ; ++ i ){
               valeur=(*this).getcomposante(i)*autre.getcomposante(i);
               set_coord(i,valeur);
        }
             return (*this);}
             
    Vecteur Vecteur::operator*(const Vecteur& autre){
        return ((*this)*= autre);
    }
    
     Vecteur operator*(double lambda, Vecteur V){
         double valeur;                    
         for (size_t i(0); i < V.taille() ; ++ i ){
             valeur=V.getcomposante(i)*lambda;
             V.set_coord(i,valeur);
            }
         return V;}


//___________________________________________________________________________________________---

    /*double Vecteur::prod_scal (Vecteur autre) const {
        double a (0);
        if (vecteur.size() == autre.vecteur.size()){
        for (size_t i(0); i < vecteur.size(); ++i){
            a += vecteur[i]*autre.vecteur[i];
            }
        }else{
            cout <<"Les dimensions ne sont pas semblables, erreur pour le produit scalaire"<<endl;
        }
    return a;
    } */
    
    double Vecteur::operator|(const Vecteur&  autre) { //produit scalaire
        double a (0);
        if (vecteur.size() == autre.vecteur.size()){
        for (size_t i(0); i < vecteur.size(); ++i){
            a += vecteur[i]*autre.vecteur[i];
            }
        }else{
            cout <<"Les dimensions ne sont pas semblables, erreur pour le produit scalaire"<<endl;
        }
    return a;
        }


//____________________________________________________________________________________________

    /*Vecteur Vecteur::prod_vect (Vecteur autre) const {
        Vecteur prod;
        if ((vecteur.size()!=3) or (autre.vecteur.size()!=3)){
            cout << "Les dimensions ne sont pas appropriées, erreur pour le produit vectoriel"<<endl;
        } else {
            prod.vecteur = {vecteur[1]*autre.vecteur[2] - vecteur[2]*autre.vecteur[1],
                            vecteur[2]*autre.vecteur[0] - vecteur[0]*autre.vecteur[2],
                            vecteur[0]*autre.vecteur[1] - vecteur[1]*autre.vecteur[0]
                            };
        }
        return prod; // Regler le retour du premier if, sinon il y aura un pb car prod est vide
    } */
    Vecteur Vecteur::operator^(const Vecteur&  autre) {
        Vecteur prod({0.0,0.0,0.0});
        if ((taille()!=3) or (autre.taille()!=3)){
            cout << "Les dimensions ne sont pas appropriées, erreur pour le produit vectoriel"<<endl;
        } else {
            prod.vecteur = {vecteur[1]*autre.vecteur[2] - vecteur[2]*autre.vecteur[1],
                            vecteur[2]*autre.vecteur[0] - vecteur[0]*autre.vecteur[2],
                            vecteur[0]*autre.vecteur[1] - vecteur[1]*autre.vecteur[0]
                            };
        }
        return prod;
        }
//____________________________________________________________________________________________________________

    double carre(double a){
        return a*a;
    }

//_________________________________________________________________________________________________

    double Vecteur::norme2() const {
        double norme2 (0);
        for (size_t i(0); i < vecteur.size(); ++i){
            norme2 += carre(vecteur[i]);
        }
        return norme2;
    }

//___________________________________________________________________________________________________

    double Vecteur::norme() const {
        double norme (sqrt(norme2()));        
        return norme;
    }

//_____________________________________________________________________________________________________________

    /*Vecteur Vecteur::unitaire() const {
        double n (norme());
        Vecteur unitaire (mult(1/n));
        return unitaire;
    }*/
   Vecteur Vecteur:: operator!() {
       double n (norme());
        Vecteur unitaire ((*this)*(1/n));
        return unitaire;
       }

//________________________________________________________________________________________________________________






