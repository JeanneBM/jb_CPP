#include <iostream>

using namespace std;

class foobar{
public:
  void setFoo(int f){foo=f;}
  int getFoo(){return foo;}
  const int& cFoo(){return foo;}
  int& rFoo(){return foo;}
  
private:
  int foo;
};

int main()
{
  foobar fu1;
  fu1.setFoo(2);
  cout << fu1.cFoo() << " " << fu1.rFoo() << endl; 
  fu1.rFoo() = 7;
  //fu1.cFoo() = 7;
  cout << fu1.cFoo() << " " << fu1.rFoo() << endl; 
}
