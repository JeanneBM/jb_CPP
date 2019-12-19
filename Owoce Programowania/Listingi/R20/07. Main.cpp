// Ten program zlicza węzły listy.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
  const int MAX = 10; // Maksymalna wartość do umieszczenia w liście

  // Definicja obiektu typu NumberList
  NumberList list;

  // Umieszczenie w liście serii liczb
  for (int x = 0; x < MAX; x++)
    list.insertNode(x);

  // Wyświetlenie liczby węzłów listy
  cout << "Liczba węzłów w liście: "
       << list.numNodes() << "." << endl;
  return 0;
}
