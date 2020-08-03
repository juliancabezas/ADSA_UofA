#include <iostream> // Handle input and output
#include <string> // Handle string data
#include <sstream> // Transform string to int
#include <vector>

int main() {

    // The input, it consists 
    std::string input("126 247 10");

    // The delimiter between numbers is a space
    std::string delim(" ");

    // I will make 3 string with the components of the input data
    std::string number1_str;
    std::string number2_str;
    std::string b_str;

    // Find position of the first space
    size_t position1 = input.find(delim);

    // Extract first number
    number1_str = input.substr(0,position1);

    // Find the position of the second space
    size_t position2 = input.find(delim,position1+1);

    // Extract second number
    number2_str = input.substr(position1+1,position2-position1-1);

    // Extract third number 
    b_str = input.substr(position2+1,input.length());

    // Print the numbers
    std::cout << input << std::endl;
    std::cout << number1_str << std::endl;
    std::cout << number2_str << std::endl;
    std::cout << b_str << std::endl;



    return 0;


}

// Transform string into a vector of strings
std::vector<int> string_to_int_vector(std::string number_str) {

    // Create vector of integers
    std::vector<int> numbers_vec;
    int digit;

    for(int i = 0; i < number_str.length(); i++) {

        digit = std::stoi(number_str.substr(i,1)); // Extract the digit
        numbers_vec.push_back(digit); // Push it into the vector
        ;
    }

}

// School method of addition
std::string school_addition()
