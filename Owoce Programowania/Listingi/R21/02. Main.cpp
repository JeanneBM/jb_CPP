// Ten program tworzy drzewo z pięciu węzłów.
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
  IntBinaryTree tree;

  cout << "Wstawianie węzłów. ";
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(3);
  tree.insertNode(12);
  tree.insertNode(9);
  cout << "Koniec.\n";

  return 0;
}
