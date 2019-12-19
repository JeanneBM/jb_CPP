// Ten program demonstruje użycie szablonu klasy BinaryTree.
// Program tworzy drzewo binarne z pięciu węzłów.
#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

const int NUM_NODES = 5;

int main()
{
  string name;

  // Utworzenie drzewa binarnego
  BinaryTree<string> tree;

  // Wstawienie kilku imion
  for (int count = 0; count < NUM_NODES; count++)
  {
    cout << "Podaj imię: ";
    getline(cin, name);
    tree.insertNode(name);
  }

  // Wyświetlenie wartości
  cout << "\nWartości zapisane w drzewie:\n";
  tree.displayInOrder();
  return 0;
}
