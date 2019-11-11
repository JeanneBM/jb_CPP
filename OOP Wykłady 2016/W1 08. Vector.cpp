#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a(5);
    a[0] = 10;
    for(int i=1; i<a.size(); ++i){
        a[i] = 10*(i+1);
        cout << a[i] << endl;
    }
    cout << endl;
    a.pop_back();
    a.push_back(1);
    for(int i=0; i<a.size(); ++i)
        cout << a[i] << endl;
}
