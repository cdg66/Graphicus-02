/********
 * Fichier: Vecteur.h
 * Auteurs: C-D Gaudreault
 * Date: 11 janvier 2021 (creation)
 * Description: Declaration de la classe pour un Vecteur
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "forme.h"
class Vecteur
{
private:
  forme *tableau;
  int taille; // indice max courent dans le vecteur
  int capacite; // maximun du vecteur.

public:
  Vecteur();
  Vecteur(int CapaciteVecteur);
  virtual ~Vecteur(); 
  int getTaille();
  bool Empty();
  bool isEmpty();
  bool setItemToTail(forme* forme);
  forme* removeItem(int index);
  forme* getItem(int index);
  virtual void afficher(ostream & s);
  

protected:

};

#endif
