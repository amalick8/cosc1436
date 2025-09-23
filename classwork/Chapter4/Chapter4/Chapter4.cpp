/*
Chapter 4
*/

#include <iostream>
#include <string>

int main()
{
    //Movie details
    std::string title;         //Required
    std::string description;   //Optional
    int runLength;             //Required, 0
    int releaseYear;           //Optional, but between 1900 - 2100
    double userRating;         //Optional, 1.0-10.0
    bool isClassic;            //Required, false

    //Get movie details
    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    //Title is required
    bool isEmpty = title == "";
    if (isEmpty)
        std::cout << "Title is required" << std::endl;

    std::cout << "Enter the run length (in minutes): ";
    std::cin >> runLength;
    if (runLength < 0)
    {
        std::cout << "Run length must be at least 0" << std::endl;
        runLength = 0;
    };

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
    if (releaseYear < 1900)
    {
        std::cout << "Release year must be at least 1900" << std::endl;
        releaseYear = 1900;
    };

    std::cout << "Enter the optional description: ";
    std::getline(std::cin, description);

    //TODO: Validate userRating
    std::cout << "Enter the optional user rating (1.0-10.0): ";
    std::cin >> userRating;

    
 

};