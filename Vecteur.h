/********
 * Fichier: Vecteur.h
 * Auteurs: C-D Gaudreault
 * Date: 11 janvier 2021 (creation)
 * Description: Declaration de la classe pour un Vecteur
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef VECTEUR_H
#define VECTEUR_H
#include "forme.h"
class Vecteur
{
private:
  Forme**  tableau;
  int taille; // indice max courent dans le vecteur
  int capacite; // maximun du vecteur.

public:
  Vecteur();
  Vecteur(int CapaciteVecteur);
  virtual ~Vecteur(); 
  int getTaille();
  bool Empty();
  bool isEmpty();
  bool setItemToTail(Forme* forme);
  Forme* removeItem(int index);
  Forme* getItem(int index);
  virtual void afficher(ostream & s);
  

protected:

};

#endif
