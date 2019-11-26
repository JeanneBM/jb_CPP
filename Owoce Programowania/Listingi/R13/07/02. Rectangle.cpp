// Ten program demonstruje użycie konstruktora klasy Rectangle.
#include <iostream>
#include "Rectangle.h" // Instrukcja wymagana przez klasę Rectangle
using namespace std;

int main()
{
  Rectangle box;    // Definicja instancji klasy Rectangle

  // Wyświetlenie danych prostokąta
  cout << "Dane prostokąta:\n";
  cout << "Szerokość: " << box.getWidth() << endl;
  cout << "Długość: " << box.getLength() << endl;
  cout << "Pole: " << box.getArea() << endl;
  return 0;
}
