// Plik specyfikacji klasy Rectangle
// Ta wersja klasy zawiera konstruktora.
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
  double width;
  double length;
public:
  Rectangle();               // Konstruktor
  void setWidth(double);
  void setLength(double);

  double getWidth() const
    { return width; }

  double getLength() const
    { return length; }

  double getArea() const
    { return width * length; }
};
#endif
