/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
#define OUTPUT
Canevas::Canevas()
{
  for (int i = 0; i < MAX_COUCHES; i++)
  {
    couches[i].setIndexCouche(i);
  }
  couches[0].setEtat(ETATACTIF); // set la premiere couche comme etat active
}

Canevas::~Canevas(){}

//En attente de couche
bool Canevas::reinitialiser()
{
   for (int i=0; i<MAX_COUCHES; i++){
      couches[i].setEtatReinitialise();
   }
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      couches[i].setIndexCouche(i);
   }
   couches[0].setEtat(ETATACTIF); // set la premiere couche comme etat
   return false;
}

bool Canevas::activerCouche(int index)
{
   
    if (index >= 0 && index < MAX_COUCHES)
    { 
       if (couches[index].getEtat() == ETATACTIF)
       {
          for (int i=0; i<MAX_COUCHES; i++)
          {
             if (cacherCouche(i) == false)
             {
                 return false;
             }
          }
       }
       else if (couches[index].getEtat() == ETATINACTIF || couches[index].getEtat() == ETATINIT) {
          couches[index].setEtat(ETATACTIF);
          #ifdef OUTPUT
          cout << "REUSSITE 1" << endl;
          #endif
          
          for (int i=0; i<MAX_COUCHES; i++)
          {
            if (i != index)
            {
              if (cacherCouche(i) == false)
              {
                 return false;
              }
            }
          }
          return true;
       }
       else{
          #ifdef OUTPUT
          cout << "ECHEC, erreur setEtat 1" << endl;
          #endif 
          return false;
       }
    }
    else
    {
       #ifdef OUTPUT
       cout << "ECHEC, index hors limites 1" << endl;
       #endif 
       return false;
    }
    return false;
}

bool Canevas::cacherCouche(int index)
{
   if (index >= 0 && index < MAX_COUCHES){
       if (couches[index].setEtat(ETATINACTIF) == true){
          #ifdef OUTPUT
          cout << "REUSSITE 2" << endl;
          #endif
          return true;
       }
       else{
          #ifdef OUTPUT
          cout << "ECHEC, erreur setEtat 2" << endl;
          #endif
          return false;
       }
    }
    else{
       #ifdef OUTPUT
       cout << "ECHEC, index hors limites 2" << endl;
       #endif
       return false;
    }
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
         #ifdef OUTPUT
         cout << "REUSSITE 3" << endl;
         #endif
         return couches[i].setForme(p_forme);
      }
   }
   
   #ifdef OUTPUT
   cout << "ECHEC, erreur forme 1" << endl;
   #endif
   return false;
}

//En attente de couche
bool Canevas::retirerForme(int index)
{
   for (int i=0; i<MAX_COUCHES; i++){
      if (couches[i].getEtat() == ETATACTIF){
         #ifdef OUTPUT
         cout << "REUSSITE 4" << endl;
         #endif
         return couches[i].removeForme(index);
      }
   }
   
   #ifdef OUTPUT
   cout << "ECHEC, erreur forme 2" << endl;
   #endif
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
         #ifdef OUTPUT
         cout << "REUSSITE 5" << endl;
         #endif
         return couches[i].translaterCouche(deltaX, deltaY);
      }
   }
   
   #ifdef OUTPUT
   cout << "ECHEC, erreur position" << endl;
   #endif
   return false;
}

void Canevas::afficher(ostream & s)
{
   #ifdef OUTPUT
   int j = 0;
   #endif
   for (int i=0; i<MAX_COUCHES; i++){
      //s << "----- couche no: " << i << "-----"<< endl;
      couches[i].afficherCouche(s);
   }
   #ifdef OUTPUT
   //if (j == 0)
   //{
   //  cout << "ECHEC, rien a afficher" << endl;
   //}
   #endif
}






