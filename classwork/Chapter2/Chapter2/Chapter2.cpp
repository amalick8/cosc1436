// Chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// For a lab:
// Your name
// Lab 1
// COSC 1436 Fall 2025
// 
// 
// #include is a Preprocessor directive, it takes the contents of the file
// which is <iostream> in this case, <iostream> is very large, the compiler sees
// <iostream> and uses that code instead of wasting your space, kind of like an 
// attachment
#include <iostream>
#include <string>

int main()
{
  //std::cout << "Hello World" << " Your Name" << std::endl;
  //std::cout << "You are " << 20 << " years old" << std::endl;

    //Identical to << endl
 //std::cout << "Hello World" << " Your Name\n";

  //std::cout << "Hello World\nYour Name";
    //String literals "..." A literal is a read only piece of data
    // "Whatever" Just a block of text
    // Escape sequence - special meaning to the compiler
    //      - Starts with \ followed by a character
    //      - \t does 3-4 spots of spaces 
    //      - \n does new line
    //      - \" for double quote
    //      - \\ for slash

    //Integer literals - one or more digits, used when you need constant numerals

    //Floating point literals - one or more digits + fraction like 
    // 3.14159 which is pi or 3E10, -3E10 3E-10

    // Variable - Named memory location where data is stored

    std::string name; 
    name = "Ammar";
    std::cout << "Hello World " << name;

    int age;
    age = 20;
    std::cout << "You are " << age << " years old";

    //var - decl ::= type id;
    //type is std:: string or int
    //id is name or age
    //id:: = (letter or _)(letter or digits or _)

    //Area of rectangle calculator
    //Area = length x width

    //int length;
    //int width;
    //length = 10;
    //width = 20;

    int length = 10, width = 20;

    //unintialized variable - YOU MUST assign a value to a variable before you read it
    //int area;
    //area = 0
    int area = 0;
    //area = length * width;

    std::cout << "Area of rectange is " << area << std::endl;

    //2 different approaches to variable declarations 
    //Block - all variables together
    //int radius, diameter;
    //std::string circleName;

    //Now I can use the variable

    //Inline - variables are declared just before they are used
    int radius = 10, diameter = 10;
    //Use radius, diameter

    std::string circleName;
    //Use circleName

    //Assignment
    //E = E
    //Expression = Expression 
    //l-value = r-value
    //left-value = right-value
    //variables = readable value (variables, literals, expressions)
    
    //double pi;
    //pi = 3.14159;

    char letterGrade;
    letterGrade = 'A';

    bool isPassing;
    isPassing = true;

    area = length * width;
    //Assignment is right associative
    //length = 100;
    //width = 100;
    length = width = 100;
    //std::cout << length; //Verify length is correct

    //Arithmetic operatores
    // arith_op ::= + | - | * | /
    length = length + 10;
    width = width - 20;

    // int division :== int / int produces an int, remainder is lost
    int result = 10 / 3; // = 3

    // Modulus is remainder and only works for integral types
    int remainder = 10 % 3; // = 1

    int negativeLength = -length;


    // Scope - lifetime of a variable
    {//Starting of a new block
        int newVariable = 10;
        double newVariable2 = 45.7;
    };

    {
        char newVariable1 = 'A';
    };

     //std::cout << newVariable1;

     //Strings C++
     std::string studentName; 
     studentName = "Bob";

     studentName = studentName + " Wilson";

     //Literal = great for static values
     //Variables = great for writable values
     //Named constant = variable that has a constant value
     const double Pi = 3.14159;

     // A = Pi * R^2
     double areaCircle = Pi * (radius * radius);

     std::cout << areaCircle;

     const int NumberOfLabGrades = 5;
     const int NumberOfExamGrades = 4;

     //Cannot write to a constant
     //Pi = 140;


}

