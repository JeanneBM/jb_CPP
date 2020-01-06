// Szablon klasy do tworzenia listy łączonej
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>    // Plik wymagany przez obiekt cout
using namespace std;

template <class T>
class LinkedList
{
private:
  // Deklaracja struktury wykorzystywanej w liście
  struct ListNode
  {
    T value;                // Wartość przechowywana w węźle
    struct ListNode *next;  // Zmienna wskazująca następny węzeł
  };

  ListNode *head;   // Wskaźnik nagłówka listy

public:
  // Konstruktor
  LinkedList()
    { head = nullptr; }

  // Destruktor
  ~LinkedList();

  // Operacje na liście
  void appendNode(T);
  void insertNode(T);
  void deleteNode(T);
  void displayList() const;
};


//**************************************************
// Funkcja appendNode() umieszcza na końcu listy węzeł 
// zawierający wartość podaną w argumencie newValue.
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
  ListNode *newNode;  // Zmienna wskazująca nowy węzeł
  ListNode *nodePtr;  // Zmienna do przeglądania listy

  // Utworzenie nowego węzła i zapisanie w nim argumentu newValue
  newNode = new ListNode;
  newNode->value = newValue;
  newNode->next = nullptr;

  // Jeżeli lista nie zawiera węzłów,
  // jako pierwszy wstawiany jest newNode.
  if (!head)
    head = newNode;
  else  // W przeciwnym razie zmienna newNode umieszczana jest na końcu listy.
  {
    // Ustawienie wskaźnika nodePtr na początku listy
    nodePtr = head;

    // Wyszukanie ostatniego węzła listy
    while (nodePtr->next)
      nodePtr = nodePtr->next;

    // Wstawienie newNode jako ostatniego węzła listy
    nodePtr->next = newNode;
  }
}

//**************************************************
// Funkcja displayList() wyświetla wartości
// zapisane we wszystkich węzłach listy
// wskazywanej przez nagłówek head.
//**************************************************

template <class T>
void LinkedList<T>::displayList() const
{
  ListNode *nodePtr; // Zmienna do przeglądania listy

  // Ustawienie wskaźnika nodePtr na początku listy
  nodePtr = head;

  // Przeglądanie listy dopóki
  // nodePtr wskazuje węzeł
  while (nodePtr)
  {
    // Wyświetlenie zawartości bieżącego węzła
    cout << nodePtr->value << endl;

    // Przejście do następnego węzła
    nodePtr = nodePtr->next;
  }
}

//**************************************************
// Funkcja insertNode() wstawiająca nowy węzeł
// z wartością podaną w argumencie newValue.
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
  ListNode *newNode;                 // Wskaźnik nowego węzła
  ListNode *nodePtr;                 // Zmienna do przeglądania listy
  ListNode *previousNode = nullptr;  // Wskaźnik poprzedniego węzła

  // Utworzenie nowego węzła i zapisanie w nim argumentu newValue
  newNode = new ListNode;
  newNode->value = newValue;

  // Jeżeli lista nie zawiera węzłów
  // jako pierwszy wstawiany jest newNode
  if (!head)
  {
    head = newNode;
    newNode->next = nullptr;
  }
  else // W przeciwnym razie zmienna newNode umieszczana jest na końcu listy
  {
    // Ustawienie wskaźnika nodePtr na początku listy
    nodePtr = head;

    // Zainicjowanie zmiennej previousNode wartością nullptr
    previousNode = nullptr;

    // Pomięcie wszystkich węzłów zawierających wartość mniejszą niż newValue
    while (nodePtr != nullptr && nodePtr->value < newValue)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    // Jeżeli nowy węzeł ma być pierwszy w liście,
    // zostanie wstawiony przed wszystkimi węzłami.
    if (previousNode == nullptr)
    {
      head = newNode;
      newNode->next = nodePtr;
    }
    else // W przeciwnym razie zostanie wstawiony za poprzednim węzłem
    {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
}

//******************************************************
// Funkcja deleteNode() wyszukuje węzeł zawierający
// wartość równą searchValue. Jeżeli węzeł zostanie znaleziony,
// jest usuwany z listy i pamięci.
//******************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
  ListNode *nodePtr;       // Zmienna do przeglądania listy
  ListNode *previousNode;  // Zmienna wskazująca poprzedni węzeł

  // Jeśli lista jest pusta, nie rób nic
  if (!head)
    return;

  // Sprawdzenie, czy pierwszy węzeł to ten właściwy
  if (head->value == searchValue)
  {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  }
  else
  {
    // Ustawienie wskaźnika nodePtr na początku listy
    nodePtr = head;

    // Pominięcie wszystkich węzłów, których zmienna value
    // nie jest równa searchValue
    while (nodePtr != nullptr && nodePtr->value != searchValue)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    // Jeżeli nodePtr nie wskazuje końca listy, poprzedni
    // węzeł jest łączony z węzłem znajdującym się za nodePtr,
    // a następnie usuwany jest węzeł nodePtr.
    if (nodePtr)
    {
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

//**************************************************
// Destruktor
// Usuwa wszystkie węzły listy.
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
  ListNode *nodePtr;   // Zmienna do przeglądania listy
  ListNode *nextNode;  // Zmienna wskazująca następny węzeł

  // Ustawienie wskaźnika nodePtr na początku listy
  nodePtr = head;

  // Dopóki nodePtr nie wskazuje końca listy...
  while (nodePtr != nullptr)
  {
    // ...wskaźnik jest ustawiany na następnym węźle, ...
    nextNode = nodePtr->next;

    // ...usuwany jest bieżący węzeł, ...
    delete nodePtr;

    // ...zmienna nodePtr jest ustawiana na następnym węźle.
    nodePtr = nextNode;
  }
}
#endif
