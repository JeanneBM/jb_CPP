// Ten program demonstruje tworzenie łączonej listy za pomocą szablonu.
#include <iostream>
#include "LinkedList.h"
#include "FeetInches.h"
using namespace std;

int main()
{
  // Definicja obiektu typu LinkedList
  LinkedList<FeetInches> list;

  // Definicja kilku obiektów typu FeetInches
  FeetInches distance1(5, 4); // 5 stóp 4 cale
  FeetInches distance2(6, 8); // 6 stóp 8 cali
  FeetInches distance3(8, 9); // 8 stóp 9 cali

  // Umieszczenie obiektów typu FeetInches w liście
  list.appendNode(distance1); // 5 stóp 4 cale
  list.appendNode(distance2); // 6 stóp 8 cali
  list.appendNode(distance3); // 8 stóp 9 cali

  // Wyświetlenie zawartości listy
  cout << "Początkowa zawartość listy:\n";
  list.displayList();
  cout << endl;

  // Wstawienie kolejnego węzła typu FeetInches
  cout << "Wstawienie wartości '7 stóp i 2 cale'.\n";
  FeetInches distance4(7, 2);
  list.insertNode(distance4);

  // Wyświetlenie zawartości listy
  cout << "Bieżąca zawartość listy.\n";
  list.displayList();
  cout << endl;

  // Usunięcie ostatniego węzła
  cout << "Usunięcie ostatniego węzła.\n";
  FeetInches distance5(8, 9);
  list.deleteNode(distance5);

  // Wyświetlenie zawartości listy
  cout << "Bieżąca zawartość listy.\n";
  list.displayList();
  return 0;
}
