#include <iostream>
#include <stdlib.h>

using namespace std;

class collection{
  public:
    collection(){size=0; tab=NULL;}
    collection(int s) : size(s) {allocate();}
    collection(collection& c){
        size=getSize();
        //tab = ????
    }
    ~collection(){
        cout << "The cleaning service!" << endl;
        delete []tab;
    }

    void setSize(int a){ size=a; }
    int getSize(){ return size; }
    void allocate();
    int& rTab(int i){ return tab[i];}
  private:
    int size;
    int * tab;
};

void collection::allocate(){
  tab = new int[size];
}

int main(){
    collection c(10);
    for(int i=0; i<c.getSize(); ++i)
    {    
        c.rTab(i) = i;
    }

    for(int i=0; i<c.getSize(); ++i)
    {    
        cout << c.rTab(i) << endl;
    }
}


