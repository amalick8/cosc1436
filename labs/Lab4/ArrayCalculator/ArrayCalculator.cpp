/*
 * Lab 4
 * M. Ammar Malick
 * COSC 1436 Fall 2025
 */
#include <iostream>
#include <string>
#include <iomanip>

/// <summary>Displays an error message.</summary>
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    std::cout << "ERROR: " << message << std::endl;
}

/// <summary>Reads an integer with validation.</summary>
/// <param name="minimumValue">Minimum allowed value.</param>
/// <returns>Valid integer entered by user.</returns>
int ReadInt(int minimumValue)
{
    int value;
    std::cin >> value;

    while (value < minimumValue)
    {
        DisplayError("Value must be at least 0");
        std::cin >> value;
    }

    return value;
}

/// <summary>prompts user for array values</summary>
/// <param name="numbers">Array to fill with values.</param>
/// <param name="size">Maximum size of array</param>
/// <returns>Number of values enterd</summary>
int GetNumbers(int numbers[], int size)
{
    int count = 0;

    for (int index = 0; index < size; ++index)
    {
        std::cout << "Enter a value: ";
        int value;
        std::cin >> value;

        //Check if user wants to stop
        if (value == 0)
            break;
        else if (value < 0)
        {
            DisplayError("You must enter a value greater than or equal to 0");
            --index;
            continue;
        }

        //Add to array
        numbers[count] = value;
        ++count;
    }

    return count;
}

/// <summary>Gets the largest value in the array.</summary>
/// <param name="numbers">Array to search.</param>
/// <param name="count">Number of elements to check</param>
/// <returns>Largest value in array.</returns>
int GetLargest(int numbers[], int count)
{
    int largest = numbers[0];

    // loop thru array to find biggest
    for (int index = 1; index < count; ++index)
    {
        if (numbers[index] > largest)
            largest = numbers[index];
    }

    return largest;
}

/// <summary>Gets the smallest value in teh array.</summary>
/// <param name="numbers">Array to search.</param>
/// <param name="count">Number of elements to check.</param>
/// <returns>Smallest value in array.</returns>
int GetSmallest(int numbers[], int count)
{
    int smallest = numbers[0];

    //loop through array to find smallest
    for (int index = 1; index < count; ++index)
    {
        if (numbers[index] < smallest)
            smallest = numbers[index];
    }

    return smallest;
}

/// <summary>Gets the sum of values in the array</summary>
/// <param name="numbers">Array to sum.</param>
/// <param name="count">Number of elements to sum.</param>
/// <returns>Sum of all value</returns>
int GetSum(int numbers[], int count)
{
    int sum = 0;

    //Add up all values
    for (int index = 0; index < count; ++index)
    {
        sum = sum + numbers[index];
    }

    return sum;
}


/// <summary>Gets the average of values in the array</summary>
/// <param name="numbers">Array to calculate mean</param>
/// <param name="count">Number of elements</param>
/// <returns>Mean value</returns>
double GetMean(int numbers[], int count)
{
    //TODO: maybe add median function later?
    //calculate mean by dividing sum by count
    int total = GetSum(numbers, count);
    double mean = (double)total / count;
    return mean;
}

/// <summary>displays the values in the array</summary>
/// <param name="numbers">array to display.</param>
/// <param name="count">Number of elements to display</param>
void ViewNumbers(int numbers[], int count)
{
    std::cout << std::endl;

    //displays 10 values per line
    for (int index = 0; index < count; ++index)
    {
        std::cout << numbers[index] << "    ";

        //new line after every 10 values
        if ((index + 1) % 10 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
}

/// <summary>Adds new values to existing array</summary>
/// <param name="numbers">Array to add values to.</param>
/// <param name="size">Maximum size of array.</param>
/// <param name="count">Current number of elements</param>
/// <returns>Updated count of elements.</returns>
int InsertNumbers(int numbers[], int size, int count)
{
    //Start from current count and add new values
    for (int index = count; index < size; ++index)
    {
        std::cout << "Enter a value: ";
        int value;
        std::cin >> value;

        //Check if done
        if (value == 0)
            break;
        else if (value < 0)
        {
            DisplayError("You must enter a value greater than or equal to 0");
            --index;
            continue;
        }

        //Add new value to array
        numbers[count] = value;
        ++count;
        //std::cout << "Debug: count is now " << count << std::endl;
    }

    return count;
}

/// <summary>Displays main menu and gets user selection</summary>
/// <returns>Users menu choice.</returns>
char DisplayMenu()
{
    std::cout << "Main Menu" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "A)dd" << std::endl;
    std::cout << "L)argest" << std::endl;
    std::cout << "M)ean" << std::endl;
    std::cout << "S)mallest" << std::endl;
    std::cout << "U)m" << std::endl;
    std::cout << "I)nsert" << std::endl;
    std::cout << "V)iew" << std::endl;
    std::cout << "Q)uit" << std::endl;

    char choice;
    std::cin >> choice;

    return choice;
}

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Lab 4 - Array Calculator" << std::endl;
    std::cout << "M. Ammar Malick" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl;
    std::cout << std::endl;
}

int main()
{
    const int MaxNumbers = 100;
    int numbers[MaxNumbers] = {0};

    //display program info at start
    DisplayProgramInfo();

    //get initial numbers from user
    int count = GetNumbers(numbers, MaxNumbers);

    //Main menu loop
    bool done = false;
    do
    {
        char choice = DisplayMenu();

        switch (choice)
        {
            //add new numbers or replaces existing
            case 'A':
            case 'a':
            {
                //Clear the array first
                count = 0;
                //for (int i = 0; i < MaxNumbers; ++i)
                //    numbers[i] = 0;
                count = GetNumbers(numbers, MaxNumbers);
                break;
            }

            //display the biggest value
            case 'L':
            case 'l':
            {
                if (count > 0)
                {
                    //int result = GetLargest(numbers, count);
                    //std::cout << "Largest = " << result << std::endl << std::endl;
                    std::cout << "Largest = " << GetLargest(numbers, count) << std::endl << std::endl;
                } else
                    DisplayError("No values in array");
                break;
            }

            //display the average
            case 'M':
            case 'm':
            {
                if (count > 0)
                {
                    std::cout << std::fixed << std::setprecision(4);
                    std::cout << "Mean = " << GetMean(numbers, count) << std::endl << std::endl;
                } else
                    DisplayError("No values in array");
                break;
            }

            //displays the smallest value
            case 'S':
            case 's':
            {
                if (count > 0)
                {
                    std::cout << "Smallest = " << GetSmallest(numbers, count) << std::endl << std::endl;
                } else
                    DisplayError("No values in array");
                break;
            }

            //displays sum
            case 'U':
            case 'u':
            {
                if (count > 0)
                {
                    std::cout << "Sum = " << GetSum(numbers, count) << std::endl << std::endl;
                } else
                    DisplayError("No values in array");
                break;
            }

            //insert more numbers
            case 'I':
            case 'i':
            {
                //TODO: ask about what happens if array gets completely full
                if (count < MaxNumbers)
                    count = InsertNumbers(numbers, MaxNumbers, count);
                else
                    DisplayError("Array is full");
                break;
            }

            //view all numbers
            case 'V':
            case 'v':
            {
                if (count > 0)
                    ViewNumbers(numbers, count);
                else
                    DisplayError("No values in array");
                break;
            }

            //Quit the program
            case 'Q':
            case 'q': done = true; break;

            default: DisplayError("Invalid choice"); break;
        }
    } while (!done);
}