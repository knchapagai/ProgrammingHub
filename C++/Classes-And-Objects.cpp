#include<iostream>
#include<string>    //for using string class
using namespace std;

class Cars
{
  private:
  //member variables or data members
  string companyName;
  string modelName;
  string fuelType;
  float mileage;
  double price;
  
  public:
  //member functions
  void setData(string cName, string mName, string fType, float m, double p)
  {
    companyName = cName;
    modelName = mName;
    fuelType = fType;
    mileage = m;
    price = p;
  }
  
  void displayData()
  {
    cout << "Car Details" << endl;
    cout << "Name of the company: " << companyName << endl;
    cout << "Car model name: " << modelName << endl;
    cout << "Type of fuel: " << fuelType << endl;
    cout << "Mileage: " << mileage << endl;
    cout <<"Price of car: " << price << endl;
  }
};

int main()
{
  //objects are nothing but variables of type class
  Cars car1, car2;    //object of type Car
  int x;
  
  car1.setData("toyota", "altis", "petrol", 15.5, 1500000);
  car1.dispalyData();
  
  //you can do the same for another car2
  return 0;
}
