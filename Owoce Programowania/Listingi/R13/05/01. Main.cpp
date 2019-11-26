// Ten program wykorzystuje klasę Rectangle zadeklarowaną
// w pliku Rectangle.h. Funkcje członkowskie klasy są
// zdefiniowane w pliku Rectangle.cpp. Ten program musi
// być zostać skompilowany z powyższymi plikami.
#include <iostream>
#include "Rectangle.h" // Instrukcja wymagana przez klasę Rectangle
using namespace std;

int main()
{
  Rectangle box;     // Definicja instancji klasy Rectangle
  double rectWidth;  // Lokalna zmienna przechowująca wartość zmiennej width
  double rectLength; // Lokalna zmienna przechowująca wartość zmiennej length

  // Podanie szerokości i długości prostokąta przez użytkownika
  cout << "Ten program wylicza pole\n";
  cout << "prostokąta. Podaj szerokość: ";
  cin >> rectWidth;
  cout << "Podaj długość: ";
  cin >> rectLength;

  // Zapisanie szerokości i długości prostokąta
  // w obiekcie box
  box.setWidth(rectWidth);
  box.setLength(rectLength);

  // Wyświetlenie danych prostokąta
  cout << "Dane prostokąta:\n";
  cout << "Szerokość: " << box.getWidth() << endl;
  cout << "Długość: " << box.getLength() << endl;
  cout << "Pole: " << box.getArea() << endl;
  return 0;
}
