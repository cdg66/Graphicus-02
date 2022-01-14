/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas(){}

Canevas::~Canevas(){}

//En attente de couche
bool Canevas::reinitialiser()
{
   for (int i=0; i<MAX_COUCHES; i++){
      couches[i].setEtatReinitialise();
   }
   return false;
}

bool Canevas::activerCouche(int index)
{
    if (index < MAX_COUCHES){
       if (couches[index].setEtat(ETATACTIF) == true)
          return true;
       else
          return false;
    }
    else
       return false;
}

bool Canevas::cacherCouche(int index)
{
   if (index < MAX_COUCHES){
       if (couches[index].setEtat(ETATINACTIF) == true)
          return true;
       else
          return false;
    }
    else
       return false;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
         return couches[i].setForme(p_forme);
      }
   }
   return false;
}

//En attente de couche
bool Canevas::retirerForme(int index)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
         return couches[i].removeForme(index);
      }
   }
   return false;
}

double Canevas::aire()
{
   double aireTotale = 0.0;
   for (int i=0; i<MAX_COUCHES; i++){
      aireTotale += couches[i].getAire();
   }
   return aireTotale;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
         return couches[i].translaterCouche(deltaX, deltaY);
      }
   }
   return false;
}

void Canevas::afficher(ostream & s)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
        s << "Voici la couche demandee d'indexe: "<< couches[i].getIndexCouche() << endl;
        s << "Celle-ci est composee de: " << endl;
        couches[i].afficherCouche(s);
        s << "L'aire totale de toutes les couches est de: " << aire() << endl;
      }
   }
}






