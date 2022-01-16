/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include <iostream>
//#define TESTUNITAIRE
#define TESTCAS1
//#define TESTCAS2

using namespace std;

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
   cout << "TEST Forme" << endl;
   Forme* rectangle1 = new Rectangle;
   Forme* cercle1 = new Cercle;
   Forme* rectangle2 = new Rectangle(5, 2);
   Forme* cercle2 = new Cercle(3);
   Forme* carre1 = new Carre();
   Forme* carre2 = new Carre(111);
   rectangle1->afficher(std::cout);
   rectangle2->afficher(std::cout);
   cercle1->afficher(std::cout);
   cercle2->afficher(std::cout);
   carre1->afficher(std::cout);
   carre2->afficher(std::cout);
   cout << "translater" << endl;
   delete rectangle1;
   delete rectangle2;
   delete cercle1;
   delete cercle2;
   delete carre1;
   delete carre2;
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
   cout << "TEST vecteurs" << endl;
   Vecteur tv;
   tv.setItemToTail(new Rectangle);
   tv.setItemToTail(new Cercle);
   tv.setItemToTail(new Rectangle);
   tv.setItemToTail(new Cercle);
   tv.setItemToTail(new Rectangle);
   tv.setItemToTail(new Cercle);
   // afiche
   int taille = tv.getTaille();
   cout << "taille du vecteur:" << taille << endl;
   tv.afficher(std::cout);
   // delete a forme
   cout << "enlever item 3:" << taille << endl;
   if (tv.removeItem(3) == NULL)
   {
     cout << "erreur  verteur retourne NULL" << taille << endl;
   };
   // affiche encore
   taille = tv.getTaille();
   cout << "taille du vecteur:" << taille << endl;
   tv.afficher(std::cout); 
   cout << "taille du vecteur:" << taille << endl;
   // delete tv
   cout << "empty vecteur"  << endl;
   //tv.Empty();
   //tv.Empty();
   // affiche taille encore
   taille = tv.getTaille();
   //cout << "taille du vecteur une fois vide:" << taille << endl;
   //delete tv;
}

void Tests::tests_unitaires_couche()
{
   Couche couche;
   // Tests sur la classe Couche
   cout << "TEST couche" << endl;
   couche.setIndexCouche(5);
   cout << "num couche: " << couche.getIndexCouche() << endl;
   couche.setForme(new Rectangle);
   couche.setForme(new Rectangle);
   couche.setForme(new Cercle);
   couche.setForme(new Rectangle);
   couche.afficherCouche(std::cout);
   cout << "remove item 1" << endl;
   couche.removeForme(1);
   cout << "novelle couche" << endl;
   couche.afficherCouche(std::cout);
   couche.setEtat(ETATACTIF);
   cout << "EtatActif:" << couche.getEtat() << endl;
   couche.setEtat(ETATINACTIF);
   cout << "EtatInactif:" << couche.getEtat() << endl;
   couche.setEtat(ETATINIT);
   cout << "Etatinit_err:" << couche.getEtat() << endl;
   
   cout << "translatation 1:1" << endl;
   couche.translaterCouche(1,1);
   couche.afficherCouche(std::cout);
   
   cout << "aire:" << couche.getAire() <<endl;
   
   //cout << "Reinitialise" << endl;
   //couche.setEtatReinitialise();
   //cout << "Etat:" << couche.getEtat() << endl;
   //couche.afficherCouche(std::cout);
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
   cout << "\nTEST canevas\n" << endl;
   Canevas cnv;
   
   //out of bound
   cnv.activerCouche(6);
   
   //test activerCouche, cacherCouche, reinitialiser
   cnv.activerCouche(1); //simplement activer
   cnv.afficher(std::cout);
   
   cnv.cacherCouche(1); //simplement desactiver
   cnv.afficher(std::cout);
   
   cnv.activerCouche(2); //desactiver par double activation
   cnv.activerCouche(2);
   
   
   cnv.reinitialiser(); //reinitialiser
   cnv.afficher(std::cout);
   
   //test ajouterForme
   cnv.ajouterForme(new Rectangle);
   cnv.ajouterForme(new Cercle);
   cnv.ajouterForme(new Carre);
   cnv.afficher(std::cout);
   
   //test retirerForme
   cnv.retirerForme(2);
   cnv.retirerForme(1);
   cnv.retirerForme(0);
   cnv.afficher(std::cout);
   
   //test translater
   cnv.ajouterForme(new Rectangle(15, 20));
   cnv.ajouterForme(new Cercle(2));
   cnv.translater(4, 3);
   cnv.afficher(std::cout);
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   cout << "TESTS UNITAIRES (CAS 00)" << endl;
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   #ifdef TESTUNITAIRE
   tests_unitaires();
   #endif
   #ifdef TESTCAS1
   tests_application_cas_01();
   #endif
   #ifdef TESTCAS2
   tests_application_cas_02();
   #endif
}

