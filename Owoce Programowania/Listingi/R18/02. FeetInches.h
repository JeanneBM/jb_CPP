// Plik specyfikacji klasy FeetInches.
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches; // Deklaracja wyprzedzająca

// Prototypy funkcji przeciążających operatory strumieniowe
ostream &operator << (ostream &, const FeetInches &);
istream &operator >> (istream &, FeetInches &);

// Klasa FeetInches zawiera odległość
// lub wymiar wyrażony w stopach i calach.

class FeetInches
{
private:
  int feet;         // Zmienna zawierająca liczbę stóp
  int inches;       // Zmienna zawierająca liczbę cali
  void simplify();  // Funkcja zdefiniowana w pliku FeetInches.cpp
public:
  // Konstruktor
  FeetInches(int f = 0, int i = 0)
    { feet = f;
      inches = i;
      simplify(); }

  // Mutatory
  void setFeet(int f)
    { feet = f; }

  void setInches(int i)
    { inches = i;
      simplify(); }

  // Akcesory
  int getFeet() const
    { return feet; }

  int getInches() const
    { return inches; }

  // Funkcje przeciążonych operatorów
  FeetInches operator + (const FeetInches &); // Przeciążony operator +
  FeetInches operator - (const FeetInches &); // Przeciążony operator -
  FeetInches operator ++ ();     // Przeciążony prefiksowy operator ++
  FeetInches operator ++ (int);  // Przeciążony sufiksowy operator ++
  bool operator > (const FeetInches &);  // Przeciążony operator >
  bool operator < (const FeetInches &);  // Przeciążony operator <
  bool operator == (const FeetInches &); // Przeciążony operator ==
  bool operator != (const FeetInches &); // Przeciążony operator !=

  // Funkcje konwertujące
  operator double();
  operator int();

  // Funkcje zaprzyjaźnione
  friend ostream &operator << (ostream &, const FeetInches &);
  friend istream &operator >> (istream &, FeetInches &);
};

#endif
