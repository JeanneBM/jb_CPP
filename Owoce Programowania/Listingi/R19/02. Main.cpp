// Ten program demonstruje użycie klasy MathStack.
#include <iostream>
#include "MathStack.h"
using namespace std;

int main()
{
  int catchVar; // Zmienna zawierająca wartość zdjętą ze stosu

  // Utworzenie obiektu typu MathStack
  MathStack stack(5);

  // Odłożenie wartości 3 i 6 na stosie
  cout << "Odkładanie wartości 3\n";
  stack.push(3);
  cout << "Odkładanie wartości 6\n";
  stack.push(6);

  // Dodanie dwóch wartości.
  stack.add();

  // Zdjęcie sumy ze stosu i jej wyświetlenie
  cout << "Suma wartości: ";
  stack.pop(catchVar);
  cout << catchVar << endl << endl;

  // Odłożenie wartości 7 i 10 na stosie
  cout << "Odkładanie wartości 7\n";
  stack.push(7);
  cout << "Odkładanie wartości 10\n";
  stack.push(10);

  // Odjęcie 7 od 10.
  stack.sub();

  // Zdjęcie różnicy ze stosu i jej wyświetlenie
  cout << "Różnica wartości: ";
  stack.pop(catchVar);
  cout << catchVar << endl;
  return 0;
}
