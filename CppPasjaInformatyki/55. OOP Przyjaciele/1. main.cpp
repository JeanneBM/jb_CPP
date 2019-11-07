#include <iostream>
#include "przyjaciele.h"
using namespace std;

void sedzia(Punkt &pkt,Prostokat &p)
{
   p.nazwa="PODMIANA";

if((pkt.x>=p.x)&&(pkt.x<=p.x+p.szerokosc)&&(pkt.y>=p.y)&&(pkt.y<=p.y+p.wysokosc))

cout<<endl<<"Punkt "<<pkt.nazwa<<" nalezy do prostokata: "<<p.nazwa;

else
cout<<endl<<"Punkt "<<pkt.nazwa<<" lezy POZA prostokatem: "<<p.nazwa;
}

int main()
{
    Punkt pkt1("A",3,17);
    //pkt1.wczytaj();

    Prostokat p1("Prostokat",0,0,6,4);
    //p1.wczytaj();

    sedzia(pkt1,p1);

    p1.wczytaj();

    return 0;
}
