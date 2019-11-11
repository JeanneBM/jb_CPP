#include <iostream>

using namespace std;

void fun1(int a){
    a=1;
}
void fun2(int *pa){
    *pa=2;
}
void fun3(int & a){
    a=3;
}

int main(){
    int a = 6;
    cout << a << endl;
    fun1(a);
    cout << a << endl;
    fun2(&a);
    cout << a << endl;
    fun3(a);
    cout << a << endl;
    int & b; // this will not compile
}
