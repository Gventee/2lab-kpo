#include "stdafx.h"
#include "YearUtils.h"
#include "DateUtils.h"
#include "ValidDate.h"
#include "MonthUtils.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string dateString;
    int day, month, year;

    cout << "Введите дату в формате ДДММГГГГ: ";
    cin >> dateString;
    if (!parseDate(dateString, day, month, year)) {
        cerr << "Ошибка: Неверный формат даты или недопустимая дата.\n";
        return 1;
    }

    cout << "Месяц: " <<getMonthName(month) << "\n";

    if (YearUtils::isLeapYear(year)) {
        cout << year << " год является високосным.\n";
    }
    else {
        cout << year << " год не является високосным.\n";
    }

    int dayNumber = DateUtils::dayOfYear(day, month, year);
    cout << "Порядковый номер дня в году: " << dayNumber << "\n";

    int resultDay, resultMonth;
   getDateFromDayNumber(dayNumber, year, resultDay, resultMonth);
    cout << "Дата по порядковому номеру дня: " << resultDay << " " << getMonthName(month) << " " << year << "\n";

    cout << "Введите дату (ДД ММ): " << endl;
    int birthdayDay, birthdayMonth;
    while (!(cin >> birthdayDay >> birthdayMonth) || !isValidDate(birthdayDay, birthdayMonth)) {
        cout << "Ошибка! Введите корректную дату (ДД ММ): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    int daysUntil = DateUtils::daysUntilBirthday(day, month, year, birthdayDay, birthdayMonth);
    cout << "Дней до ближайшего дня рождения: " << daysUntil << "\n";

    int eventDayNumber;
    cout << "Введите порядковый номер дня года для события (например, 256 для Дня программиста): ";
    cin >> eventDayNumber;

    int eventDay, eventMonth;
    getEventDate(eventDayNumber, year, eventDay, eventMonth);
    cout << "Дата события: " << eventDay << " " << getMonthName(eventMonth) << " " << year << "\n";


    return 0;
}
