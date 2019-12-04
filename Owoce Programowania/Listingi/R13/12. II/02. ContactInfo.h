// Ta klasa zawiera przeciążone konstruktory.
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
using namespace std;

class InventoryItem
{
private:
  string description; // Opis produktu
  double cost;        // Cena produktu
  int units;          // Liczba produktu
public:
  // Konstruktor nr 1 (domyślny)
  InventoryItem()
    { // Inicjacja zmiennych description, cost i units
      description = "";
      cost = 0.0;
      units = 0; }

  // Konstruktor nr 2
  InventoryItem(string desc)
    { // Przypisanie wartości zmiennej description
      description = desc;

      // Inicjacja zmiennych cost i units
      cost = 0.0;
      units = 0; }

  // Konstruktor nr 3
  InventoryItem(string desc, double c, int u)
    { // Przypisanie wartości zmiennym description, cost i units
      description = desc;
      cost = c;
      units = u; }

  // Mutatory
  void setDescription(string d)
    { description = d; }

  void setCost(double c)
    { cost = c; }

  void setUnits(int u)
    { units = u; }

  // Akcesory
  string getDescription() const
    { return description; }

  double getCost() const
    { return cost; }

  int getUnits() const
    { return units; }
};
#endif

