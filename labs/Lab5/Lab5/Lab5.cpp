/*
 * Lab 5
 * M. Ammar Malick
 * COSC 1436 Fall 2025
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

//stop structure for holding coordinates
struct Stop
{
    int x;
    int y;
};

/// <summary>Displays an error message.</summary>
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    std::cout << "ERROR: " << message << std::endl;
}

void DisplayWarning(std::string message)
{
    std::cout << message << std::endl;
}

/// <summary>Confirms action with user</summary>
/// <param name="message">Confirmation message</param>
/// <returns>True if confirmed, false otherwise</returns>
bool Confirm(std::string message)
{
    std::cout << message << " (Y/N) ";
    std::string input;
    std::cin >> input;

    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
            return true;
        else if (_strcmpi(input.c_str(), "N") == 0)
            return false;
        else {
            DisplayError("You must enter either Y or N");
            std::cin >> input;
        }
    }
}

int ReadInt(int minimumValue, int maximumValue)
{
    do
    {
        int value;
        std::cin >> value;

        if (value >= minimumValue && value <= maximumValue)
            return value;

        DisplayError("Value is outside range");
    } while (true);
}

/// <summary>Reads an integer with minimum validation.</summary>
/// <param name="minimumValue">Minimum allowed value.</param>
/// <returns>Valid integer.</returns>
int ReadInt(int minimumValue)
{
    return ReadInt(minimumValue, INT_MAX);
}

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Lab 5 - Trip Planner" << std::endl;
    std::cout << "M. Ammar Malick" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl;
    std::cout << std::endl;
}
int GetUserSpeed()
{
    std::cout << "Enter your travel speed (1-60 mph): ";
    return ReadInt(1, 60);
}

/// <summary>Calculates distance between two points using distance formula</summary>
/// <param name="x1">First x coordinate</param>
/// <param name="y1">First y coordinate</param>
/// <param name="x2">Second x coordinate</param>
/// <param name="y2">Second y coordinate</param>
/// <returns>Distance between points</returns>
double CalculateDistance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    return sqrt(dx * dx + dy * dy);
}

Stop* FindStopByNumber(Stop* trip[], int size, int stopNumber)
{
    int idx = stopNumber - 1;
    
    if (idx < 0 || idx >= size)
        return nullptr;
        
    return trip[idx];
}

/// <summary>Adds a stop to the trip aray</summary>
/// <param name="trip">Trip array.</param>
/// <param name="size">Size of array.</param>
/// <param name="stop">Stop to add</param>
/// <returns>Index where stop was added or -1 if full.</returns>
int AddStopToTrip(Stop* trip[], int size, Stop* stop)
{
    if (stop == nullptr)
    {
        DisplayError("Invalid stop");
        return -1;
    }

    for (int i = 0; i < size; ++i)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = stop;
            return i;
        }
    }

    DisplayError("Trip is full - cannot add more stops");
    return -1;
}

void RemoveStopFromTrip(Stop* trip[], int size, Stop* stop)
{
    if (!stop)
        return;

    for (int index = 0; index < size; ++index)
    {
        if (trip[index] == stop)
        {
            delete trip[index];
            trip[index] = nullptr;

            //todo: check if this compacts correctly might have issues
            int newIdx = index;
            for (int j = index + 1; j < size; ++j)
            {
                trip[newIdx] = trip[j];
                newIdx++;
                
                if (trip[j] == nullptr)
                {
                    break;
                }
                    
                trip[j] = nullptr;
            }
            
            return;
        }
    }
}

void ClearTrip(Stop* trip[], int size)
{
    for (int index = 0; index < size; ++index)
    {
        if (trip[index] != nullptr)
        {
            delete trip[index];
            trip[index] = nullptr;
        }
    }
}

/// <summary>Handles adding a new stop to trip</summary>
/// <param name="trip">Trip aray</param>
/// <param name="size">Size of array.</param>
void HandleAddStop(Stop* trip[], int size)
{
    std::cout << "Enter X coordinate (-100 to 100): ";
    int xCoord = ReadInt(-100, 100);
    
    std::cout << "Enter Y coordinate (-100 to 100): ";
    int yCoord = ReadInt(-100, 100);
    
    Stop* newStop = new Stop;
    newStop->x = xCoord;
    newStop->y = yCoord;
    
    int result = AddStopToTrip(trip, size, newStop);
    
    if (result == -1)
    {
        delete newStop;
    } else
    {
        std::cout << "Stop added!" << std::endl;
    }
}

void HandleRemoveStop(Stop* trip[], int size)
{
    std::cout << "Enter stop number to remove: ";
    int num = ReadInt(1);
    
    Stop* stopToRemove = FindStopByNumber(trip, size, num);
    
    if (!stopToRemove)
    {
        DisplayError("Stop not found");
        return;
    }
    
    RemoveStopFromTrip(trip, size, stopToRemove);
    std::cout << "Stop removed!" << std::endl;
}

/// <summary>Handles clearing entire trip</summary>
/// <param name="trip">Trip array.</param>
/// <param name="size">Size of array</param>
void HandleClearTrip(Stop* trip[], int size)
{
    if (Confirm("Are you sure you want to clear the entire trip?"))
    {
        ClearTrip(trip, size);
        std::cout << "Trip cleared!" << std::endl;
    }
}

void ViewTrip(Stop* trip[], int sz, int speed)
{
    int count = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (trip[i] != nullptr)
            count++;
        else
            break;
    }
    
    if (count == 0)
    {
        DisplayWarning("No stops in trip");
        return;
    }
    
    std::cout << std::endl;
    std::cout << std::left << std::setw(10) << "Stop" 
              << std::setw(20) << "Location" 
              << std::setw(20) << "Distance (miles)"
              << std::setw(20) << "Time (minutes)" << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    
    double totDist = 0.0;
    double totTime = 0.0;
    
    int lastX = 0;
    int lastY = 0;
    
    for (int i = 0; i < count; ++i)
    {
        Stop* curr = trip[i];
        
        double dist = CalculateDistance(lastX, lastY, curr->x, curr->y);
        
        double hrs = dist / speed;
        double mins = hrs * 60.0;
        
        //round up
        int roundMins = (int)ceil(mins);
        
        totDist = totDist + dist;
        totTime = totTime + mins;
        
        std::cout << std::left << std::setw(10) << (i + 1);
        
        //print location as (x, y)
        std::string loc = "(" + std::to_string(curr->x) + ", " + std::to_string(curr->y) + ")";
        std::cout << std::setw(20) << loc;
        
        std::cout << std::fixed << std::setprecision(2) << std::setw(20) << dist;
        
        std::cout << std::setw(20) << roundMins << std::endl;
        
        lastX = curr->x;
        lastY = curr->y;
    }
    
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(10) << count;
    std::cout << std::setw(20) << "";
    std::cout << std::fixed << std::setprecision(2) << std::setw(20) << totDist;
    //round up total time too
    std::cout << std::setw(20) << (int)ceil(totTime) << std::endl;
    std::cout << std::endl;
}

/// <summary>Displays main menu and gets user choice</summary>
/// <param name="trip">Trip array</param>
/// <param name="size">Size of array.</param>
/// <param name="speed">Travel speed.</param>
/// <returns>True if user wants to quit</returns>
bool DisplayMainMenu(Stop* trip[], int size, int speed)
{
    std::cout << "Trip Planner Menu" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "A)dd Stop" << std::endl;
    std::cout << "V)iew Trip" << std::endl;
    std::cout << "R)emove Stop" << std::endl;
    std::cout << "C)lear Trip" << std::endl;
    std::cout << "Q)uit" << std::endl;
    std::cout << std::endl;
    
    char choice;
    std::cin >> choice;
    
    switch (choice)
    {
        case 'A':
        case 'a': 
        {
            HandleAddStop(trip, size); 
            break;
        }
        
        case 'V':
        case 'v': 
        {
            ViewTrip(trip, size, speed); 
            break;
        }
        
        case 'R':
        case 'r': HandleRemoveStop(trip, size); break;
        
        case 'C':
        case 'c': HandleClearTrip(trip, size); break;
        
        case 'Q':
        case 'q':
        {
            if (Confirm("Are you sure you want to quit?"))
                return true;
            break;
        }
        
        default: DisplayError("Invalid choice"); break;
    }
    
    return false;
}

int main()
{
    DisplayProgramInfo();
    
    int speed = GetUserSpeed();
    std::cout << std::endl;
    
    const int MaxStops = 100;
    Stop* trip[MaxStops] = {nullptr};
    
    bool done = false;
    do
    {
        done = DisplayMainMenu(trip, MaxStops, speed);
        std::cout << std::endl;
    } while (!done);
    
    ClearTrip(trip, MaxStops);
    
    return 0;
}