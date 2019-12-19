// Plik specyfikacji klasy MathStack
#ifndef MATHSTACK_H
#define MATHSTACK_H
#include "IntStack.h"

class MathStack : public IntStack
{
public:
  // Konstruktor
  MathStack(int s) : IntStack(s) {}

  // Operacje w klasie MathStack
  void add();
  void sub();
};
#endif
