#include <iostream>

using namespace std;

class foobar{
  public:

    foobar(int aa, int bb=9): a(aa), b(bb)
    {
      cout << "I am created with the parametric constructor" << endl;
      a=5;
      b=7;
    }
    void print()
    {
      cout << a << " " << b << endl;
    }
    
  private:
    int& a; //referencje
    int& b;
};

int main(){
  int a=5, b=9;

  foobar f2(3);
  foobar f3(a,b);

  f2.print();
  f3.print();
  
}
