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

#define TESTUNITAIRE
#define TESTCAS1
#define TESTCAS2

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
   cout << "------------Etape 1--------------" << endl; 
   if(cnv.activerCouche(1) == true)
   {
     cout << "couche 1 active" << endl;
   }
   else
   {
     cout << "failed to activer couche 1 : exiting";
     return;
   }
   
   
   cout << "------------Etape 2--------------" << endl; 
   if(cnv.ajouterForme(new Rectangle(2, 3)) == true)
   {
     cout << "rectangle ajoute" << endl;
   }
   else
   {
     cout << "failed to ajouter rectangle: exiting" << endl;
     return;
   }
   
   if(cnv.ajouterForme(new Carre(4, 2, 3)) == true)
   {
     cout << "carre ajoute" << endl;
   }
   else
   {
     cout << "failed to ajouter carre: exiting" << endl;
     return;
   }
   
   if(cnv.ajouterForme(new Cercle(6, 7, 8)) == true)
   {
     cout << "cercle ajoute" << endl;
   }
   else
   {
     cout << "failed to ajouter carre: exiting" << endl;
     return;
   }
   
   
   cout << "------------Etape 3--------------" << endl; 
   cout << "------------Etape 4--------------" << endl; 
   cout << "------------Etape 5--------------" << endl; 
   cout << "------------Etape 6--------------" << endl; 
   cout << "------------Etape 7--------------" << endl; 
   cout << "------------Etape 8--------------" << endl; 
   cout << "------------Etape 9--------------" << endl; 
   cout << "------------Etape 10-------------" << endl; 
   cout << "------------Etape 11-------------" << endl; 
   cout << "------------Etape 12-------------" << endl; 
   cout << "------------Etape 13-------------" << endl; 
   cout << "------------Etape 14-------------" << endl; 
   cout << "------------Etape 15-------------" << endl; 
   cout << "------------Etape 16-------------" << endl; 
   cout << "------------Etape 17-------------" << endl; 
   cout << "------------Etape 18-------------" << endl; 
   cout << "------------Etape 19-------------" << endl; 
   
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
