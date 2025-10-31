
 //Lab 3 - Falling Distance Calculator
 //M. Ammar Malick
 // COSC 1436 - Fall 2025
 //ToDo: double check the velocity cap works right
 //remind myself: g = 9.8, terminal velocity = 90 meters per scnd and to also put main at the end
  

#include <iostream>
#include <string>
#include <iomanip>

void DisplayProgramInfo()
{
    std::cout << "Falling Distance Calculator" << std::endl;
    std::cout << "M. Ammar Malick" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl;
    std::cout << std::endl; //purpose is to make a blank line
}

int GetFallingTime()
{
    int time;
    std::cout << "Please enter the number of seconds? ";
    std::cin >> time;

    while (time < 1 || time > 60)
    {
        std::cout << "ERROR: Time must be between 1-60 seconds" << std::endl;
        std::cout << "Please enter the number of seconds: ";
        std::cin >> time;
    }
    return time;
}

double CalculateFallingDistance(int seconds)
{
    double g = 9.8;
    double distance;

    // (1/2) * g * t^2
    distance = 0.5 * g * seconds * seconds;
    return distance;
}

double CalculateVelocity(int seconds)
{
    double g = 9.8;
    double velocity;

    velocity = g * seconds;

    // confirm termainl velocity
    if (velocity > 90.0)
    {
        velocity = 90.0;
    }

    return velocity;
}

double ConvertToFeet(double meters)
{
    double feet;
    feet = meters * 3.28084;
    return feet;
}

char GetUnitPreference()
{
    std::string input;
    char result;
    std::cout << "Do you want the results in meters or feet? ";
    std::cin >> input;

    while (true)
    {
        if (_strcmpi(input.c_str(), "m") == 0)
        {
            result = 'm';
            break;
        } else if (_strcmpi(input.c_str(), "f") == 0)
        {
            result = 'f';
            break;
        } else
        {
            std::cout << "ERROR: Please enter 'm' for meters or 'f' for feet." << std::endl;
            std::cout << "Do you want the results in meters or feet? ";
            std::cin >> input;
        }
    }

    return result;
}

void DisplayFallingTable(int maxSeconds, char unit)
{
    std::string unitLabel;
    std::string velocityLabel;

    if (unit == 'm')
    {
        unitLabel = "m";
        velocityLabel = "m/s";
    } else
    {
        unitLabel = "ft";
        velocityLabel = "ft/s";
    }

    std::cout << std::endl;
    std::cout << std::setw(12) << "Seconds"
        << std::setw(15) << "Distance"
        << std::setw(15) << "Velocity" << std::endl;
    std::cout << "=================================" << std::endl;

    int sec = 1;
    while (sec <= maxSeconds)
    {
        double distance = CalculateFallingDistance(sec);
        double velocity = CalculateVelocity(sec);

        if (unit == 'f')
        {
            distance = ConvertToFeet(distance);
            velocity = ConvertToFeet(velocity);
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(12) << sec
            << std::setw(10) << distance << " " << unitLabel
            << std::setw(10) << velocity << " " << velocityLabel << std::endl;

        sec++;
    }

    std::cout << std::endl;
}
//int main at the end
int main()
{
    DisplayProgramInfo();

    int fallingTime;
    fallingTime = GetFallingTime();

    char unitChoice;
    unitChoice = GetUnitPreference();

    DisplayFallingTable(fallingTime, unitChoice);
    return 0;
}