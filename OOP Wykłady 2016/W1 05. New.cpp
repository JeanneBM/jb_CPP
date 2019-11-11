#include <iostream>
#include <vector>

using namespace std;

struct D{
    int a;
};

int main(){
    int n=10;
    D * p = new D;
    D * tab = new D[50];
    tab[8].a = 1;
    cout << tab[8].a << endl;
    delete p;
    delete []tab;
}
