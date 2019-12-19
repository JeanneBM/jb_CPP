// Plik implementacji klasy IntStack
#include <iostream>
#include "IntStack.h"
using namespace std;

//************************************************
// Konstruktor
// Konstruktor tworzy pusty stos. Argument size
// oznacza wielkość stosu.
//************************************************

IntStack::IntStack(int size)
{
  stackArray = new int[size];
  stackSize = size;
  top = -1;
}

//***********************************************
// Konstruktor kopiujący
//***********************************************

IntStack::IntStack(const IntStack &obj)
{
  // Utworzenie tablicy odgrywającej rolę stosu
  if (obj.stackSize > 0)
    stackArray = new int[obj.stackSize];
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

//***********************************************
// Destruktor
//***********************************************

IntStack::~IntStack()
{
  delete[] stackArray;
}

//*************************************************
// Funkcja push() odkłada wartość
// na stosie.
//*************************************************

void IntStack::push(int num)
{
  if (isFull())
  {
    cout << "Stos jest pełny.\n";
  }
  else
  {
    top++;
    stackArray[top] = num;
  }
}

//*****************************************************
// Funkcja pop() zdejmuje wartość
// ze szczytu stosu i zapisuje ją
// w zmiennej wskazanej w argumencie.
//*****************************************************

void IntStack::pop(int &num)
{
  if (isEmpty())
  {
    cout << "Stos jest pusty.\n";
  }
  else
  {
    num = stackArray[top];
    top--;
  }
}

//***************************************************
// Funkcja isFull() zwraca wartość true jeżeli
// stos jest pełny lub false w przeciwnym razie.
//***************************************************

bool IntStack::isFull() const
{
  bool status;

  if (top == stackSize - 1)
    status = true;
  else
    status = false;

  return status;
}

//*****************************************************
// Funkcja isEmpty() zwraca wartość true jeżeli
// stos jest pusty lub false w przeciwnym razie.
//*****************************************************

bool IntStack::isEmpty() const
{
  bool status;

  if (top == -1)
    status = true;
  else
    status = false;

  return status;
}
