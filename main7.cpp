#include <iostream>
#include <string>
using namespace std;

class CBuilding {

protected:
  int *timeUsed = new int;
  int power;
  string name;
  int peopleCount;

public:
  void changeFloor() {
    if (power == 1) {
      cout << this->name << " turned off." << endl;
      power = 0;
    }

    else {
      cout << this->name << " turned on." << endl;
      power = 1;
    }
  }

  virtual void getPower() {
    if (power == 1)
      cout << "Electricity is turned off." << endl;

    else
      cout << "Electricity is turned on." << endl;
  }

  void getAll() {
    cout << "Buliding has been in use for " << *timeUsed << " days." << endl;
    if (power == 1)
      cout << "Buliding electricity is turned on." << endl;

    else
      cout << "Electricity is turned off." << endl;
    cout << "Buliding name: " << name << endl;
    cout << "people: " << peopleCount << endl;
  }

  void setName(string name) {
    this->name = name;
  }

  void setTimeUsed(int time) {
    *timeUsed = time;
  }

  void loadPeople(int people) {
    this->peopleCount += people;
    cout << people << " people loaded." << endl;
  }

  CBuilding() {
    *timeUsed = 0;
    power = 0;
    name = "Unknown";
  }

  CBuilding(int timeUse, int power, string name) {
    *timeUsed = timeUse;
    this->power = power;
    this->name = name;
  }
};

class СShoppingCentre : virtual public CBuilding {

protected:
  int money;
  string producer;

public:
  void getPower() override {
    if (power == 1)
      cout << "Electricity 2 is turned off." << endl;

    else
      cout << "Electricity 2 is turned on." << endl;
  }

  void setMoney(int speed) {
    this->money = speed;
  }

  void setProducer(string producer) {
    this->producer = producer;
  }

  void getInfo() {
    cout << "Building has been in use for " << *timeUsed << " days." << endl;
    if (power == 1)
      cout << "Building electicity is turned off." << endl;

    else
      cout << "Building electicity is turned on." << endl;
    cout << "Shopping name: " << name << endl;
  }

  void getAllScanner() {
    cout << "Capacity (people per minute): " << money << endl;
    cout << "Country producer: " << producer << endl;
  }

  void func() {
    if (peopleCount == 0 || power == 0) {
      cout << "Not enough power or Electricity is off." << endl;
    }
    else if (peopleCount > 0 && power == 1) {
      peopleCount--;
      cout << 
        "people left: " << peopleCount << endl;
    }
  }

  СShoppingCentre() {
    *timeUsed = 0;
    power = 0;
    name = "Unknown";
    money = 0;
    producer = "Unknown";
  }

  СShoppingCentre(int timeUse, int power, string name, int money, string producer) {
    *timeUsed = timeUse;
    this->power = power;
    this->name = name;
    this->money = money;
    this->producer = producer;
  }
};

class СEntertainingCentre : virtual public CBuilding {

protected:
  int movies;
  string name_2;

public:
  void setMovies(int movies) {
    this->movies = movies;
  }

  void setTypeOfPaper(string name_2) {
    this->name_2 = name_2;
  }

  void getAll_() {
    cout << "Printing speed (pages per minute): " << movies << endl;
    cout << "Type of people used: " << name_2 << endl;
  }

  void print() {
    if (peopleCount == 0 || power == 0) {
      cout << "Not enough people or Electricity is off." << endl;
    }
    else if (peopleCount > 0 && power == 1) {
      peopleCount--;
      cout << 
        "people left: " << peopleCount << endl;
    }
  }

  СEntertainingCentre() {
    *timeUsed = 0;
    power = 0;
    name = "Unknown";
    movies = 0;
    name_2 = "Unknown";
  }

  СEntertainingCentre(int timeUse, int power, string name, int movies, string name_2) {
    *timeUsed = timeUse;
    this->power = power;
    this->name = name;
    this->movies = movies;
    this->name_2 = name_2;
  }

  ~СEntertainingCentre() {
    cout << "Object '" << this->name << "' destroyed." << endl;
    delete timeUsed;
  }

};

class CShoppingLeisureCentre : public СShoppingCentre, public СEntertainingCentre {
public:
  CShoppingLeisureCentre(int timeUse, int power, string name, int money, string producer, int movies, string name_2) {
    *timeUsed = timeUse;
    this->power = power;
    this->name = name;
    this->money = money;
    this->producer = producer;
    this->movies = movies;
    this->name_2 = name_2;
  }

  void get() {
    cout << "Money: " << money << endl;
    cout << "Country producer: " << producer << endl;
    cout << "Movies: " << movies << endl;
    cout << "Name 2: " << name_2 << endl;
  }

  void operator = (const CShoppingLeisureCentre & other) {
    this->money = other.money;
    this->producer = other.producer;
    this->movies = other.movies;
    this->name_2 = other.name_2;
    cout << "Objects are now equal." << endl;
  }
};

int main() {
  CShoppingLeisureCentre obj(56, 0, "Forum", 50, "Ukraine", 65, "Silpo");

  obj.loadPeople(5);
  cout << endl;

  obj.getAll();
  obj.get();
  cout << endl;

  obj.print();
  cout << endl;

  obj.func();
  cout << endl;

  obj.getAll();
  obj.get();
  cout << endl;
  return 1;
}
