#pragma once
#ifndef DATEUTILS_H
#define DATEUTILS_H

namespace DateUtils {

    // ������� ��� ���������� ����������� ������ ��� � ����
    int dayOfYear(int day, int month, int year);

    // ������� ��� ���������� ���������� ���� �� ���������� ��� ��������
    int daysUntilBirthday(int currentDay, int currentMonth, int currentYear,
        int birthdayDay, int birthdayMonth);
}

#endif