void Tests::tests_application_cas_01()
{
   Canevas cnv;
   Coordonnee cord;
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
   cout << "\n------------Etape 1--------------\n" << endl; 
   if(cnv.activerCouche(1) == true)
   {
     cout << "couche 1 active" << endl;
   }
   else
   {
     cout << "Erreur pour activer couche 1 : exiting";
     return;
   }
   
   
   cout << "\n------------Etape 2--------------\n" << endl; 
   if(cnv.ajouterForme(new Rectangle(2, 3)) == true)
   {
     cout << "rectangle ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter rectangle: exiting" << endl;
     return;
   }
   
   if(cnv.ajouterForme(new Carre(4, 2, 3)) == true)
   {
     cout << "carre ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter carre: exiting" << endl;
     return;
   }
   
   if(cnv.ajouterForme(new Cercle(6, 7, 8)) == true)
   {
     cout << "cercle ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter carre: exiting" << endl;
     return;
   }
   
   
   cout << "\n------------Etape 3--------------\n" << endl; 
   
   if(cnv.activerCouche(2) == true)
   {
     cout << "couche 2 active" << endl;
   }
   else
   {
     cout << "Erreur pour activer couche 2 : exiting";
     return;
   }
   
   cout << "\n------------Etape 4--------------\n" << endl; 
   
   //ajout d'un rectangle
   if(cnv.ajouterForme(new Rectangle(4, 5)) == true)
   {
     cout << "rectangle ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter rectangle: exiting" << endl;
     return;
   }
   
   cout << "\n------------Etape 5--------------\n" << endl; 
   
   cnv.afficher(std::cout);
   
   cout << "\n------------Etape 6--------------\n" << endl; 
   
   cout << "L'aire totale du Canevas est de: " << cnv.aire() << " u^2" << endl;
   
   cout << "\n------------Etape 7--------------\n" << endl; 
   
   //activer couche 0
   if(cnv.activerCouche(0) == true)
   {
     cout << "couche 0 active" << endl;
   }
   else
   {
     cout << "Erreur pour activer couche 2 : exiting";
     return;
   }
   
   //ajout d'un rectangle
   if(cnv.ajouterForme(new Rectangle(1, 1)) == true)
   {
     cout << "rectangle ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter rectangle: exiting" << endl;
     return;
   }
   
   //ajout d'un carre
   if(cnv.ajouterForme(new Carre(1)) == true)
   {
     cout << "carre ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter carre: exiting" << endl;
     return;
   }
   
   //ajout d'un cercle
   if(cnv.ajouterForme(new Cercle(1)) == true)
   {
     cout << "cercle ajoute" << endl;
   }
   else
   {
     cout << "Erreur pour ajouter cercle: exiting" << endl;
     return;
   }
   
   cout << "\n------------Etape 8--------------\n" << endl; 
   
   if(cnv.activerCouche(1) == true)
   {
     cout << "couche 1 active" << endl;
   }
   else
   {
     cout << "Erreur pour activer couche 1 : exiting";
     return;
   }
   
   if(cnv.translater(5, 5) == true)
   {
     cnv.afficher(std::cout);
   }
   else
   {
     cout << "Erreur pour activer couche 2 : exiting";
     return;
   }
   
   cout << "\n------------Etape 9--------------\n" << endl;
   
   if (cnv.reinitialiserCouche(2) == true)
   {
     cout << "couche 2 reinitialisee" << endl;
   }
   else
   {
     cout << "Erreur pour reinitialiser couche 2 : exiting";
     return;
   }
   
   cout << "\n------------Etape 10-------------\n" << endl; 
   
   if (cnv.reinitialiserCouche(3) == true)
   {
     cout << "couche 3 reinitialisee" << endl;
   }
   else
   {
     cout << "Erreur pour reinitialiser couche 3 : exiting";
     return;
   }
   
   cnv.afficher(std::cout);
   
   cout << "\n------------Etape 11-------------\n" << endl; 
   
   if (cnv.reinitialiserCouche(4) == true)
   {
     cout << "couche 3 reinitialisee" << endl;
   }
   else
   {
     cout << "Erreur pour reinitialiser couche 3 : exiting";
     return;
   }
   
   cout << "\n------------Etape 12-------------\n" << endl; 
   
   cnv.afficher(std::cout);
   
   cout << "\n------------Etape 13-------------\n" << endl; 
   
   cout << "L'aire totale du Canevas est de: " << cnv.aire() << " u^2" << endl;
   
   cout << "\n------------Etape 14-------------\n" << endl; 
   
   if (cnv.retirerForme(0) == true)
   {
     cout << "forme retiree" << endl;
   }
   else
   {
     cout << "Erreur pour retirer forme" << endl;
   }
   
   cout << "\n------------Etape 15-------------\n" << endl; 
   
   cnv.afficher(std::cout);
   
   cout << "\n------------Etape 16-------------\n" << endl; 
   
   cout << "L'aire totale du Canevas est de: " << cnv.aire() << " u^2" << endl;
   
   cout << "\n------------Etape 17-------------\n" << endl; 
   
   if (cnv.reinitialiser() == true)
   {
     cout << "canevas reinitialise" << endl;
   }
   else
   {
     cout << "Erreur pour reinitialiser canevas" << endl;
   }
   
   cout << "\n------------Etape 18-------------\n" << endl; 
   
   cnv.afficher(std::cout);
   
   cout << "\n------------Etape 19-------------\n" << endl; 
   
   cout << "L'aire totale du Canevas est de: " << cnv.aire() << " u^2" << endl;
   
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
