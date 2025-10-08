/*
Chapter 4
*/

#include <iostream>
#include <string>
#include <iomanip>

//Movie details

struct Movie {

    std::string title;         //Required
    std::string description;   //Optional
    int runLength;             //Required, 0
    int releaseYear;           //Optional, but between 1900 - 2100
    double userRating;         //Optional, 1.0-10.0
    bool isClassic;            //Required, false
    std::string genres;         //Optional 

};

int main()
{

    //Demo prefix/postfix-increment/decrement
    //std::cout << "Enter a value: ";
    //int number;
    //std::cin >> number;

    //std::cout <<  "Prefix (++x) = " << ++number << ", x =" << number << std::endl;
    //std::cout << "Prefix (--x) = " << --number << ", x =" << number << std::endl;
    //std::cout << "Postfix (x++) = " << number++ << ", x =" << number << std::endl;
    //std::cout << "Postfix (x--) = " << number-- << ", x =" << number << std::endl;

    //Demo nested loops 10x12
    //  1 2 3 4 5
    //1 1 2 3 4 5
    //2 2 4 6 8 10
    //3 3 6 9 12 15

    //for (int rows = 1 ; rows <= 12; ++rows)
    //{ 
    //    for (int cols = 1; cols <= 10; ++cols)
    //    {
    //            std::cout << std::setw(4) << (rows * cols);
    //    }
    //    std::cout << std::endl;
    //}
    //    



    //Display main menu
    bool done = false;
    do // while(!done)
    {


        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

        //if (choice == "A" || choice == "aa") 
        //{
        //    //TODO: Move add code here
        //    std::cout << "Add not implemented" << std::endl;
        //} else if (choice == "V" || choice == "v") 
        //{
        //    //TODO: Movie view code here
        //    std::cout << "View not implemented" << std::endl;
        //} else if (choice == "E" || choice == "v") 
        //{
        //    std::cout << "Edit not implemented" << std::endl;
        //} else if (choice == "D" || choice == "v") 
        //{
        //    std::cout << "Delete not implemented" << std::endl;
        //} else if (choice == "Q" || choice == "v") {
        //    return 0;
        //} else
        //{
        //    std::cout << "invalid choice" << std::endl;
        //};

        switch (choice)
        {
            case 'A': /*std::cout << "Add not implemented" << std::endl; break;*/
            case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

            case 'V':
            case 'v':
            {
                //Declaring a variable
                //switch-statement
                std::cout << "View not implemented" << std::endl;
                done = true;
                break;
            }

            case 'D': 
            case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

            case 'E': 
            case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

            case 'Q': return 0;
            case 'q': return 0;

            default: std::cout << "Invalid choice" << std::endl; break;
        };

    } while (!done);

    //Validate input

    //Get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    //Title is required
    /*bool isEmpty = title == "";
    if (isEmpty)*/
    while (title == "") {
        std::cout << "Title is required" << std::endl;
        std::getline(std::cin, title);
    }
       

    std::cout << "Enter the run length (in minutes): ";
    /*runLength = -1;
    while (runLength < 0)
    {
        std::cin >> runLength;
        if (runLength < 0)
            std::cout << "Error: Run length must be at least 0" << std::endl;
    }*/
    //std::cin >> runLength;
    do //while (runLength < 0)
    {
        std::cin >> runLength;

        //Error
        if (runLength < 0)
       { 
        std::string message = "Run length must be at least 0";
        std::cout << "ERROR: " << message << std::endl;
        }
        //std::cin >> runLength
    } while (runLength < 0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
   /* if (releaseYear < 1900)
    {
        std::cout << "Release year must be at least 1900" << std::endl;
        releaseYear = 1900;
    } else if (releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        releaseYear = 1900;
    };*/

    while (releaseYear < 1900 || releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        std::cin >> releaseYear;
    }

    std::cout << "Enter the optional description: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    //TODO: Validate userRating
    /*std::cout << "Enter the optional user rating (1.0-10.0): ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    }*/
    /*if (userRating < 1.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    } else if (userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    }*/


    // Genres up to 5
    //done = false;
    //int count = 0;
    //while (!done && count < 5)
    //{ 
    //    std::string genre;


    //std::cout << "Enter the genre (or blank to continue): ";
    //std::getline(std::cin, genre);
    //if (genre == "")
    //    done = true;
    //else
    //    genres = genres + ", " + genre;

    //++count; // or, count++
    //}

    done = false;
    /*int index = 0;*/
    //for (count = 0; count < 5 && !done; ++count)
    //for (index = 0; index < 5; ++index)
    for ( int index = 0; index < 5; ++index)
        {
            std::string genre;

            std::cout << "Enter the genre (or blank to continue): ";
            std::getline(std::cin, genre);
            if (genre == "")
                //done = true;
                //index = 5
                break;
            else if (genre == " ")
                continue;
        
            genres = genres + ", " + genre;
        }


    std::cout << "Is this a classic (Y/N)? ";
    std::string input;
    std::cin >> input;



    //Infinite Loop
    // while (true) {}
    // for (;;) {}
   


    // if (Eb) S [ else S]
    /*if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    else
        std::cout << "You must enter either Y or N";*/
    //done = false;
    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
        {
            //done = true;
            isClassic = true;
            break;

        } else if (_strcmpi(input.c_str(), "N") == 0)
        {
            isClassic = false;
            //done = true;
            break;
        } else {
            std::cout << "You must enter either Y or N";
            std::cin >> input;
        }
    };
    //TODO: Handle other values
    // Title (Year)
    // Run Length (min)
    // User Rating = ##
    // Is Classic?
    // [Description]
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << title << " (" << releaseYear << ")" << std::endl;
    std::cout << "Run Length " << runLength << " mins" << std::endl;
    std::cout << "Genres" << genres << std::endl;
    /*std::cout << "User Rating = " << userRating << std::endl;*/
   /* std::cout << "Is Classic? " << isClassic << std::endl;*/
   /* if (isClassic)
        std::cout << "Is Classic? Yes" << std::endl;
    else
        std::cout << "Is Classic? No" << std::endl;
    if (description != "")*/
    /*std::string classicIndicator;
    if (isClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";*/
    //Conditional_expression ::= Eb ? Et : Ef
    std::cout << "Is Classic? " << (isClassic ? "Yes" : "No")<< std::endl;
        std::cout << description << std::endl;
    std::cout << std::endl;
};

void relationalDemo()
{
    std::cout << "Enter two values: ";

    int left, right;
    std::cin >> left >> right;

    // Relational operators ::= > >= < <= == !=
    // Warning 1 - Equality and equals are similar and work in the same situations
    // Warning 2 - Be very, very careful of floating point comparison for equality
    //              Consider using >= or <= instead unless comparing to an integer
    // Warning 3 - Strings compare by character values not by locale
    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;

    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">= " << (left >= right) << std::endl;
    std::cout << "<= " << (left <= right) << std::endl;
    std::cout << "== " << (left == right) << std::endl;
    std::cout << "!= " << (left != right) << std::endl;

    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 * 3.0) / 3.0;
    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    // Comparison works but is case sensitive
    std::string name1 = "Bob";
    std::string name2 = "bob";
    std::cout << (name1 == name2) << std::endl;

    // To compare strings case insensitive use the strcmpi
    //  > 0 ::= left > right
    //  < 0 ::= left < right
    //  == 0 ::= left == right
    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;


}