#include "stdafx.h"
#include "DateUtils.h"
#include "YearUtils.h" 

namespace DateUtils {
   
    int dayOfYear(int day, int month, int year) {
        int dayNumber = 0;
        for (int i = 1; i < month; ++i) {
            dayNumber += YearUtils::daysInMonth(i, year);
        }
        dayNumber += day;
        return dayNumber;
    }

    int daysUntilBirthday(int currentDay, int currentMonth, int currentYear,
        int birthdayDay, int birthdayMonth) {
        int currentDayOfYear = DateUtils::dayOfYear(currentDay, currentMonth, currentYear);
        int birthdayDayOfYear = DateUtils::dayOfYear(birthdayDay, birthdayMonth, currentYear);

        if (birthdayDayOfYear > currentDayOfYear) {
            return birthdayDayOfYear - currentDayOfYear;
        }
        else if (birthdayDayOfYear == currentDayOfYear) {
            return 0; 
        }
        else {
            int daysInCurrentYear = YearUtils::isLeapYear(currentYear) ? 366 : 365;
            return (daysInCurrentYear - currentDayOfYear) + DateUtils::dayOfYear(birthdayDay, birthdayMonth, currentYear + 1);
        }
    }

}
