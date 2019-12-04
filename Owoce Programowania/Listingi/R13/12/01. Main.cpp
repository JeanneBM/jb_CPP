// Ten program demonstruje użycie klasy z destruktorem
#include <iostream>
#include "ContactInfo.h"
using namespace std;

int main()
{
  // Definicja obiektu typu ContactInfo z następującymi danymi:
  // Imię i nazwisko: Jak Nowak, nr telefonu: 512 345 678
  ContactInfo entry("Jan Nowak", "512 345 678");

  // Wyświetlenie danych zapisanych w obiekcie
  cout << "Imię i nazwisko: " << entry.getName() << endl;
  cout << "Nr telefonu: " << entry.getPhoneNumber() << endl;
  return 0;
}
