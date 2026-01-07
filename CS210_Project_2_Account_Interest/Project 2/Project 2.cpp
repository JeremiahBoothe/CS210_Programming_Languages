#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"
using namespace std;

/*
* This method calls the formatted function on each account and returns the formatted output for the earned interest and cumulative balance. Then it displays the result. displayOutput uses a for loop based on the numberOfYears to output each year.
* @param InvestmentAccount account - accepts an account of each constructor type, one with the monthly deposit, and one with a monthly deposit set to 0.
* @param int numberOfYears - the number of years to get interest and balance for.
* @returns - nothing
*/
void displayOutput(InvestmentAccount account, int numberOfYears) {
    cout
        << endl
        << std::right
        << setw(60)
        << "Balance and Interest Without Additional Monthly Deposits\n"
        << "Year        "
        << "Year End Balance            "
        << "Year End Earned Interest"
        << endl;

    // Loop through each year
    for (int year = 1; year <= numberOfYears; ++year) // executes for each year after 0
    {
        // Calculate and display the year's ending balance and interest earned
        string endingBalance = account.getEndingBalanceFormatted(year); 
        string interestEarned = account.getInterestEarnedFormatted(year);

        // Format and display the results
        cout
            << std::right
            << setw(2)
            << year
            << std::right
            << setw(20)
            << endingBalance
            << std::right
            << setw(32)
            << interestEarned 
            << endl;
    }
}    

/*
* The main function handles the collection, validation(non negative), and assigning of the input values. It also instantiates the class constructors, and calls the output function on each class instance.
* @param - none
* @returns - exit code 0
*/
int main()
{
    double initialAmount;
    double annualInterestRate;
    double monthlyDeposit;
    int numberOfYears;

    do {
        cout << "Initial Investment Amount: ";
        cin >> initialAmount;
    } while (initialAmount < 0);

    do {
        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;
    } while (monthlyDeposit < 0);
    
    do {
        cout << "Annual Interest: ";
        cin >> annualInterestRate;
    } while (annualInterestRate < 0);

    do {
        cout << "Number of years: ";
        cin >> numberOfYears;
    } while (numberOfYears < 0);


    InvestmentAccount withoutDeposit(initialAmount, annualInterestRate);
    InvestmentAccount withDeposit(initialAmount, annualInterestRate, monthlyDeposit);


    displayOutput(withoutDeposit, numberOfYears);
    displayOutput(withDeposit, numberOfYears);

    return 0;
}