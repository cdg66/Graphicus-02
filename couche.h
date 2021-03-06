/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet C-D Gaudreault
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "Vecteur.h"

#define ETATINIT    0
#define ETATACTIF   1
#define ETATINACTIF 2
class Couche
{
   private:
   
   int etatCouche;
   int indexCouche;
   Vecteur shapes; 
   
   public:
   
   Couche();
   ~Couche();
   bool setIndexCouche(int index);
   int  getIndexCouche();
   bool setForme(Forme* forme);
   bool removeForme(int index);
   Forme* getForme(int index);
   double getAire();
   bool translaterCouche(int deltaX, int deltaY);
   bool setEtatReinitialise();
   bool setEtat(int Etat);
   int getEtat();
   void afficherCouche(ostream & s); 
};

#endif
