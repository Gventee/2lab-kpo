#include "stdafx.h"
#include "ValidDate.h"
#include "YearUtils.h" 

using namespace std;

bool parseDate(const string& dateStr, int& day, int& month, int& year) {
    if (dateStr.length() != 8) {
        return false;
    }

    try {
        day = stoi(dateStr.substr(0, 2));
        month = stoi(dateStr.substr(2, 2));
        year = stoi(dateStr.substr(4, 4));
    }
    catch (const invalid_argument&) {
        return false;
    }
    catch (const out_of_range&) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > YearUtils::daysInMonth(month, year)) {
        return false;
    }

    return true;
}
bool isValidDate(int day, int month) {
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (day >= 1 && day <= daysInMonth[month - 1]);
}


