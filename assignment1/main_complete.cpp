//====================================
// Algorithm & Data Structure Analysis (ADSA)
// Student names: Francisco Zanartu & Julian Cabezas Pena
// Semester: 2
// Year: 2020
// Assignment: 1
//=====================================


#include <iostream> // Handle input and output
#include <string> // Handle string data
#include <sstream> // Transform string to int
#include <vector> // Vector data structure
#include <algorithm> 
#include <iterator> 
#include <cmath> 


// Transform vector of integers to string
std::string int_vector_to_string(std::vector<int> number_vec) {

    std::ostringstream vts; 

    std::copy(number_vec.begin(), number_vec.end(), std::ostream_iterator<int>(vts, "")); 

    return vts.str();

}


// Transform string into a vector of integers
/* std::vector<int> string_to_int_vector(std::string number_str) {

    // Create vector of integers
    std::vector<int> numbers_vec;
    int digit;

    for(int i = 0; i < number_str.length(); i++) {

        digit = std::stoi(number_str.substr(i,1)); // Extract the digit
        numbers_vec.push_back(digit); // Push it into the vector
        
    }
}
 */

// Transform string into a vector of integers
std::vector<int> double_to_int_vector(double number) {

    // Create vector of integers
    std::vector<int> numbers_vec;
    int digit=0;
    std::string integer_str;

    integer_str = std::to_string(number);

    for(int i = 0; i < integer_str.length(); i++) {

        std::string digit_str = integer_str.substr(i,1);

        if (digit_str == ".") {
            break;

        } else {

            digit = std::stoi(integer_str.substr(i,1)); // Extract the digit
            numbers_vec.push_back(digit); // Push it into the vector
        }

        
    }

    return numbers_vec;
}


// Transform string into a vector of integers
std::vector<int> integer_to_int_vector(int number) {

    // Create vector of integers
    std::vector<int> numbers_vec;
    int digit=0;
    std::string integer_str;

    integer_str = std::to_string(number);

    for(int i = 0; i < integer_str.length(); i++) {

        digit = std::stoi(integer_str.substr(i,1)); // Extract the digit
        numbers_vec.push_back(digit); // Push it into the vector
                
    }

    return numbers_vec;
}

// School method of addition
std::vector<int> school_addition(std::vector<int> number1_vec, std::vector<int> number2_vec, int b) {

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

    return result_vec;

}


// School method of substraction
std::vector<int> school_substraction(std::vector<int> number1_vec, std::vector<int> number2_vec, int b) {

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

        // If the substraction gives a negative number then add 1 to the carry
        if (number1_vec[i] - number2_vec[i] - carry < 0){
            partial = number1_vec[i] - number2_vec[i] - carry + b;
            result_vec.insert(result_vec.begin(), partial);
            carry = 1;
        } else {
            partial = number1_vec[i] - number2_vec[i] - carry;
            result_vec.insert(result_vec.begin(), partial);
            carry = 0;
        }

    }

    // If the first element is a zero drop it
    if (!result_vec.empty()) {
        while (result_vec.size() > 1 & result_vec[0] == 0){
        result_vec.erase(result_vec.begin());
        }
    }

    return result_vec;

}


// Simple multiplication, just as in school
std::vector<int> school_multiplication(std::vector<int> number1_vec, std::vector<int> number2_vec, int b) {

    // Create vector with the result
    std::vector<int> result_vec;
    std::vector<int> partial_vec;
    int partial = 0;
    int counter= 0;
    int carry = 0;


    for (int i = number1_vec.size() - 1; i >= 0; i--) {
        
        // Carry starts at zero
        carry = 0;

        for (int j = number2_vec.size() - 1; j >= 0; j--) {
            
            // In case the multiplication is bigger than the base
            if (number1_vec[i] * number2_vec[j] + carry >= b) {
                partial = (number1_vec[i] * number2_vec[j] + carry) % b;
                partial_vec.insert(partial_vec.begin(), partial);
                carry = (number1_vec[i] * number2_vec[j] + carry - partial) / b;
            
            // In case it is not bigger than the base the carry just turns out to be zero
            } else {
                partial = number1_vec[i] * number2_vec[j] + carry;
                partial_vec.insert(partial_vec.begin(), partial);
                carry = 0;
            }
        
        }

        
    
        // In case we still have a carry
        if (carry > 0){
            partial_vec.insert(partial_vec.begin(), carry);
        }

        // Put trailing zeroes
        for (int zeroes = number1_vec.size() - 1; zeroes > i; zeroes--) {

            partial_vec.push_back(0);

        }

        // Delete leading zeroes
        //if (partial_vec[0] == 0){
        //    partial_vec.erase(partial_vec.begin());
        //}

        // if it is the first iteration the partial vector becomes the result vector
        if (counter == 0){
            result_vec = partial_vec;
        } else {
            result_vec = school_addition(partial_vec, result_vec, b);
        }

        
        partial_vec.clear();
        counter = counter + 1;

    }

    // If the first element is a zero drop it
    if (!result_vec.empty()) {
        while (result_vec.size() > 1 & result_vec[0] == 0){
        result_vec.erase(result_vec.begin());
        }
    }

    return result_vec;

}

// Make a power using vectors of integers
std::vector<int> vector_power(int base, int exponent, int b) {

    std::vector<int> result = integer_to_int_vector(base);
    std::vector<int> multiplier = integer_to_int_vector(base);

    for (int i = 0; i < exponent; i++) {

        std::vector<int> result = school_multiplication(result, multiplier, b);

    }

    return result;

}

