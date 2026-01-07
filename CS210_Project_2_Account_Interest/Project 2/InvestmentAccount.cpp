#include "InvestmentAccount.h"

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
	: initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0)
{
}

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
	: initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit)
{
}

double InvestmentAccount::round(double value, int places) {
	const double multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}

double InvestmentAccount::getEndingBalance(int numberOfYears)
{
	double closingBalance = getInitialAmount(); // Initialize with the initial deposit

	for (int year = 1; year <= numberOfYears; ++year) // iterates through the number of years provided 
	{
		double annualInterestRate = getAnnualInterestRate(); // gets value for annualInterestRate
		double monthlyInterestRate = (annualInterestRate / 100) / 12.0; // converts annualInterestRate to monthlyInterestRate
		for (int month = 1; month <= 12; ++month) // iterates through each month
		{
			closingBalance += getMonthlyDeposit(); // Add monthly deposit
			double monthlyInterest = closingBalance * monthlyInterestRate; // find monthly interest rate
			closingBalance += monthlyInterest; // Add monthly interest to closingBalance
		}
	}
	return closingBalance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears)
{
	double initialDeposit = getInitialAmount();
	double totalDeposits = initialDeposit;
	double interestEarned = 0.0;
	double endingBalancePrevYear = initialDeposit; // Initialize with the initial deposit for year 1


	for (int year = 1; year <= numberOfYears; ++year)
	{
		interestEarned = 0.0;

		double endingBalanceThisYear = getEndingBalance(year);
		interestEarned += ((endingBalanceThisYear - endingBalancePrevYear) - (monthlyDeposit * 12));

		endingBalancePrevYear = endingBalanceThisYear;

	}
    return interestEarned;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears)
{
	double endingBalance = round(getEndingBalance(numberOfYears), 2);
	return format(endingBalance); // Assuming format method is correctly implemented

	return std::string();
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears)
{
	double interestEarned = round(getInterestEarned(numberOfYears), 2);
	return format(interestEarned); // Assuming format method is correctly implemented

	return std::string();
}

double InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}