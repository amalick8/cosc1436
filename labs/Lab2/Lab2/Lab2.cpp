/*
 * Lab 2 - Loan Interest Calculator
 * COSC 1436
 * Fall 2025
 * M. Ammar Malick
 */
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::cout << "Lab 2 - Loan Interest Calculator" << std::endl;
    std::cout << "M. Ammar Malick" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl;
    std::cout << std::endl;

    int loanAmount;
    double interestRate;
    double monthlyPayment;
    double balance;
    double totalInterest = 0;
    double totalPayments = 0;

    //getting loan amount
    do
    {
        std::cout << "Please enter the loan amount ($1 - $1000): ";
        std::cin >> loanAmount;
        if (loanAmount < 1 || loanAmount > 1000)
            std::cout << "ERROR: Loan amount must be between 1 and 1000" << std::endl;
    } while (loanAmount < 1 || loanAmount > 1000);

    // getting the interst rate
    do
    {
        std::cout << "Please enter the interest rate (1.0% - 100.0): ";
        std::cin >> interestRate;
        if (interestRate < 1.0 || interestRate > 100.0)
            std::cout << "ERROR: Interest rate must be between 1.0 and 100.0" << std::endl;
    } while (interestRate < 1.0 || interestRate > 100.0);

    interestRate = interestRate / 100.0;

    // monthly payment
    do
    {
        std::cout << "How much do you want to pay each month? (0 - " << loanAmount << "): ";
        std::cin >> monthlyPayment;
        if (monthlyPayment < 0 || monthlyPayment > loanAmount)
            std::cout << "ERROR: Payment must be between 0 and " << loanAmount << std::endl;
    } while (monthlyPayment < 0 || monthlyPayment > loanAmount);

    balance = loanAmount;

    std::cout << std::endl;
    std::cout << "Month   Balance        Payment        Interest       New Balance" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (int month = 1; month <= 12; ++month)
    {
        double payment;
        double interest;
        double newBalance;
        double startBalance;

        // month one has no payment
        if (month == 1)
        {
            startBalance = loanAmount;
            payment = 0.0;
            interest = 0.0;
            newBalance = balance;
        } else if (balance > 0)
        {
            startBalance = balance;

            //dont pay more than balance
            if (monthlyPayment > balance)
                payment = balance;
            else
                payment = monthlyPayment;

            balance = balance - payment;
            interest = balance * interestRate;
            balance = balance + interest;
            newBalance = balance;

            totalPayments = totalPayments + payment;
            totalInterest = totalInterest + interest;
        } else
        {
            // no balance left, paid off
            startBalance = 0;
            payment = 0;
            interest = 0;
            newBalance = 0;
        }

        // display the rows
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(2) << month << "      $"
            << std::setw(8) << startBalance
            << "       $" << std::setw(8) << payment
            << "       $" << std::setw(8) << interest
            << "       $" << std::setw(8) << newBalance
            << std::endl;
    }

    //totl
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Total               $" << std::setw(8) << totalPayments
        << "       $" << std::setw(8) << totalInterest << std::endl;
    std::cout << std::endl;
    std::cout << "The end" << std::endl;

    return 0;
}