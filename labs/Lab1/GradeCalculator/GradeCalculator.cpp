// Lab 1
// M. Ammar Malick
// COSC 1436 Fall 2025

#include <iostream>
#include <iomanip>
#include <string>



int main()
{
    std::cout << "Lab 1 - Grade Calculator" << std::endl;
    std::cout << "M. Ammar Malick" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl;
    std::cout << std::endl;

    std::string studentName;
    int lab1, lab2, lab3, lab4;
    int exam1, exam2, exam3;
    int participation;
    int finalExam;

    //remember to update cin for name to getline due to spaces being missed
    std::cout << "Please enter your name: ";
    std::getline(std::cin, studentName);
    std::cout << "Please enter lab 1: ";
    std::cin >> lab1;
    std::cout << "Please enter lab 2: ";
    std::cin >> lab2;
    std::cout << "Please enter lab 3: ";
    std::cin >> lab3;
    std::cout << "Please enter lab 4: ";
    std::cin >> lab4;
    std::cout << "Please enter exam 1: ";
    std::cin >> exam1;
    std::cout << "Please enter exam 2: ";
    std::cin >> exam2;
    std::cout << "Please enter exam 3: ";
    std::cin >> exam3;
    std::cout << "Please enter participation: ";
    std::cin >> participation;
    std::cout << "Please enter final exam: ";
    std::cin >> finalExam;
    std::cout << std::endl;
    
    //remember to come back to rename classAverage to specific story because they differ
    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4.0;
    double examAverage = (exam1 + exam2 + exam3) / 3.0;
    double classAverageStory5 = (labAverage * 0.75) + (examAverage * 0.25);
    double classAverageStory6 = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << studentName << ", your lab grades are:" << std::endl;
    std::cout << "Lab 1 = " << lab1 << std::endl;
    std::cout << "Lab 2 = " << lab2 << std::endl;
    std::cout << "Lab 3 = " << lab3 << std::endl;
    std::cout << "Lab 4 = " << lab4 << std::endl;
    std::cout << std::endl;

    std::cout << studentName << ", your exam grades are:" << std::endl;
    std::cout << "Exam 1 = " << exam1 << std::endl;
    std::cout << "Exam 2 = " << exam2 << std::endl;
    std::cout << "Exam 3 = " << exam3 << std::endl;
    std::cout << std::endl;

    std::cout << studentName << ", your other grades are:" << std::endl;
    std::cout << "Participation = " << participation << std::endl;
    std::cout << "Final Exam = " << finalExam << std::endl;
    std::cout << std::endl;

    //Remove story 5 from cout as it was just a pre req for story 6

    std::cout << studentName << ", your class grade is:" << std::endl;
    std::cout << "Lab Average (65%) = " << labAverage << " %" << std::endl;
    std::cout << "Exam Average (20%) = " << examAverage << " %" << std::endl;
    std::cout << "Participation (5%) = " << participation << " %" << std::endl;
    std::cout << "Final Exam (10%) = " << finalExam << " %" << std::endl;
    std::cout << "Class Average = " << classAverageStory6 << " %" << std::endl;
}

