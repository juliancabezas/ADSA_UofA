#include <iostream> // Handle input and output
#include <string> // Handle string data
#include <sstream> // Transform string to int
#include <vector>
#include <algorithm> 
#include <iterator> 


// Transform vector of integers to string
std::string int_vector_to_string(std::vector<int> number_vec) {

    std::ostringstream vts; 

    std::copy(number_vec.begin(), number_vec.end(), std::ostream_iterator<int>(vts, "")); 

    return vts.str();

}


// Transform string into a vector of integers
std::vector<int> string_to_int_vector(std::string number_str) {

    // Create vector of integers
    std::vector<int> numbers_vec;
    int digit;

    for(int i = 0; i < number_str.length(); i++) {

        digit = std::stoi(number_str.substr(i,1)); // Extract the digit
        numbers_vec.push_back(digit); // Push it into the vector
        
    }
}


// School method of addition
std::string school_addition(std::vector<int> number1_vec, std::vector<int> number2_vec, int b) {

    // Create vector with the result
    std::vector<int> result_vec;
    int partial;
    int carry = 0;

    // I need the vectors to be of equal size, I will insert zeroes if necessary
    // In case the first number is bigger
    if (number1_vec.size() > number2_vec.size()) {

        while(number1_vec.size() > number2_vec.size()) {
            number2_vec.insert(number2_vec.begin(), 0);
        }

    }

    // In case the second number is bigger
    if (number2_vec.size() > number1_vec.size()) {

        while(number2_vec.size() > number1_vec.size()) {
            number1_vec.insert(number1_vec.begin(), 0);
        }

    }

    // Add number by number
    for (int i = number1_vec.size() - 1; i >= 0; i--) {

        // The module will give us the partial result
        partial = (number1_vec[i] + number2_vec[i] + carry) % b;
        result_vec.insert(result_vec.begin(), partial);
        //result_vec.push_back(partial);

        // Integer division will give us the carry
        carry = (number1_vec[i] + number2_vec[i] + carry) / b;


    }

    // If I still have a carry I will insert it in the beginning
    if (carry > 0) {
        result_vec.insert(result_vec.begin(), carry);
    }

    return int_vector_to_string(result_vec);

}


int main() {

    // The input, it consists in two integers and a base, separated by a space
    //std::string input("10 111 2");
    std::string input("101 5 10");

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

    // Create vector of integers for number 1
    std::vector<int> number1_vec;
    int digit;

    for(int i = 0; i < number1_str.length(); i++) {

        digit = std::stoi(number1_str.substr(i,1)); // Extract the digit
        number1_vec.push_back(digit); // Push it into the vector
        
    }

    // Create vector of integers for number 2
    std::vector<int> number2_vec;

    for(int i = 0; i < number2_str.length(); i++) {

        digit = std::stoi(number2_str.substr(i,1)); // Extract the digit
        number2_vec.push_back(digit); // Push it into the vector
        
    }

    //std::vector<int> number1_vec;
    //number1_vec = string_to_int_vector(number1_str);

    //std::vector<int> number2_vec;
    //number2_vec = string_to_int_vector(number2_str);

    std::string school_addition_result;
    school_addition_result = school_addition(number1_vec,number2_vec,std::stoi(b_str));
    //std::string school_addition_result = school_addition(string_to_int_vector(number1_str),string_to_int_vector(number2_str),std::stoi(b_str));

    std::cout << school_addition_result << std::endl;

    return 0;

}
