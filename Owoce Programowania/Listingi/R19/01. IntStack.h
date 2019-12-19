// Plik specyfikacji klasy IntStack
#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
private:
  int *stackArray;  // Wskaźnik do tablicy wykorzystywanej jako stos
  int stackSize;    // Wielkość stosu
  int top;          // Zmienna oznaczająca szczyt stosu

public:
  // Konstruktor
  IntStack(int);

  // Konstruktor kopiujący
  IntStack(const IntStack &);

  // Destruktor
  ~IntStack();

  // Operacje na stosie
  void push(int);
  void pop(int &);
  bool isFull() const;
  bool isEmpty() const;
};
#endif
