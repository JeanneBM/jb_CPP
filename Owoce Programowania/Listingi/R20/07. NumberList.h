// Plik specyfikacji klasy NumberList
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
  // Deklaracja struktury węzła listy
  struct ListNode
  {
    double value;
    struct ListNode *next;
  };

  ListNode *head;    // Wskaźnik nagłówka listy

  // Prywatne funkcje członkowskie
  int countNodes(ListNode *) const;
  void showReverse(ListNode *) const;

public:
  // Konstruktor
  NumberList()
    { head = nullptr; }

  // Destruktor
  ~NumberList();

  // Operacje na liście łączonej
  void appendNode(double);
  void insertNode(double);
  void deleteNode(double);
  void displayList() const;
  int numNodes() const
    { return countNodes(head); }
  void displayBackwards() const
    { showReverse(head); }
};
#endif
