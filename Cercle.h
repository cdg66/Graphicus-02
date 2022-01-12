#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"


using namespace std;

// Rectangle class declaration.

class Cercle: public Forme
{
   private:
      double rayon;
      
   public:
      Cercle();
      Cercle(double r);
      ~Cercle();
      
      virtual double aire() = 0;
      virtual void afficher(ostream & s) = 0;
      
      void setRayon(double);
      double getRayon const;
};

#endif
