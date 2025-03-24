#include "MonthUtils.h"
#include "YearUtils.h"  // Для проверки високосного года
#include <iostream>

using namespace std;

// Реализация функции для получения названия месяца по его порядковому номеру
string getMonthName(int month) {
    const string months[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    if (month < 1 || month > 12) {
        return "Неверный номер месяца";
    }
    return months[month-1];
}

// Реализация функции для получения даты по порядковому номеру дня в году
void getDateFromDayNumber(int dayNumber, int year, int& day, int& month) {
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int daysInYear = YearUtils::isLeapYear(year) ? 366 : 365;

    if (dayNumber < 1 || dayNumber > daysInYear) {
        cerr << "Неверный порядковый номер дня.\n";
        return;
    }

    int daysPassed = 0;
    for (month = 0; month < 12; ++month) {
        int daysThisMonth = daysInMonth[month];
        if (month == 1 && YearUtils::isLeapYear(year)) {
            daysThisMonth = 29; // Февраль в високосный год
        }
        if (dayNumber <= daysPassed + daysThisMonth) {
            day = dayNumber - daysPassed;
            break;
        }
        daysPassed += daysThisMonth;
    }
}

// Функция для вычисления даты события по порядковому номеру дня
void getEventDate(int eventDayNumber, int year, int& day, int& month) {
    // Проверим для разных известных событий
    if (eventDayNumber == 256) {
        // День программиста: 256-й день года
        getDateFromDayNumber(256, year, day, month);
    }
    else if (eventDayNumber == 1) {
        // Первый день лета: 152-й или 153-й день
        int firstDayOfSummer = YearUtils::isLeapYear(year) ? 153 : 152;
        getDateFromDayNumber(firstDayOfSummer, year, day, month);
    }
    else {
        getDateFromDayNumber(eventDayNumber, year, day, month);
    }
}
