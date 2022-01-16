#include "Cercle.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function

#define PI 3.141592653

using namespace std;


Cercle::Cercle()
{
  rayon = 1;
}

Cercle::Cercle(double r)
{
  rayon = r;
}

Cercle::Cercle(double r,  int X, int Y)
{
  Coordonnee coord;
  coord.x = X;
  coord.y =Y;
  setAncrage(coord);
  rayon = r;
}

Cercle::~Cercle(){}

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Cercle::setRayon(double r)
{
   if (r > 0)
      rayon = r;
   else
   {
      cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}


//***********************************************************
// getWidth returns the value in the member variable width. *
//***********************************************************

double Cercle::getRayon() const
{
   return rayon;
}


//************************************************************
// getArea returns the product of width times length.        *
//************************************************************

double Cercle::aire()
{
   return PI * rayon * rayon;
}

void Cercle::afficher(ostream & s)
{
   s << "ceci est un cercle d'aire: " << aire() << " u^2" << endl;
}










