// Ten program demonstruje użycie szablonu klasy Stack.
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

// Stałe reprezentujące opcje menu
const int PUSH_CHOICE = 1,
          POP_CHOICE = 2,
          QUIT_CHOICE = 3;

// Prototypy funkcji
void menu(int &);
void getStackSize(int &);
void pushItem(Stack<string>&);
void popItem(Stack<string>&);

int main()
{
  int stackSize; // Wielkość stosu
  int choice;    // Wybrana opcja menu

  // Uzyskanie wielkości stosu
  getStackSize(stackSize);

  // Utworzenie stosu.
  Stack<string> stack(stackSize);

  do
  {
    // Uzyskanie opcji menu wybranej przez użytkownika
    menu(choice);

    // Wykonanie operacji wybranej przez użytkownika
    if (choice != QUIT_CHOICE)
    {
      switch (choice)
      {
      case PUSH_CHOICE:
        pushItem(stack);
        break;
      case POP_CHOICE:
        popItem(stack);
      }
    }
  } while (choice != QUIT_CHOICE);

  return 0;
}

//************************************************
// Funkcja getStackSize() prosi użytkownika
// o podane wielkości stosu, którą
// zapisuje w zmiennej podanej w argumencie.
//************************************************
void getStackSize(int &size)
{
  // Pobranie żądanej wielkości stosu
  cout << "Jak duży ma być stos? ";
  cin >> size;

  // Sprawdzenie wielkości
  while (size < 1)
  {
    cout << "Wprowadź liczbę 1 lub większą: ";
    cin >> size;
  }
}

//************************************************
// Funkcja menu() wyświetla menu i pobiera opcję
// wybraną przez użytkownika, którą następnie
// przypisuje zmiennej wskazanej w argumencie.
//************************************************
void menu(int &choice)
{
  // Wyświetlenie menu i pobranie opcji użytkownika
  cout << "\nCo chcesz zrobić?\n"
       << PUSH_CHOICE
       << " - Odłożyć dane na stosie\n"
       << POP_CHOICE
       << " - Zdjąć dane ze stosu\n"
       << QUIT_CHOICE
       << " - Zamknąć program\n"
       << "Podaj opcję: ";
  cin >> choice;

  // Sprawdzenie opcji
  while (choice < PUSH_CHOICE || choice > QUIT_CHOICE)
  {
    cout << "Podaj poprawną opcję: ";
    cin >> choice;
  }
}

//************************************************
// Funkcja pushItem() odczytuje dane wprowadzone przez
// użytkownika i odkłada je na stosie.
//************************************************
void pushItem(Stack<string> &stack)
{
  string item;

  // Odczytanie danych i odłożenie ich na stosie
  cin.ignore();
  cout << "\nPodaj dane: ";
  getline(cin, item);
  stack.push(item);
}

//****************************************************
// Funkcja popItem() zdejmuje dane ze stosu.
//****************************************************
void popItem(Stack<string> &stack)
{
  string item = "";

  // Zdjęcie danych ze stosu
  stack.pop(item);

  // Wyświetlenie danych
  if (item != "")
    cout << "Zdjęte dane: " << item << "\n";
}
