// Ten program demonstruje użycie klasy IntStack.
#include <iostream>
#include "IntStack.h"
using namespace std;

int main()
{
  int catchVar; // Zmienna zawierająca wartość zdjętą ze stosu

  // Definicja stosu na 5 wartości
  IntStack stack(5);

  // Odłożenie na stosie wartości 5, 10, 15, 20 i 25
  cout << "Odłożenie wartości 5\n";
  stack.push(5);
  cout << "Odłożenie wartości 10\n";
  stack.push(10);
  cout << "Odłożenie wartości 15\n";
  stack.push(15);
  cout << "Odłożenie wartości 20\n";
  stack.push(20);
  cout << "Odłożenie wartości 25\n";
  stack.push(25);

  // Zdjęcie wartości ze stosu
  cout << "Zdejmowanie wartości...\n";
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  return 0;
}
