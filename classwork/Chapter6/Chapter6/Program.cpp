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
    //double userRating;         //Optional, 1.0-10.0
    bool isClassic;            //Required, false
    std::string genres;         //Optional 
};

int main() 
{
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

    //int id;
    Movie movie = {0};


    //Get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);

    //Title is required
    /*bool isEmpty = title == "";
    if (isEmpty)*/
    while (movie.title == "") {
        std::cout << "Title is required" << std::endl;
        std::getline(std::cin, movie.title);
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
        std::cin >> movie.runLength;

        //Error
        if (movie.runLength < 0)
       { 
        std::string message = "Run length must be at least 0";
        std::cout << "ERROR: " << message << std::endl;
        }
        //std::cin >> runLength
    } while (movie.runLength < 0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;

    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        std::cin >> movie.releaseYear;
    }

    std::cout << "Enter the optional description: ";
    std::cin.ignore();
    std::getline(std::cin, movie.description);

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
        
            movie.genres = movie.genres + ", " + genre;
        }


    std::cout << "Is this a classic (Y/N)? ";
    std::string input;
    std::cin >> input;


    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
        {
            //done = true;
            movie.isClassic = true;
            break;

        } else if (_strcmpi(input.c_str(), "N") == 0)
        {
            movie.isClassic = false;
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
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres" << movie.genres << std::endl;

    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No")<< std::endl;
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
};

void relationalDemo()
{
    std::cout << "Enter two values: ";

    int left, right;
    std::cin >> left >> right;

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