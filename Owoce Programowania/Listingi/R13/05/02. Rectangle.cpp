// Plik implementacji klasy Rectangle.
// W tej wersji klasy funkcje getWidth(), getLength() i getArea()
// są zadeklarowane jako œródwierszowe w pliku Rectangle.h.
#include "Rectangle.h" // Instrukcja wymagana przez klasê Rectangle
#include <iostream>    // Instrukcja wymagana przez obiekt cout
#include <cstdlib>     // Instrukcja wymagana przez funkcjê exit()
using namespace std;

//***********************************************************
// Funkcja setWidth() przypisuje wartoœæ zmiennej członkowskiej width.
//***********************************************************

void Rectangle::setWidth(double w)
{
  if (w >= 0)
    width = w;
  else
  {
    cout << "B³êdna szerokoœæ\n";
    exit(EXIT_FAILURE);
  }
}

//***********************************************************
// Funkcja setLength() przypisuje wartoœæ zmiennej cz³onkowskiej length.
//***********************************************************

void Rectangle::setLength(double len)
{
  if (len >= 0)
    length = len;
  else
  {
    cout << "B³êdna d³ugoœæ\n";
    exit(EXIT_FAILURE);
  }
}
