#include <iostream>

using namespace std;

class student{
  public:
    int numerindeksu;
    void setOcena(float o){ocenazcpp=o;}
    void print(void)
    {
      cout << " Student " << numerindeksu << " recived " << ocenazcpp << endl;
    }
    float ocenazcpp;
};

int main(){
  student s1,s2;
  s1.numerindeksu = 207778;
  s1.setOcena(5.0);
  
  s1.print();
}
