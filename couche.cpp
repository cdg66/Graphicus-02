/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

using namespace std;

Couche::Couche()
{
  indexCouche = 0;
  etatCouche = ETATINIT;
}
Couche::~Couche()
{

}

bool Couche::setIndexCouche(int index)
{
  indexCouche = index;
  return true;
}

int  Couche::getIndexCouche()
{
  return indexCouche;
}

bool Couche::setForme(Forme* forme)
{
  if (shapes.setItemToTail(forme) == 0)
  {
    return true;
  };
  return false;
}

bool Couche::removeForme(int index)
{
   if (index < 0 || index > shapes.getTaille())
   {
     return false;
   }
   delete shapes.removeItem(index);
   return true;
}

Forme* Couche::getForme(int index)
{
  return shapes.getItem(index);
}

double Couche::getAire()
{
  int i;
  double aire = 0;
  Forme* forme;
  for (i = 0; i < shapes.getTaille(); i++)
  { 
    forme = shapes.getItem(i);
    aire = aire + forme->aire();
  }
  return aire;
}

bool Couche::translaterCouche(int deltaX, int deltaY)
{
  int i;
  for (i = 0; i < shapes.getTaille(); i++)
  {
    cout << "translation:"<< i << endl;
    Forme* forme = shapes.getItem(i);
    if (forme == NULL)
    {
      cout << "erreur getitem returned NULL" << endl;
      return false;
    }
    cout << "translation get:"<< i << endl;
    forme->translater(deltaX, deltaY);
    cout << "fin translation:"<< i << endl;
  }
  return true;
}
bool Couche::setEtatReinitialise()
{
// vide le vecteur
  shapes.Empty();

// reset index de couche
  indexCouche = 0;

// reset l'etat de couche
  etatCouche = ETATINIT;
  return true;
}
bool Couche::setEtat(int Etat)
{
  if (Etat == ETATINIT)
  {
    return false;
  }
  etatCouche = Etat;
  return true;
}

int Couche::getEtat()
{
  return etatCouche;
}
void Couche::afficherCouche(ostream & s)
{
  int i;
  s << "Couche numero:" << getIndexCouche() << endl;
  shapes.afficher(s);
}
