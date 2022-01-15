// rectangle.cpp (Rectangle version 1 Gaddis ed 6  page 755)
// Implementation file for the Rectangle class.
#include "rectangle.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
using namespace std;


Rectangle::Rectangle()
{
  width = 1;
  length = 1;
}

Rectangle::Rectangle(double w, double l)
{
  width = w;
  length = l;
}
Rectangle::~Rectangle()
{

}

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w)
{
   if (w > 0)
      width = w;
   else
   {
      cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len)
{
   if (len > 0)
      length = len;
   else
   {
      cout << "Invalid length\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// getWidth returns the value in the member variable width. *
//***********************************************************

double Rectangle::getWidth() const
{
   return width;
}

//*************************************************************
// getLength returns the value in the member variable length. *
//*************************************************************

double Rectangle::getLength() const
{
   return length;
}

//************************************************************
// getArea returns the product of width times length.        *
//************************************************************

double Rectangle::aire() 
{
   return width * length;
}

void Rectangle::afficher(ostream & s)
{
   s << "ceci est un rectangle d'aire: " << aire() << " u^2" << endl;
}



