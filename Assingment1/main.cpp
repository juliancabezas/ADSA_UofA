#include <iostream>
#include <string>

int main() {

    // The input, it consists 
    std::string input("126 247 2547");

    // The delimiter between numbers is a space
    std::string delim(" ");

    // I will make 3 string with the components of the input data
    std::string number1;
    std::string number2;
    std::string b;

    // Find position of the first space
    size_t position1 = input.find(delim);

    // Extract first number
    number1 = input.substr(0,position1);

    // Find the position of the second space
    size_t position2 = input.find(delim,position1+1);

    // Extract second number
    number2 = input.substr(position1+1,position2-position1-1);

    // Extract third number 
    b = input.substr(position2+1,input.length());

    // Print the numbers
    std::cout << input << std::endl;
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    std::cout << b << std::endl;

    return 0;


}