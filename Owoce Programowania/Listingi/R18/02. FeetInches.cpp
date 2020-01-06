// Plik implementacji klasy FeetInches
#include <cstdlib>  // Instrukcja wymagana przez funkcję abs().
#include "FeetInches.h"

//**************************************************************
// Definicja funkcji simplify(). Funkcja ta sprawdza,
// czy wartość zmiennej inches jest większa od 12 lub
// mniejsza od 0. Jeżeli jeden z warunków jest spełniony,
// liczba cali i stóp jest dostosowywana do wymogów
// systemu miar. Na przykład miara 3 stopy i 14 cali
// jest zamieniana na 4 stopy i 2 cale, a miara 5 stóp
// i -2 cale jest zamieniana na 4 stopy i 10 cali.
//**************************************************************

void FeetInches::simplify()
{
   if (inches >= 12)
   {
      feet += (inches / 12);
      inches = inches % 12;
   }
   else if (inches < 0)
   {
      feet -= ((abs(inches) / 12) + 1);
      inches = 12 - (abs(inches) % 12);
   }
}

//**********************************************
// Przeciążony operator jednoargumentowy +
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches + right.inches;
   temp.feet = feet + right.feet;
   temp.simplify();
   return temp;
}

//**********************************************
// Przeciążony operator jednoargumentowy -
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches - right.inches;
   temp.feet = feet - right.feet;
   temp.simplify();  
   return temp;
}

//*************************************************************
// Przeciążony operator prefiksowy ++. Powoduje on zwiększenie 
// zmiennej inches. Funkcja zwraca powiększony obiekt.
//*************************************************************

FeetInches FeetInches::operator ++ ()
{
   ++inches;
   simplify();
   return *this;
}

//***************************************************************
// Przeciążony operator sufiksowy ++. Powoduje on zwiększenie 
// zmiennej inches. Funkcja zwraca obiekt zanim zostanie
// powiększony.
//***************************************************************

FeetInches FeetInches::operator ++ (int)
{
   FeetInches temp(feet, inches);

   inches++;
   simplify();
   return temp;
}

//************************************************************
// Przeciążony operator >. Zwraca true jeżeli bieżący obiekt
// jest większy od obiektu w argumencie right.
//************************************************************

bool FeetInches::operator > (const FeetInches &right)
{
   bool status;

   if (feet > right.feet)
      status = true;
   else if (feet == right.feet && inches > right.inches)
      status = true;
   else
      status = false;

   return status;
}

//************************************************************
// Przeciążony operator <. Zwraca true jeżeli bieżący obiekt
// jest mniejszy od obiektu w argumencie right.
//************************************************************

bool FeetInches::operator < (const FeetInches &right)
{
   bool status;

   if (feet < right.feet)
      status = true;
   else if (feet == right.feet && inches < right.inches)
      status = true;
   else
      status = false;

   return status;
}

//*************************************************************
// Przeciążony operator ==. Zwraca true jeżeli bieżący obiekt
// jest równy obiektowi w argumencie right.
//*************************************************************

bool FeetInches::operator == (const FeetInches &right)
{
   bool status;

   if (feet == right.feet && inches == right.inches)
      status = true;
   else
      status = false;

   return status;
}

//*************************************************************
// Przeciążony operator !=. Zwraca wartość true jeżeli bieżący
// obiekt zawiera wartość różną od wartości zawartej w argumencie right.
//*************************************************************

bool FeetInches::operator != (const FeetInches &right)
{
  bool status;

  if (!operator==(right))
    status = true;
  else
    status = false;

  return status;
}

//********************************************************
// Przeciążony operator << umożliwiający bezpośrednie wyświetlanie
// zawartości obiektu typu FeetInches za pomocą obiektu cout.
//********************************************************

ostream &operator<<(ostream &strm, const FeetInches &obj)
{
   strm << obj.feet << " stopy/stóp, " << obj.inches << " cale/cali";
   return strm;
}

//********************************************************
// Przeciążony operator >> umożliwiający bezpośrednie umieszczanie w obiekcie
// typu FeetInches danych wprowadzonych przez użytkownika z pomocą obiektu cin.
//********************************************************

istream &operator >> (istream &strm, FeetInches &obj)
{
   // Wprowadzenie przez użytkownika liczby stóp
   cout << "Liczba stóp: ";
   strm >> obj.feet;

   // Wprowadzenie przez użytkownika liczby cali
   cout << "Liczba cali: ";
   strm >> obj.inches;

   // Normalizacja wartości
   obj.simplify();

   return strm;
}

//*************************************************************
// Funkcja konwertująca obiekt typu FeetInches
// na liczbę typu double
//*************************************************************

FeetInches::operator double()
{
  double temp = feet;

  temp += (inches / 12.0);
  return temp;
}

//*************************************************************
// Funkcja konwertująca obiekt typu FeetInches
// na liczbę typu int
//*************************************************************

FeetInches:: operator int()
{ 
   return feet; 
}
