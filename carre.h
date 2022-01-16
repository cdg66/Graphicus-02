// rectangle.h (Rectangle version 1 Gaddis ed 6  page 754)
// Specification file for the Rectangle class. 
#ifndef CARRE_H
#define CARRE_H
#include "forme.h"
#include "rectangle.h"

using namespace std;

// Carre class declaration.

class Carre: public Rectangle
{
   private:
   public:
      Carre();
      Carre(double l);
      Carre(double l, int X, int Y);
      virtual  ~Carre();
      
      virtual double aire();
      virtual void afficher(ostream & s);
      void translater(int deltaX, int deltaY); // delta Y est ignoree seul deltaX est pris en compte
      void setWidth(double);
      void setLength(double);
      double getWidth() const;
      double getLength() const;
};

#endif
