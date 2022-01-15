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
   cout << "TEST canevas" << endl;
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
   tests_unitaires();
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
