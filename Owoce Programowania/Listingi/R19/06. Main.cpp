// Ten program demonstruje użycie adaptera
// kontenera stack.
#include <iostream>
#include <vector>
#include <stack.h>
using namespace std;

int main()
{
  const int MAX = 8;   // Maksymalna wartość do umieszczenia na stosie
  int count;           // Licznik obiegów pętli

  // Definicja stosu
  stack< int, vector<int> > iStack;

  // Odłożenie wartości na stosie
  for (count = 2; count < MAX; count += 2)
  {
    cout << "Odkładanie wartości " << count << endl;
    iStack.push(count);
  }

  // Wyświetlenie wielkości stosu
  cout << "Wielkość stosu: ";
  cout << iStack.size() << endl;

  // Zdjęcie wartości ze stosu
  for (count = 2; count < MAX; count += 2)
  {
    cout << "Zdejmowanie wartości " << iStack.top() << endl;
    iStack.pop();
  }
  return 0;
}
