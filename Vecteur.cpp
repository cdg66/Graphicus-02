/********
 * Fichier: Vecteur.cpp.cpp
 * Auteurs: C.-A. Brunet
 * Date: 12 janvier 2021 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    Vecteur.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "Vecteur.h"

Vecteur::Vecteur()
{
  taille = 0;
  capacite = 3;
  *tableau = new Forme[capacite];
}
Vecteur::Vecteur( int CapaciteVecteur)
{
  taille = 0;
  capacite = CapaciteVecteur;
  *tableau = new Forme[capacite];
}
virtual Vecteur::~Vecteur()
{
  Empty();
  delete tableau;
}
int Vecteur::getTaille()
{
  return taille;
}
bool Vecteur::Empty()
{
  int i;
  for (i = 0; i < taille; i++)
  {
    delete tableau[i];
  }
}
bool Vecteur::isEmpty()
{
  if (taille)
  {
    return 1;
  }
  return 0;
}
bool Vecteur::setItemToTail(Forme* Forme)
{
  int i;
  if (taille >= capacite) // fin du buffer
  {
    capacite = capacite * 2;
    Forme *tabtemp = new Forme[capacite]; // nouveau buffer double
    for (i = 0 ; i < taille; i++) // copie l'ancien
    {
      tabtemp[i] = tableau[i];
    }
    delete tableau;   
    tableau = tabletemp;
  }
  // insert Forme
  tableau[taille] = &Forme;
  taille++;
  
}
Forme* Vecteur::removeItem(int index)
{

}
Forme* Vecteur::getItem(int index)
{
  if ((index > 0) || (index >= taille) )
  {
    return null;
  }
  return tableau[index]
}
virtual void Vecteur::afficher(ostream & s)
{
  int i;
  for (i = 0 ; i < taille; i++) 
  {
    s << "Figure " << i << ":";
    tableau[i]->afficher(s);
  }
   
}

