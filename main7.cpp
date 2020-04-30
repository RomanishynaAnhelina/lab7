#include <iostream>
#include <iomanip>
#include <Windows.h>

#define w 10

using namespace std;

class CCloth
{
protected:
  int length, size;
  char* brand;
public:
  CCloth(const char* brand, int length, int size)
  {
    setInfo(brand, length, size);
  }
  ~CCloth()
  {
    delete[] brand;
  }
  void setInfo(const char* brand, int length, int size)
  {
    this->brand = new char[strlen(brand) + 1];
    strcpy_s(this->brand, strlen(brand) + 1, brand);
    this->length = length;
    this->size = size;
  }
  virtual void PrintInfo() = 0;
};

class CPants : public CCloth
{
protected:
  char* season;
public:
  CPants(const char* brand, int length, int size, const char* season) :
    CCloth(brand, length, size)
  {
    setInfo(season);
  }
  void setInfo(const char* season)
  {
    this->season = new char[strlen(season) + 1];
    strcpy_s(this->season, strlen(season) + 1, season);
  }
  virtual void PrintInfo()
  {
    cout << "Pants info:" << endl;
    cout << setw(w) << left << "Бренд: " << CCloth::brand << endl;
    cout << setw(w) << left << "Довжина: " << CCloth::length << " см" << endl;
    cout << setw(w) << left << "Розмір: " << CCloth::size << endl;
    cout << setw(w) << left << "Сезон: " << season << endl;
  }
};

class CShorts : public CCloth
{
protected:
  char* style;
public:
  CShorts(const char* brand, int length, int size, const char* style) : CCloth(brand, length, size)
  {
    setInfo(style);
  }
  void setInfo(const char* style)
  {
    this->style = new char[strlen(style) + 1];
    strcpy_s(this->style, strlen(style) + 1, style);
  }
  virtual void PrintInfo()
  {
    cout << "Shorts info:" << endl;
    cout << setw(w) << left << "Бренд: " << CCloth::brand << endl;
    cout << setw(w) << left << "Довжина: " << CCloth::length << " см" << endl;
    cout << setw(w) << left << "Розмір: " << CCloth::size << endl;
    cout << setw(w) << left << "Стиль: " << style << endl;
  }
};

class CPantsShorts : public CPants, public CShorts
{
public:
  CPantsShorts(const char* brand, int length, int size, const char* season, const char* style) : CPants(brand, length, size, season), CShorts(brand, length, size, style)
  {

  }
  virtual void PrintInfo()
  {
    cout << "Pants-Shorts info:" << endl;
    cout << setw(w) << left << "Бренд: " << CCloth::brand << endl;
    cout << setw(w) << left << "Довжина: " << CCloth::length << " см" << endl;
    cout << setw(w) << left << "Розмір: " << CCloth::size << endl;
    cout << setw(w) << left << "Сезон: " << CPants::season << endl;
    cout << setw(w) << left << "Стиль: " << CShorts::style << endl;
  }
};


int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  CPants Pans1("Jeans", 70, 32, "Spring");
  Pans1.PrintInfo();

  cout << endl << endl;

  CShorts Shorts1("Shorts", 40, 35, "Wide");
  Shorts1.PrintInfo();

  cout << endl << endl;

  CPantsShorts PantsShorts1("PantsShorts", 50, 31, "Summer", "Capri");
  PantsShorts1.PrintInfo();

  cout << endl;
  system("pause");
  return 0;
}
