/********
 * Fichier: Vecteur.cpp.cpp
 * Auteurs: C.-A. Brunet
 * Date: 12 janvier 2021 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    Vecteur.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "Vecteur.h"
#include "forme.h"
Vecteur::Vecteur()
{
  taille = 0;
  capacite = 3;
  tableau = new Forme*[capacite];  
}
Vecteur::Vecteur( int CapaciteVecteur)
{
  taille = 0;
  capacite = CapaciteVecteur;
  tableau = new Forme*[capacite];  
}
Vecteur::~Vecteur()
{
  //Empty();
  //delete[] tableau;
}
int Vecteur::getTaille()
{
  return taille;
}
bool Vecteur::Empty()
{
  //int i;
  //for (i = 0; i < taille; i++)
  //{
    delete[] tableau;
    taille= 0;
    return 0;
  //}
}
bool Vecteur::isEmpty()
{
  if (taille)
  {
    return 1;
  }
  return 0;
}

//ants = new *Ant[num_ants];

bool Vecteur::setItemToTail(Forme* forme)
{
  int i;
  if (taille >= capacite) // fin du buffer
  {
    capacite = capacite * 2;
    Forme** Temporaire = new Forme*[capacite]; // nouveau buffer double
    for (i = 0 ; i < taille; i++) // copie l'ancien
    {
      Temporaire[i] = tableau[i];
    }
    delete[] tableau; 
    tableau = Temporaire;
  }
  // insert Forme
  tableau[taille] = forme;
  taille++;
  return 0;
}
Forme* Vecteur::removeItem(int index)
{
  Forme* Temporaire = tableau[index];
  int i;
  if ((index < 0) || (index >= taille) )
  {
    return NULL;
  }
  for (i = index; i < capacite; i++)
  {
    tableau[i] = tableau[i+1];
  }
  taille--;
  return Temporaire; 
}
Forme* Vecteur::getItem(int index)
{
  if ((index < 0) || (index >= taille) )
  {
    return NULL;
  }
  return tableau[index]; // pointer shenanigan
}
void Vecteur::afficher(ostream & s)
{
  int i;
  if (taille == 0)
  {
    s << "Vide " << "\n" << endl;
    return;
  }
  for (i = 0 ; i < taille; i++) 
  {
    s << "Figure " << i << ":";
    tableau[i]->afficher(s);
  }
   
}