// Make a power using vectors of integers
/* std::vector<int> vector_powerRRRR(int base, int exponent, int b) {

    std::vector<int> result = integer_to_int_vector(base);
    std::vector<int> multiplier = integer_to_int_vector(base);

    for (int i = 0; i < exponent; i++) {

        std::vector<int> result = school_multiplication(result, multiplier, b);

    }

    return result;

} */

// Make a power using vectors of integers
std::vector<int> vector_power10(int exponent) {

    std::vector<int> result;

    result.push_back(1);

    for (int i = 0; i < exponent; i++) {

        result.push_back(0);

    }

    return result;

}

int convert_base(int n, int base)
{
    int new_base = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%base;
        n /= base;
        new_base += remainder*pow(10,i);
        ++i;
    }
    return new_base;
}

std::vector<int> karatsuba_multiplication(std::vector<int> number1_vec, std::vector<int> number2_vec, int b) {

    // I will create all the vectors I need
    std::vector<int> a1;
    std::vector<int> a0;
    std::vector<int> b0;
    std::vector<int> b1;

    std::vector<int> p0;
    std::vector<int> p1;
    std::vector<int> p2;

    std::vector<int> f0;
    std::vector<int> f1;

    int sep_point;



    // I need vector 1 to be larger than vector 2
    if (number2_vec.size() > number1_vec.size()) {

        number1_vec.swap(number2_vec);

    }


    // I need the vectors to be of equal size, I will insert zeroes if necessary
    // In case the first number is bigger
/*     if (number1_vec.size() > number2_vec.size()) {

        while(number1_vec.size() > number2_vec.size()) {
            number2_vec.insert(number2_vec.begin(), 0);
        }

    }

    // In case the second number is bigger
    if (number2_vec.size() > number1_vec.size()) {

        while(number2_vec.size() > number1_vec.size()) {
            number1_vec.insert(number1_vec.begin(), 0);
        }

    } */



    // Determine n
    int n = std::max(number1_vec.size(),number2_vec.size());

    // Base case
    if (n <= 3){
        return school_multiplication(number1_vec, number2_vec, b);
    }

    // Index to separate the vector
    // In case it is a multiple of 2
    if (n % 2 == 1) {
        sep_point = (n + 1) / 2;
    } else {
        sep_point = n / 2;
    }

    // Separate the first number in halves
    if (number1_vec.size() <= sep_point) {

        a0 = number1_vec;

        // a1 will just be a zero
        a1.insert(a1.begin(), 0);

    } else {

        for (int i = 0; i < (number1_vec.size()-sep_point); i++) {

            a1.push_back(number1_vec[i]);

        }

        for (int j = (number1_vec.size()-sep_point); j < number1_vec.size(); j++) {

            a0.push_back(number1_vec[j]);
            
        }

    }


    // Separate the second number in halves
    if (number2_vec.size() <= sep_point) {

        b0 = number2_vec;

        // a1 will just be a zero
        b1.insert(b1.begin(), 0);

    } else {


        for (int i = 0; i < (number2_vec.size()-sep_point); i++) {

            b1.push_back(number2_vec[i]);

        }

        for (int j = (number2_vec.size()-sep_point); j < number2_vec.size(); j++) {

            b0.push_back(number2_vec[j]);
            
        }

    }

    // Compute the three products
    //p2 = school_multiplication(a1,b1,b);
    //p0 = school_multiplication(a0,b0,b);
    //p1 = school_multiplication(school_addition(a1,a0,b),school_addition(b1,b0,b),b);

    p2 = karatsuba_multiplication(a1,b1,b);
    p0 = karatsuba_multiplication(a0,b0,b);
    p1 = karatsuba_multiplication(school_addition(a1,a0,b),school_addition(b1,b0,b),b);

    int sep_point_x2 = 2*sep_point;
    double b_power_2n = std::pow(10,sep_point_x2);

    // Now compute the 3 parts of the final ecuation
    //f0 = school_multiplication(p2,double_to_int_vector(b_power_2n),b);
    f0 = school_multiplication(p2,vector_power10(sep_point_x2),b);

    double b_power_n = std::pow(10,sep_point);

    //f1 = school_multiplication(school_substraction(p1,school_addition(p2,p0,b),b),double_to_int_vector(b_power_n),b);
    f1 = school_multiplication(school_substraction(p1,school_addition(p2,p0,b),b),vector_power10(sep_point),b);
    
    return school_addition(school_addition(f0,f1,b),p0,b);

}



int main() {

    // The input, it consists in two integers and a base, separated by a space
    std::string input;

    // Get the input
    std::getline(std::cin,input);

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

    // Print the numbers (DEGUG)
    //std::cout << input << std::endl;
    //std::cout << number1_str << std::endl;
    //std::cout << number2_str << std::endl;
    //std::cout << b_str << std::endl;

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



    //std::vector<int> school_substraction_result;
    //school_substraction_result = school_substraction(number1_vec,number2_vec,std::stoi(b_str));


    //std::cout << int_vector_to_string(school_substraction_result) << std::endl;

    std::vector<int> school_addition_result;
    school_addition_result = school_addition(number1_vec,number2_vec,std::stoi(b_str));

    std::vector<int> karatsuba_multiplication_result;
    karatsuba_multiplication_result = karatsuba_multiplication(number1_vec,number2_vec,std::stoi(b_str));

    std::cout << int_vector_to_string(school_addition_result) + " " + int_vector_to_string(karatsuba_multiplication_result) << std::endl;

    return 0;

}