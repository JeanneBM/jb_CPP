#include <iostream>
#include "DynIntStack.h"
using namespace std;

//**************************************************
// Destruktor
// Destruktor usuwa wszystkie elementy z listy.
//**************************************************

DynIntStack::~DynIntStack()
{
  StackNode *nodePtr = nullptr, *nextNode = nullptr;

  // Ustawienie zmiennej nodePtr na szczycie stosu
  nodePtr = top;

  // Przeglądanie listy i usuwanie kolejnych elementów
  while (nodePtr != nullptr)
  {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
}

//*************************************************
// Funkcja push() odkłada na stosie
// wartość argumentu.
//*************************************************

void DynIntStack::push(int num)
{
  StackNode *newNode = nullptr; // Wskaźnik nowego elementu

  // Utworzenie nowego elementu i zapisanie w nim wartości argumentu num.
  newNode = new StackNode;
  newNode->value = num;

  // Jeżeli w liście nie ma elementów,
  // newNode jest wstawiany jako pierwszy.
  if (isEmpty())
  {
    top = newNode;
    newNode->next = nullptr;
  }
  else  // W przeciwnym razie element newNode jest wstawiany przed wskaźnikiem top.
  {
    newNode->next = top;
    top = newNode;
  }
}

//*****************************************************
// Funkcja pop() zdejmuje wartość
// ze szczytu stosu i zapisuje ją w zmiennej
// wskazanej w argumencie.
//*****************************************************

void DynIntStack::pop(int &num)
{
  StackNode *temp = nullptr; // Tymczasowy wskaźnik

  // Sprawdzenie, czy stos nie jest pusty
  if (isEmpty())
  {
    cout << "Stos jest pusty.\n";
  }
  else // Zdjęcie wartości ze stosu
  {
    num = top->value;
    temp = top->next;
    delete top;
    top = temp;
  }
}

//*****************************************************
// Funkcja isEmpty() zwraca wartość true jeżeli
// stos jest pusty, lub false w przeciwnym razie.
//*****************************************************

bool DynIntStack::isEmpty()
{
  bool status;

  if (!top)
    status = true;
  else
    status = false;

  return status;
}
