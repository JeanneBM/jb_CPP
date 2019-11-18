// Ten program oblicza wynagrodzenie użytkownika

#include <iostream>

using namespace std;

int main()
{
    double hours, rate, pay;
    
    // Pobranie liczby przepracowanych godzin
    cout << "Ile godzin przepracowales? ";
    cin >> hours;
    
    // Pobranie stawki godzinowej
    cout << "Ile wynosi Twoje wynagrodzenie za godzine? ";
    cin >> rate;
    
    // Obliczenie wynagrodzenia
    pay = hours * rate;
    
    // Wyświetlenie wynagrodzenia
    cout << "Zarobiles " << pay << " zł." << endl;
    return 0; 
}
