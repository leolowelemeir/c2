#include "Integrateur.h"
#include "ex_vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"

using namespace std;


void Integrateur::integre(ObjetMobile& M){
	// On ne peut pas directement placer M.setP ( M.getP() + ... etc) car sinon les valeurs auront change pour le calcul suivant de la derivee, ce qu on ne veut pas ici
		Vecteur nouv_P (M.getP() + (dt*M.getPd()));
		cout << "nouvelle position " << nouv_P << endl;
		Vecteur nouv_Pd (M.getPd() + (dt*M.evolution() ));
		cout << "nouvelle vitesse " << nouv_Pd << endl;
		cout << " acceleration " << M.evolution() << endl;
		M.setP (nouv_P);
		M.setPd (nouv_Pd);
}

void IntegrateurEulerCromer::integre(ObjetMobile& M) {
		/// Verifier si il ne faut pas plutot faire un test d existence que un !=0
		if (not (M.getPd() == vecnull)){		// Si l equation n est que du premier degre, Pd==0. Ainsi ce calcul ne servirait a rien
		 Vecteur nouv_Pd ( M.getPd() + (dt*M.evolution()));
    	 M.setPd ( nouv_Pd);
		}
		M.setP (M.getP() + (dt*M.getPd()));	// Le calcul precedent, s il est effectué, modifie les valeurs de Pd ainsi l'actualisation est valable pour P: d'où la difference avec l'integrateur general
}

/*void IntegrateurNewmark::integre(ObjetMobile& M) {
	if (not (M.getPd()==0)){		// Si l equation n est que du premier degre, Pd==0. Ainsi ce calcul ne servirait a rien
		M.setPd (M.getPd()); 
		M.setP (M.getP());
		s=M.evolution();
		
		do{
			q=M.getP();
			r=M.evolution();
			M.setPd(M.getPd()+dt*(1/2)*(r+s));
			M.setP(M.getP()+dt*M.getPd()+dt*dt*(1/3)(((1/2))*r+s));
			Vecteur test(M.getP-q);
		} while ((test.norme())>=epsilon);

}
}*/
