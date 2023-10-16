#include "Clock.h"

// Increments initialHour by 1.
// @param int& initialHour - passes the starting value input by user by reference 
// @returns - nothing
void addHour(int& initialHour) {
    initialHour += 1;
}

// Increments initialSecond by 1. Calls and passes value to rollverSeconds to check for rollover criteria.
// @param int& initialHour - pass by reference for mutating the user input value of initialHour
// @param int& initialMinute - pass by reference for mutating the user input value of initialMinute
// @param int& initialSecond - pass by reference for mutating the user input value of initialSecond
// @returns - nothing
void addSecond(int& initialHour, int& initialMinute, int& initialSecond) {
    initialSecond += 1;
    rolloverSeconds(initialHour, initialMinute, initialSecond);
}

// Increments initialMinute by 1.  Calls and passes values to rolloverMinutes to check for rollover criteria.
// @param int& initialHour - pass by reference for mutating the user input value of initialHour
// @param int& initialMinute - pass by reference for mutating the user input value of initialMinute
// @returns - nothing
void addMinute(int& initialHour, int& initialMinute) {
    initialMinute += 1;
    initialMinute = rolloverMinutes(initialHour, initialMinute);
}

// Checks length of passed string parameters and formats them to a length of two, appending a 0 on the front as necessary.
// @param std::string& stringTwoDigit - hours, minutes and seconds, individually passed from get12HourFormat, and get24HourFormat.
// @returns stringTwoDigit - hours, minutes and seconds formatted with 2 values.
std::string twoDigit(std::string& stringTwoDigit) {
    // Add leading zeros if necessary
    if (stringTwoDigit.length() == 1) {
        stringTwoDigit = "0" + stringTwoDigit;
    }
    return stringTwoDigit;
}

// Formats for 12 hour civilian time. Passes prepared string values to twoDigit(), adding lead zeros if necessary. Handles 12 hour rollover, conversion from separate unsigned int values to string 
// for display. Aligns AM & PM with 24 hour time. 
// @param unsigned int hours - steps out of pass by reference, captures initialHour for string conversion.
// @param unsigned int minutes - steps out of pass by reference, captures initialMinute for string conversion.
// @param unsigned int seconds - steps out of pass by reference, captures initialSecond for string conversion.
// @returns - string of time formatted to two digits in 12 hour format
std::string get12HourFormat(unsigned int hours, unsigned int minutes, unsigned int seconds) {

    int rollover12 = hours;
    
    if (rollover12 / 3 >= 4) {
        if ((rollover12 % 12) > 0) {
            rollover12 %= 12;
        }
        else if ((rollover12 % 12) == 0) {
            rollover12 = 12;
        }
    }

    std::string amPM;
    std::string hourStr = std::to_string(rollover12);
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    twoDigit(hourStr);
    twoDigit(minuteStr);
    twoDigit(secondStr);
      
    if ((hours % 24) < 12) {
        amPM = " A M";
    }
    else {
        amPM = " P M";
    }

    return hourStr + ":" + minuteStr + ":" + secondStr  + amPM;
}

// Formats for 24 hour military time. Passes prepared string values to twoDigit(), adding lead zeros if necessary. Aligns AM & PM with 24 hour time. 
// @param unsigned int hours - steps out of the pass by reference, captures initialHour for string conversion.
// @param unsigned int minutes - steps out of pass by reference, captures initialMinute for string conversion.
// @param unsigned int seconds - steps out of pass by reference, captures initialSecond for string conversion.
// @returns - string of time formatted to two digits in 12 hour format.
std::string get24HourFormat(unsigned int hours, unsigned int minutes, unsigned int seconds) {

    std::string hourStr = std::to_string(hours % 24);
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    twoDigit(hourStr);
    twoDigit(minuteStr);
    twoDigit(secondStr);

    return hourStr + ":" + minuteStr + ":" + secondStr;
}

// Rolls over initialSecond and updates initialHour by incrementing the minute through a function call to addMinute().
// @param int& initialHours - pass by reference for mutating the user input value of initialHour
// @param int& initialMinute - pass by reference for mutating the user input value of initialMinute
// @param int& initialSecond - pass by reference for mutating the user input value of initialSecond
// @returns - initialSecond, either passed through unchanged or set to 0 if passed through the if statement.
int rolloverSeconds(int& initialHour, int& initialMinute, int& initialSecond) {
    
    if (initialSecond > 59) {
        int range = (initialSecond / 60);
        for (int i = 0; i < range; ++i) {
            addMinute(initialHour, initialMinute);
        }
        return initialSecond = 0; // Ensure seconds stay within the range 0-59
    }
    return initialSecond;
}

// Rolls over minutes and updates initialHour by incrementing the hour through a function call to addHour().
// @param int& initialHour - pass by reference for mutating the user input value of initialHour
// @param int& InitialMinute - pass by reference for mutating the user input value of initialMinute
// @returns - initialMinute, either passed through unchanged or set to 0 if passed through the if statement.
int rolloverMinutes(int& initialHour, int& initialMinute) {
    
    if (initialMinute > 59) {
        int range = (initialMinute / 60);
        for (int i = 0; i < range; ++i) {
            addHour(initialHour);
        }
        return initialMinute = 0; // Ensure minutes stay within the range 0-59
    }
    return initialMinute;
}

