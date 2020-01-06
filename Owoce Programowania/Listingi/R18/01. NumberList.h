// Plik specyfikacji klasy NumberList
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
  // Deklaracja struktury do tworzenia listy
  struct ListNode
  {
    double value;           // Wartość przechowywana w węźle
    struct ListNode *next;  // Wskaźnik następnego węzła
  };

  ListNode *head;           // Nagłówek listy

public:
  // Konstruktor
  NumberList()
    { head = nullptr; }

  // Destruktor
  ~NumberList();

  // Operacje na liście połączonej
  void appendNode(double);
  void insertNode(double);
  void deleteNode(double);
  void displayList() const;
};
#endif
