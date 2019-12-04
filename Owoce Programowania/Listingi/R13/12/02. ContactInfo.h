// Plik specyfikacji klasy Contact
#ifndef CONTACTINFO_H
#define CONTACTINFO_H
#include <cstring>   // Instrukcja wymagana przez funkcje strlen() i strcpy()

// Deklaracja klasy ContactInfo
class ContactInfo
{
private:
  char *name;  // Imię i nazwisko
  char *phone; // Numer telefonu
public:
  // Konstruktor
  ContactInfo(const char *n, const char *p)
  { // Alokacja odpowiedniej ilości pamięci dla informacji kontaktowych
    name = new char[strlen(n) + 1];
    phone = new char[strlen(p) + 1];

    // Skopiowanie imienia, nazwiska i numeru telefonu do zaalokowanych obszarów pamięci
    strcpy(name, n);
    strcpy(phone, p);
  }

  // Destruktor
  ~ContactInfo()
  {
    delete[] name;
    delete[] phone;
  }

  const char *getName() const
  {
    return name;
  }

  const char *getPhoneNumber() const
  {
    return phone;
  }
};
#endif
