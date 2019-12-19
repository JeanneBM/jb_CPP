#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
using namespace std;

// Szablon klasy stosu
template <class T>
class DynamicStack
{
private:
  // Struktura elementu listy
  struct StackNode
  {
    T value;         // Wartość przechowywania w węźle
    StackNode *next; // Wskaźnik do następnego elementu
  };

  StackNode *top; // Wskaźnik szczytu stosu

public:
  //Konstruktor
  DynamicStack()
    { top = nullptr; }

  // Destruktor
  ~DynamicStack();

  // Operacje na stosie
  void push(T);
  void pop(T &);
  bool isEmpty();
};

//***************************************************
// Destruktor
//***************************************************
template <class T>
DynamicStack<T>::~DynamicStack()
{
  StackNode *nodePtr, *nextNode;

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

//*************************************************************
// Funkcja push() odkładająca na stosie
// wartość argumentu
//*************************************************************

template <class T>
void DynamicStack<T>::push(T item)
{
  StackNode *newNode = nullptr; // Wskaźnik nowego elementu

  // Utworzenie nowego elementu i zapisanie w nim wartości argumentu num
  newNode = new StackNode;
  newNode->value = item;

  // Jeżeli w liście nie ma elementów
  // newNode jest wstawiany jako pierwszy.
  if (isEmpty())
  {
    top = newNode;
    newNode->next = nullptr;
  }
  else  // W przeciwnym razie element newNode jest wstawiany przed wskaźnikiem top
  {
    newNode->next = top;
    top = newNode;
  }
}

//*************************************************************
// Funkcja pop() zdejmująca wartość
// ze szczytu stosu i zapisującą ją w zmiennej
// wskazanej w argumencie.
//*************************************************************

template <class T>
void DynamicStack<T>::pop(T &item)
{
  StackNode *temp = nullptr; // Tymczasowy wskaźnik

  // Sprawdzenie, czy stos nie jest pusty
  if (isEmpty())
  {
    cout << "Stos jest pusty.\n";
  }
  else // Zdjęcie wartości ze stosu
  {
    item = top->value;
    temp = top->next;
    delete top;
    top = temp;
  }
}

//*************************************************************
// Funkcja isEmpty() zwracająca wartość true jeżeli
// stos jest pusty, lub false w przeciwnym razie.
//*************************************************************

template <class T>
bool DynamicStack<T>::isEmpty()
{
  bool status;

  if (!top)
    status = true;
  else
    status = false;

  return status;
}
#endif
