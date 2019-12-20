#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

// Szablon klasy stosu
template <class T>
class Stack
{
private:
  T * stackArray;
  int stackSize;
  int top;

public:
  // Konstruktor
  Stack(int);

  // Konstruktor kopiujący
  Stack(const Stack&);

  // Destruktor
  ~Stack();

  // Operacje na stosie
  void push(T);
  void pop(T &);
  bool isFull();
  bool isEmpty();
};

//***************************************************
// Konstruktor
//***************************************************

template <class T>
Stack<T>::Stack(int size)
{
  stackArray = new T[size];
  stackSize = size;
  top = -1;
}

//***************************************************
// Konstruktor kopiujący
//***************************************************

template <class T>
Stack<T>::Stack(const Stack &obj)
{
  // Utworzenie tablicy odgrywającej rolę stosu
  if (obj.stackSize > 0)
    stackArray = new T[obj.stackSize];
  else
    stackArray = nullptr;

  // Skopiowanie wartości zmiennej stackSize
  stackSize = obj.stackSize;

  // Skopiowanie zawartości stosu
  for (int count = 0; count < stackSize; count++)
    stackArray[count] = obj.stackArray[count];

  // Ustawienie szczytu stosu
  top = obj.top;
}

//***************************************************
// Destruktor
//***************************************************

template <class T>
Stack<T>::~Stack()
{
  if (stackSize > 0)
    delete[] stackArray;
}

//*************************************************************
// Funkcja push() odkłada wartość
// na stosie.
//*************************************************************

template <class T>
void Stack<T>::push(T item)
{
  if (isFull())
  {
    cout << "Stos jest pełny.\n";
  }
  else
  {
    top++;
    stackArray[top] = item;
  }
}

//*************************************************************
// Funkcja pop() zdejmuje wartość
// ze szczytu stosu i zapisuje ją
// w zmiennej wskazanej w argumencie.
//*************************************************************

template <class T>
void Stack<T>::pop(T &item)
{
  if (isEmpty())
  {
    cout << "Stos jest pusty.\n";
  }
  else
  {
    item = stackArray[top];
    top--;
  }
}

//*************************************************************
// Funkcja isFull() zwraca wartość true jeżeli
// stos jest pełny lub false w przeciwnym razie.
//*************************************************************

template <class T>
bool Stack<T>::isFull()
{
  bool status;

  if (top == stackSize - 1)
    status = true;
  else
    status = false;

  return status;
}

//*************************************************************
// Funkcja isEmpty() zwraca wartość true jeżeli
// stos jest pusty lub false w przeciwnym razie.
//*************************************************************

template <class T>
bool Stack<T>::isEmpty()
{
  bool status;

  if (top == -1)
    status = true;
  else
    status = false;

  return status;
}
#endif
