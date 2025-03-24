#include "MonthUtils.h"
#include "YearUtils.h"  // ��� �������� ����������� ����
#include <iostream>

using namespace std;

// ���������� ������� ��� ��������� �������� ������ �� ��� ����������� ������
string getMonthName(int month) {
    const string months[] = {
        "������", "�������", "����", "������", "���", "����",
        "����", "������", "��������", "�������", "������", "�������"
    };

    if (month < 1 || month > 12) {
        return "�������� ����� ������";
    }
    return months[month-1];
}

// ���������� ������� ��� ��������� ���� �� ����������� ������ ��� � ����
void getDateFromDayNumber(int dayNumber, int year, int& day, int& month) {
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int daysInYear = YearUtils::isLeapYear(year) ? 366 : 365;

    if (dayNumber < 1 || dayNumber > daysInYear) {
        cerr << "�������� ���������� ����� ���.\n";
        return;
    }

    int daysPassed = 0;
    for (month = 0; month < 12; ++month) {
        int daysThisMonth = daysInMonth[month];
        if (month == 1 && YearUtils::isLeapYear(year)) {
            daysThisMonth = 29; // ������� � ���������� ���
        }
        if (dayNumber <= daysPassed + daysThisMonth) {
            day = dayNumber - daysPassed;
            break;
        }
        daysPassed += daysThisMonth;
    }
}

// ������� ��� ���������� ���� ������� �� ����������� ������ ���
void getEventDate(int eventDayNumber, int year, int& day, int& month) {
    // �������� ��� ������ ��������� �������
    if (eventDayNumber == 256) {
        // ���� ������������: 256-� ���� ����
        getDateFromDayNumber(256, year, day, month);
    }
    else if (eventDayNumber == 1) {
        // ������ ���� ����: 152-� ��� 153-� ����
        int firstDayOfSummer = YearUtils::isLeapYear(year) ? 153 : 152;
        getDateFromDayNumber(firstDayOfSummer, year, day, month);
    }
    else {
        getDateFromDayNumber(eventDayNumber, year, day, month);
    }
}
