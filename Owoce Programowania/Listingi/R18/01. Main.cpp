// Ten program demonstruje proste dołączanie
// węzłów do połączonej listy.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
  // Definicja obiektu NumberList
  NumberList list;

  // Dołączenie do listy kilku węzłów
  list.appendNode(2.5);
  list.appendNode(7.9);
  list.appendNode(12.6);
  return 0;
}
