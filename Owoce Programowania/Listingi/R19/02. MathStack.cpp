// Plik implementacji klasy MathStack
#include "MathStack.h"

//************************************************
// Funkcja add() zdejmuje ze stosu
// dwie wartości, dodaje je do siebie
// i wynik odkłada na stosie.
//************************************************

void MathStack::add()
{
  int num, sum;

  // Zdjęcie ze stosu dwóch wartości
  pop(sum);
  pop(num);

  // Dodanie wartości i zapisanie wyniku w zmiennej sum
  sum += num;

  // Odłożenie zmiennej sum na stosie
  push(sum);
}

//***********************************************
// Funkcja sub() zdejmuje ze
// stosu dwie wartości, następnie
// odejmuje drugą wartość
// od pierwszej i odkłada wynik
// na stosie.
//***********************************************

void MathStack::sub()
{
  int num, diff;

  // Zdjęcie ze stosu dwóch wartości
  pop(diff);
  pop(num);

  // Odjęcie zmiennej num od zmiennej diff
  diff -= num;

  // Odłożenie zmiennej diff na stosie
  push(diff);
}
