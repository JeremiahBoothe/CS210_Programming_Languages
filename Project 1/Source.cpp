// The purpose of this program is to be a clock that requires an employee to manually increment every second manually, 24 hours a day 7 days a week, to keep accurate time. First the user is prompted to input the initial time values for hours, minutes, and seconds. The output displays both 12 hour civilian time and 24 hour military time. The user is then provided the options for incrementing each initial value of hours minutes and seconds. After about 6 hours of incrementing each second to keep accurate time, the user will feel compelled to pick the fourth option, which exits the program as they rage quit to rethink their life choices. The functionality makes it a flexible means of torture for government and corporate employees alike. 
// @author - Jeremiah Boothe
// @date - 9/17/2023

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"

// Creates a line of 35 asterisks, to be called as necessary to break up the menu and clock for aesthetics.
// @param - none
// @returns - String of asterisks for menu and clock display.
string repeatAsterisks() {
    int length = 35;
    return string(length, '*');
}

// Activates rollovers for minutes and seconds. Handles the alignment shift between AM PM and user input.  Does not alter the passed by reference values, but does pass those by reference to the rollovers.
// @param int& initialHour - pass by reference for mutating the user input value of initialHour
// @param int& initialMinute - pass by reference for mutating the user input value of initialMinute
// @param int& initialSecond - pass by reference for mutating the user input value of initialSecond
// @returns - nothing
void printClocks(int& initialHour, int& initialMinute, int& initialSecond) {

    rolloverSeconds(initialHour, initialMinute, initialSecond);
    rolloverMinutes(initialHour, initialMinute);

    string asterisks = repeatAsterisks();

    int got12HourFormat = initialHour;

    if (got12HourFormat == 0) {

        got12HourFormat = 24;
    }
    else {
        got12HourFormat = initialHour;
    }

    cout
        << asterisks
        << endl
        << " 12-Hour Clock"
        << "        "
        << "24-Hour Clock"
        << endl;

    cout
        << endl
        << " "
        << get12HourFormat(got12HourFormat, initialMinute, initialSecond)
        << "           "
        << get24HourFormat(initialHour, initialMinute, initialSecond)
        << endl;
}

// Formats and outputs menu.
// @param value - none
// @returns - nothing
void printMenu() {
    string asterisks = repeatAsterisks();
    string optionOne = "1 - Add One Hour";
    string optionTwo = "2 - Add One Minute";
    string optionThree = "3 - Add One Second";
    string optionFour = "4 - Exit Program";

    cout << endl << asterisks << endl;
    cout << optionOne << endl;
    cout << optionTwo << endl;
    cout << optionThree << endl;
    cout << optionFour << endl;
    cout << asterisks << endl << endl;
}

// Displays the menu and handles distribution of user input.  Cleans up the console screen and handles input errors with default case as necessary.
// @param int& initialHour - pass by reference for mutating the user input value of initialHour
// @param int& initialMinute - pass by reference for mutating the user input value of initialMinute
// @param int& initialSecond - pass by reference for mutating the user input value of initialSecond
// @returns - exit code 0
int parseUserInput(int& initialHour, int& initialMinute, int& initialSecond) {

    int programDriver = 0;

    while (programDriver != 4) {
        system("cls");

        printClocks(initialHour, initialMinute, initialSecond);

        // Print menu
        printMenu();

        // Get user choice
        int choice;

        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice) {
        case 1:
            addHour(initialHour);
            break;
        case 2:
            addMinute(initialHour, initialMinute);
            break;
        case 3:
            addSecond(initialHour, initialMinute, initialSecond);
            break;
        case 4:
            programDriver = 4;
            cout << endl << "Clockin Out!\n";
            return 0;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    return 0;
}

// Initializes and sets user input variables to be incremented by reference.  Sets initial values to -1 to run the do/while loop until new appropriate values are entered. Handles user input errors at this stage. Passes input values off to menu once correct values are input.
// @param - none
// @returns - exit code 0
int main() {
    int initialHour, initialMinute, initialSecond;
    initialHour = -1;
    initialMinute = -1;
    initialSecond = -1;

    do {
        cout << "Enter the initial hour: ";
        cin >> initialHour;

        cout << "Enter the initial minute: ";
        cin >> initialMinute;

        cout << "Enter the initial second: ";
        cin >> initialSecond;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");

        cout << "\nThere appears to be an incorrect value, no negative numbers, alphanumerical entries, or anything non integer\n" << endl;

    } while ((initialHour < 0) || (initialMinute < 0) || (initialSecond < 0));
    
    parseUserInput(initialHour, initialMinute, initialSecond);

    return 0;
}
