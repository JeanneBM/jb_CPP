#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Szablon klasy BinaryTree
template <class T>
class BinaryTree
{
private:
  struct TreeNode
  {
    T value;           // Wartość przechowywana w węźle
    TreeNode *left;    // Wskaźnik do lewego węzła pochodnego
    TreeNode *right;   // Wskaźnik do prawego węzła pochodnego
  };

  TreeNode *root; // Wskaźnik do węzła głównego

  // Prywatne funkcje członkowskie
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(T, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;

public:
  // Konstruktor
  BinaryTree()
    { root = nullptr; }

  // Destruktor
  ~BinaryTree()
    { destroySubTree(root); }

  // Operacje na drzewie binarnym
  void insertNode(T);
  bool searchNode(T);
  void remove(T);

  void displayInOrder() const
    { displayInOrder(root); }

  void displayPreOrder() const
    { displayPreOrder(root); }

  void displayPostOrder() const
    { displayPostOrder(root); }
};

//*************************************************************
// Funkcja insert() wstawia w drzewie wskazywanym w argumencie
// nodePtr węzeł wskazywany w argumencie newNode.
// Funkcja jest wywoływana rekurencyjne.
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == nullptr)
    nodePtr = newNode;               // Wstawienie węzła
  else if (newNode->value < nodePtr->value)
    insert(nodePtr->left, newNode);  // Przeszukanie lewego poddrzewa
  else
    insert(nodePtr->right, newNode); // Przeszukanie prawego poddrzewa
}

//***********************************************************
// Funkcja insertNode() tworzy nowy węzeł, zapisuje w jego zmiennej value
// wartość argumentu num i umieszcza go w argumencie funkcji insert().
//***********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
  TreeNode *newNode = nullptr;  // Wskaźnik nowego węzła

  // Utworzenie nowego węzła i zapisanie w nim argumentu num
  newNode = new TreeNode;
  newNode->value = item;
  newNode->left = newNode->right = nullptr;

  // Wstawienie węzła
  insert(root, newNode);
}

//***************************************************
// Funkcja destroySubTree() wywoływana przez destruktor,
// usuwa wszystkie węzły drzewa.
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
  if (nodePtr)
  {
    if (nodePtr->left)
      destroySubTree(nodePtr->left);
    if (nodePtr->right)
      destroySubTree(nodePtr->right);
    delete nodePtr;
  }
}

//***************************************************
// Funkcja searchNode() zwraca wynik true, jeżeli
// szukana wartość jest zapisana w drzewie, lub false
// w przeciwnym razie.
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
  TreeNode *nodePtr = root;

  while (nodePtr)
  {
    if (nodePtr->value == item)
      return true;
    else if (item < nodePtr->value)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  return false;
}

//***********************************************
// Funkcja remove() wywołuje funkcję deleteNode() w celu usunięcia
// węzła zawierającego wartość podaną w argumencie num.
//***********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
  deleteNode(item, root);
}

//********************************************
// Funkcja deleteNode() usuwa węzeł, którego zmienna value
// zawiera wartość podaną w argumencie num.
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
  if (item < nodePtr->value)
    deleteNode(item, nodePtr->left);
  else if (item > nodePtr->value)
    deleteNode(item, nodePtr->right);
  else
    makeDeletion(nodePtr);
}

//***********************************************************
// Funkcja makeDeletion() usuwająca węzeł, którego referencja
// jest podana w argumencie. Funkcja po usunięciu węzła
// przyłącza z powrotem poddrzewa.
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
  // Definicja tymczasowego wskaźnika wykorzystywanego
  // do przyłączenia lewego poddrzewa
  TreeNode *tempNodePtr = nullptr;

  if (nodePtr == nullptr)
    cout << "Nie można usunąć pustego węzła.\n";
  else if (nodePtr->right == nullptr)
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->left;   // Przyłączenie lewego poddrzewa
    delete tempNodePtr;
  }
  else if (nodePtr->left == nullptr)
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right;  // Przyłączenie prawego poddrzewa
    delete tempNodePtr;
  }
  // Jeżeli węzeł ma dwa węzły pochodne
  else
  {
    // Przeniesienie jednego węzła do prawego poddrzewa
    tempNodePtr = nodePtr->right;
    // Przejście na koniec lewego poddrzewa
    while (tempNodePtr->left)
      tempNodePtr = tempNodePtr->left;
    // Przyłączenie lewego poddrzewa
    tempNodePtr->left = nodePtr->left;
    tempNodePtr = nodePtr;
    // Przyłączenie prawego poddrzewa
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
}

//*************************************************************
// Funkcja displayInOrder() wyświetla w przejściu poprzecznym
// wartości zawarte w drzewie wskazywanym przez nodePtr.
//*************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    displayInOrder(nodePtr->left);
    cout << nodePtr->value << endl;
    displayInOrder(nodePtr->right);
  }
}

//*************************************************************
// Funkcja displayPreOrder() wyświetla w przejściu wzdłużnym
// wartości zawarte w drzewie wskazywanym przez nodePtr.
//*************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    cout << nodePtr->value << endl;
    displayPreOrder(nodePtr->left);
    displayPreOrder(nodePtr->right);
  }
}

//*************************************************************
// Funkcja displayPostOrder() wyświetla w przejściu wstecznym
// wartości zawarte w drzewie wskazywanym przez nodePtr.
//*************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    displayPostOrder(nodePtr->left);
    displayPostOrder(nodePtr->right);
    cout << nodePtr->value << endl;
  }
}
#endif
