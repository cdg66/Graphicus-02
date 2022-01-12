/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include "forme.h" 
#include "rectangle.h"
#include "Cercle.h"
#include "Vecteur.h"

using namespace std;

int main()
{
   Tests tests;
   Forme *pr = new Rectangle;
   Forme *pc = new Cercle;
   Vecteur *v = new Vecteur;
   v->setItemToTail(pr);
   v->setItemToTail(pc);
   //Carre = new Rectangle;
   tests.tests_application();
   delete pr;
   delete pc;
   return 0;
}

