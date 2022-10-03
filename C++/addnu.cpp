#include <iostream>

int main() {
  std::cout << "Hello & Welcome to Adding Calculator Application.\n";

  // Create the Variables (FirstNumber & SecondNumber)
  int FirstNumber = 0, SecondNumber = 0;

  // Get the First Number
  std::cout << "Please enter your first number: ";
  std::cin >> FirstNumber;

  // Get the Second Number
  std::cout << "Please enter your second number: ";
  std::cin >> SecondNumber;

  // Add the two numbers
  int Sum = FirstNumber + SecondNumber;
  std::cout << "The Sum of the two numbers is: "<< Sum;
}
