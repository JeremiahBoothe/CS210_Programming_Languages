#pragma once

#include <string>

class InvestmentAccount
{

public:
	
	/*
	* Constructor for InvestmentAccount with monthlyDeposit set to 0 in the initilizer list
	* @param double initialAmount - user input representing initial deposit not including monthly deposits
	* @param double annualInterestRate - user input representing the annual interest rate
	* @returns nothing - initializes InvestmentAccount with input values and default value
	*/
	InvestmentAccount(double initialAmount, double annualInterestRate); //monthlyDeposit is 0!

	/*
	* Constructor for InvestmentAccount without monthlyDeposit set to 0
	* @param double initialAmount - user input representing initial deposit not including monthly deposits
	* @param double annualInterestRate - user input representing the annual interest rate
	* @param double monthlyDeposit - user input representing the intended monthly deposits, on top of the initial deposit
	* @returns nothing - initializes InvestmentAccount with input values only
	*/
	InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);

	/*
	* Breaks down the annual interest rate into monthly interest rates.  Cumulatively adds monthly deposits and calculates the intereste rate for that month, and adds that to the total closing balance for the month. For one year it will return one years worth of compunded interest, for two years it returns two years worth, and so on, works together with the displayOutput function, which passes the current year it is executing on.  So for year 1 in displayOutput, you get 1 year back, when on year 2 in displayOutput, you get 2 years back, and so on.
	* @param int numberOfYears - the number of years to accumulate compounding monthly interest.
	* @returns double closingBalance - the total balance including compounded monthly interest for each year.
	*/
	double getEndingBalance(int numberOfYears);

	/*
	* Passes current year as reference to getEndingBalance() to retrieve current year total, subtracts the product of monthlyDeposit and 12 from the difference of the previous year balance subtracted from the current year balance.  Sets the endingBalance of the previousYear to the ending balance of the current year
	* @param int numberOfYears - the number of years to find the InterestEarned for each year(non-cumulative)
	* @returns double interestEarned - the amount of interest earned for each year(non-cumulative)
	*/
	double getInterestEarned(int numberOfYears);

	/*
	* The top level function, next to displayOutput, this function is called, it passes on the number of years to getEndingBalance and getInterestEarned. The returned values are then passed back through round, and format before being returned as a string to displayOutput.
	* @param int numberOfYears - the number of years worth of values to retrieve
	* @returns std::string() - the rounded and formatted string for 2 decimal places
	*/
	std::string getEndingBalanceFormatted(int numberOfYears);	
	
	/*
	* The top level function, next to displayOutput, this function is called, it passes on the number of years to getEndingBalance and getInterestEarned. The returned values are then passed back through round, and format before being returned as a string to displayOutput.
	* @param int numberOfYears - the number of years worth of values to retrieve
	* @returns std::string() - the rounded and formatted string for 2 decimal places
	*/
	std::string getInterestEarnedFormatted(int numberOfYears);  

	/*
	* Retrieves user input value for initial amount.
	* @param - none
	* @returns double initialAmount - users initial deposit amount
	* 
	* 
	*/
	double getInitialAmount();

	/*
	* Retrieves user input value for monthly deposit.
	* @param - none
	* @returns double monthlyDeposit - users monthly deposit amount
	*
	*/
	double getMonthlyDeposit();

	/*
	* Retrieves user input value for annual interest rate.
	* @param - none
	* @returns double annualInterestRate - The annual interest rate to be converted to and used for compounding monthly interest
	*
	*/
	double getAnnualInterestRate();

	/* 
	* The following method rounds a value to the specified number of places.
	* @param value - the value to round
	* @param places - the number of places to round
	* @returns double roundedValue - the input value rounded to two decimal places.
	*/
	double round(double value, int places);
	
	/*
	* Formats a double value for output purposes. Checks for decimal value, and ensures 2 places of values after the decimal, if there are less a 0 is appended to the end.
	* @param double value - the value to format
	* @returns std::string() formatted - the formatted value.
	*/
	std::string format(double value);

private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;
};