CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11


all:   testVecteur testObstacle testIntegrateur1 testIntegrateur2 testBalle testPendule



constantes.o: constantes.h constantes.cc

ex_vecteur.o: ex_vecteur.cc ex_vecteur.h

testVecteur.o: testVecteur.cc ex_vecteur.h
testVecteur: testVecteur.o ex_vecteur.o


ObjetMobile.o: ObjetMobile.cc ObjetMobile.h ex_vecteur.cc ex_vecteur.h constantes.o Dessinable.cc Dessinable.h SupportADessin.h

ChampsForces.o: ChampsForces.cc ChampsForces.h ObjetMobile.o ex_vecteur.o

testBalle.o: testBalle.cc ex_vecteur.o ObjetMobile.o constantes.o ChampsForces.o
testBalle: testBalle.o ex_vecteur.o ObjetMobile.o constantes.o ChampsForces.o


obstacle.o: obstacle.cc obstacle.h ex_vecteur.o ObjetMobile.o Dessinable.o SupportADessin.h

testObstacle.o: testObstacle.cc constantes.o ObjetMobile.cc ObjetMobile.h ex_vecteur.o obstacle.cc obstacle.h
testObstacle: testObstacle.o constantes.o ObjetMobile.o ex_vecteur.o obstacle.o

testPendule.o: ex_vecteur.o ObjetMobile.o testPendule.cc constantes.o Integrateur.o
testPendule: testPendule.o ObjetMobile.o ex_vecteur.o constantes.o Integrateur.o


Integrateur.o: Integrateur.h Integrateur.cc ex_vecteur.o ObjetMobile.o

testIntegrateur1.o: Integrateur.o ex_vecteur.o ObjetMobile.o constantes.o
testIntegrateur1: testIntegrateur1.o Integrateur.o ex_vecteur.o ObjetMobile.o constantes.o

testIntegrateur2.o: Integrateur.o ex_vecteur.o ObjetMobile.o constantes.o ChampsForces.o
testIntegrateur2: testIntegrateur2.o Integrateur.o ex_vecteur.o ObjetMobile.o constantes.o ChampsForces.o

Dessinable.o: Dessinable.h Dessinable.cc ex_vecteur.o SupportADessin.h

Objetcompose.o: Objetcompose.cc Objetcompose.h ex_vecteur.o ChampsForces.o obstacle.o ObjetMobile.o Dessinable.o

Systeme.o: Systeme.cc Systeme.h Dessinable.o ChampsForces.o Objetcompose.o



