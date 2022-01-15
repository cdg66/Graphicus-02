// rectangle.cpp (Rectangle version 1 Gaddis ed 6  page 755)
// Implementation file for the Rectangle class.
#include "carre.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
using namespace std;


Carre::Carre()
{
  Rectangle::setLength(1);
  Rectangle::setWidth(1);
}

Carre::Carre(double l)
{
  Rectangle::setLength(l);
  Rectangle::setWidth(l);
}
Carre::~Carre()
{

}
void Carre::translater(int deltaX, int deltaY)
{
  Rectangle::translater(deltaX,deltaX);
}
//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Carre::setWidth(double w)
{
   if (w > 0)
   {
      Rectangle::setLength(w);
      Rectangle::setWidth(w);
   }
   else
   {
      cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Carre::setLength(double len)
{
   if (len > 0)
   {
      Rectangle::setLength(len);
      Rectangle::setWidth(len);
   }
   else
   {
      cout << "Invalid length\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// getWidth returns the value in the member variable width. *
//***********************************************************

double Carre::getWidth() const
{
   return Rectangle::getWidth();
}

//*************************************************************
// getLength returns the value in the member variable length. *
//*************************************************************

double Carre::getLength() const
{
   return Rectangle::getWidth(); // supposed to be the same
}

//************************************************************
// getArea returns the product of width times length.        *
//************************************************************

double Carre::aire() 
{
   return Rectangle::getWidth() * Rectangle::getWidth();
}

void Carre::afficher(ostream & s)
{
   s << "ceci est un carree d'aire:" << aire() << "u^2" << endl;
}



