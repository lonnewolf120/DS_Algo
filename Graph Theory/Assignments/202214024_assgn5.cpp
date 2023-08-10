#include <bits/stdc++.h>

using namespace std;

class Car {
public:
  string make;
  string model;
  int year;
  double rentalPrice;

  Car(string make, string model, int year, double rentalPrice) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->rentalPrice = rentalPrice;
  }

  void print() {
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Rental Price: $" << rentalPrice << endl;
  }
  virtual void features()
  {
  	cout<<"Broom\n";
  }
  virtual void performance()
  {
  	cout<<"good\n";
  }
};

class EconomyCar : public Car {
public:
  EconomyCar(string make, string model, int year) : Car(make, model, year, 20000) {}
  void features()
  {
  	cout<<"Features: Basic features, limited technology.\n";
  }
  void performance()
  {
  	cout<<"Performance: Fuel-efficient, lower horsepower, smaller engine size.\n";
  }
};

class StandardCar : public Car {
public:
  StandardCar(string make, string model, int year) : Car(make, model, year, 30000) {}
  void features()
  {
  	cout<<"Features: Moderately equipped, some advanced technology.\n";
  }
  void performance()
  {
  	cout<<"Performance: Balanced between fuel efficiency and power, average engine size.\n";
  }
};

class LuxuryCar : public Car {
public:
  LuxuryCar(string make, string model, int year) : Car(make, model, year, 50000) {}
  void features()
  {
  	cout<<"Features: High-end features, advanced technology, luxury materials.\n";
  }
  void performance()
  {
  	cout<<"Performance: Powerful engine, high horsepower, premium driving experience.\n";
  }
};

int main() {
  // Create a list of cars
  vector<Car*> cars;
  cars.push_back(new EconomyCar("Toyota", "Corolla", 2023));
  cars.push_back(new StandardCar("Honda", "Civic", 2023));
  cars.push_back(new LuxuryCar("Mercedes-Benz", "S-Class", 2023));

  // Print the list of cars
  for (Car* car : cars) {
    car->print();
    car->features();
    car->performance();
  }

  return 0;
}
