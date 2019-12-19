// Ten program demonstruje użycie dynamicznego stosu.
// Klasa DynIntClass
#include <iostream>
#include "DynIntStack.h"
using namespace std;

int main()
{
  int catchVar; // Zmienna przechowująca wartość zdjętą ze stosu

  // Utworzenie obiektu typu DynIntStack
  DynIntStack stack;

  // Odłożenie na stosie wartości 5, 10 i 15
  cout << "Odkładanie wartości 5\n";
  stack.push(5);
  cout << "Odkładanie wartości 10\n";
  stack.push(10);
  cout << "Odkładanie wartości 15\n";
  stack.push(15);

  // Zdjęcie wartości ze stosu i wyświetlenie na ekranie
  cout << "Zdejmowanie wartości...\n";
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;

  // Próba zdjęcia ze stosu kolejnej wartości
  cout << "\nPróba zdjęcia ze stosu kolejnej wartości... ";
  stack.pop(catchVar);
  return 0;
}
