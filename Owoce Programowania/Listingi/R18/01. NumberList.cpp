// Plik implementacji klasy NumberList
#include <iostream>  // Plik wymagany przez strumień cout
#include "NumberList.h"
using namespace std;

//**************************************************
// Funkcja appendNode() dołącza na końcu listy
// węzeł z zwartością podaną w argumencie num.
//**************************************************

void NumberList::appendNode(double num)
{
  ListNode *newNode;  // Zmienna wskazująca nowy węzeł
  ListNode *nodePtr;  // Zmienna do przeglądania listy

  // Utworzenie nowego węzła i zapisanie w nim liczby
  newNode = new ListNode;
  newNode->value = num;
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

void NumberList::displayList() const
{
  ListNode *nodePtr;  // Zmienna do przeglądania listy.

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
// z wartością podaną w argumencie num.
//**************************************************

void NumberList::insertNode(double num)
{
  ListNode *newNode;                // Wskaźnik nowego węzła
  ListNode *nodePtr;                // Zmienna do przeglądania listy
  ListNode *previousNode = nullptr;  // Wskaźnik poprzedniego węzła

  // Utworzenie nowego węzła i zapisanie w nim argumentu num
  newNode = new ListNode;
  newNode->value = num;
   
  // Jeżeli lista nie zawiera węzłów,
  // jako pierwszy wstawiany jest newNode
  if (!head)
  {
    head = newNode;
    newNode->next = nullptr;
  }
  else  // W przeciwnym razie zmienna newNode umieszczana jest na końcu listy
  {
    // Ustawienie wskaźnika nodePtr na początku listy
    nodePtr = head;

    // Zainicjowanie zmiennej previousNode wartością nullptr
    previousNode = nullptr;

    // Pomięcie wszystkich węzłów zawierających wartość mniejszą niż num
    while (nodePtr != nullptr && nodePtr->value < num)
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
    else  // W przeciwnym razie zostanie wstawiony za poprzednim węzłem
    {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
}

//**************************************************
// Funkcja deleteNode() wyszukuje węzeł zawierający
// wartość równą num. Jeżeli węzeł zostanie znaleziony,
// jest usuwany z listy i pamięci.
//**************************************************

void NumberList::deleteNode(double num)
{
  ListNode *nodePtr;       // Zmienna do przeglądania listy
  ListNode *previousNode;  // Zmienna wskazująca poprzedni węzeł

  // Jeśli lista jest pusta, nie rób nic
  if (!head)
    return;
 
  // Sprawdzenie, czy pierwszy węzeł to ten właściwy
  if (head->value == num)
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
    // nie jest równa num
    while (nodePtr != nullptr && nodePtr->value != num)
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

NumberList::~NumberList()
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
