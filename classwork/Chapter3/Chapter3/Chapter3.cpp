#include <iostream>
#include <string>
#include <cmath>

void main()
{
    //Prompt user for radius of circle
    std::cout << "Enter Radius: ";

    // cin is used to get input from the user
    // Use the input stream operator >> before the variable names
    int radius = 0;
    std::cin >> radius;

    const double Pi = 3.14159;

    // Area = Pi * R^2
    // double * int * int => double
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << " * " << radius << " * " << radius << std::endl;
    std::cout << "Area = " << area << std::endl;

    //Triangle    
    std::cout << "Enter base and height of triangle: ";

    int base = 0, height = 0;
    //std::cin >> base;
    //std::cin >> height;
    std::cin >> base >> height;

    // Area = 1/2 * base * height
    // (double / int) * int * int => double
    area = (1.0 / 2) * base * height;
    std::cout << "Area = " << area << std::endl;

    //int someValue = (1.0 / 2);

    std::cout << "Enter name: ";

    std::string name;
    //std::cin >> name;
    std::cin.ignore();
    std::getline(std::cin, name);   //getline is used to read strings with spaces in them
    std::cout << name << std::endl;

    //Overflow and underflow
    short smallValue = 32767;
    smallValue = smallValue + 1;

    short largeValue = -32768;
    largeValue = largeValue - 1;

    std::cout << smallValue << " " << largeValue << std::endl;

    //Type coercion - compiler implicitly converts an expression's type to a larger type

    //Type casting - you explicitly convert a type to another type

    int left = 10;
    int right = 3;

    double intDivision = 10 / 3; //int
    intDivision = 10.0 / 3; // double / int => double
    intDivision = 10 / 3.0; // int / double => double
    intDivision = left / right; //int / int => int

    intDivision = (double)(left / right); //int / int => int => (double)int

    intDivision = static_cast<double>(left) / right; // (double)int / int => double
    intDivision = left / (double)right; // int / (double)int => double

    //This is wrong and will not produce 5
    intDivision = (int)"5";
    //intDivision = static_cast<int>("5") // Compiler error

    //Math functions
    //pow(x, y) => power X to the Y power => x^y
    //sqrt(x) => square root of X
    //
    //ceil(x)=> Smallest possible value >=X
    //floor(x)=> Largest possible integral value <=X

    // round(x)=> Rounds a float to an int using midpoint rounding
    // trunc(x)=> Truncates a float to an int

    //exp(x) => exponential E raises to X power, E = 2.17828
    //log(x) => logarithim, inverse of the exp
   double result;
    result = pow(5, 3);  //5 * 5 * 5 = 125
    result = pow(125, -3); //cube root of 125

    result = sqrt(1000); //10

    result = sqrt(pow(5, 2)); // 5

    result = abs(-10); //10
    result = abs(10); //10

    result = ceil(14.5); // 15
    result = floor(3.1); //3

    result = round(14.5); //15
    result = trunc(3.1); //3
    result = (int)14.5; 

    result = exp(4);
    result = log(exp(4)); // 4

}

    