// rectangle.h (Rectangle version 1 Gaddis ed 6  page 754)
// Specification file for the Rectangle class. 
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "forme.h"


using namespace std;

// Rectangle class declaration.

class Rectangle: public Forme
{
   private:
      double width;
      double length;
   public:
      Rectangle();
      Rectangle(double w, double l);
      ~Rectangle();
      void setWidth(double);
      void setLength(double);
      double getWidth() const;
      double getLength() const;
      double getArea() const;
};

#endif
