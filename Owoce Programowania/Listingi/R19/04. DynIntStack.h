// Plik specyfikacji klasy DynIntStack
#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H

class DynIntStack
{
private:
  // Struktura elementu listy
  struct StackNode
  {
    int value;       // Wartość przechowywania w elemencie
    StackNode *next; // Wskaźnik do następnego elementu
  };

  StackNode *top; // Wskaźnik szczytu stosu

public:
  // Konstruktor
  DynIntStack()
  {
    top = nullptr;
  }

  // Destruktor
  ~DynIntStack();

  // Operacje na stosie
  void push(int);
  void pop(int &);
  bool isEmpty();
};
#endif
