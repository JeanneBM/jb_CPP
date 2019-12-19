// Plik specyfikacji klasy IntBinaryTree
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
  struct TreeNode
  {
    int value;        // Wartość przechowywana w węźle
    TreeNode *left;   // Wskaźnik do lewego węzła pochodnego
    TreeNode *right;  // Wskaźnik do prawego węzła pochodnego
  };

  TreeNode *root;     // Wskaźnik do węzła głównego

  // Prywatne funkcje członkowskie
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(int, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;

public:
  // Konstruktor
  IntBinaryTree()
    { root = nullptr; }

  // Destruktor
  ~IntBinaryTree()
    { destroySubTree(root); }

  // Operacje na drzewie binarnym
  void insertNode(int);
  bool searchNode(int);
  void remove(int);

  void displayInOrder() const
    { displayInOrder(root); }

  void displayPreOrder() const
    { displayPreOrder(root); }

  void displayPostOrder() const
    { displayPostOrder(root); }
};
#endif
