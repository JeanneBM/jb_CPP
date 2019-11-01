#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char napis[20]="Ala ma kota";
    cout << napis<<endl;

    //spowoduje blad:
    //napis="kot";
    //cout << napis<<endl;

    //nie spowoduje bledu:
    char *napis2="Ala ma kota";
    cout << napis2<<endl;
    napis2="Inny napis";
    cout << napis2<<endl;

    //pokaz konkretny znak:
    cout<<napis[0]<<endl;

    //sprawdz plec uzytkownika:
    string imie;
    cout<<"Podaj imie: ";
    cin>>imie;

    int dlugosc_imienia=imie.length();
    cout<<"Dlugosc: "<<dlugosc_imienia<<endl;

    if (imie[dlugosc_imienia-1]=='a')
        cout<<"Wydaje mi sie, ze jestes kobieta"<<endl;
    else cout<<"Wydaje mi sie, ze jestes facetem"<<endl;

    //odwracanie wyrazow:
    string wyraz;
    cout<<"Podaj wyraz do odwrocenia (bez spacji): ";
    cin>>wyraz;

    int dlugosc=wyraz.length();
    for (int i=dlugosc-1; i>=0; i--)
    {
        cout<<wyraz[i];
    }

    //uzycie getline - zapis ze spacjami:
    string napis3;
    cout<<endl<<"Podaj wyraz ze spacjami: ";
    cin.ignore(); //"wyczysc" strumien
    getline(cin,napis3);
    cout<<napis3<<endl;

    //wyznacz dlugosc napisu i wyswietl na ekranie:
    int dlugosc2=napis3.length();
    cout<<dlugosc2<<endl;

    // laczenie dwoch stringow:
    string jeden="Ala ma";
    string dwa=" kota";
    string trzy=jeden+dwa;
    cout<<trzy<<endl;

    //Zmiana wielkosci liter:
    string napis4="Ala ma kota";

    transform(napis4.begin(), napis4.end(), napis4.begin(), ::tolower);
    cout<<napis4<<endl;

    transform(napis4.begin(), napis4.end(), napis4.begin(), ::toupper);
    cout<<napis4<<endl;


    //Znajdz fraze:
    string napis5="Ala ma kota";
    string szukaj="kot";
    size_t pozycja = napis5.find(szukaj);

    if (pozycja!=string::npos)
        cout << "znaleziono na pozycji: " << pozycja << endl;
    else cout<<"nie znaleziono"<< endl;

    //Wykasuj czesc lancucha:
    string napis6="Ala ma kota";
    napis6.erase(3,3);
    cout<<napis6<< endl;

    //Zastap czesc lancucha:
    string napis7="Ala ma kota";
    napis7.replace(4,2,"nie ma");
    cout<<napis7<< endl;

    //Wstaw do lancucha:
    string napis8="Ala ma kota";
    napis8.insert(11," Filemona");
    cout<<napis8<< endl;

    //Wyciagnij czesc napisu do nowego lancucha:
    string napis9="Ala ma kota";
    string nowynapis = napis9.substr (4,7);
    cout<<nowynapis;

    return 0;
}
