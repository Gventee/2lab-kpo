#pragma once
#ifndef DATEUTILS_H
#define DATEUTILS_H

namespace DateUtils {

    // Функция для вычисления порядкового номера дня в году
    int dayOfYear(int day, int month, int year);

    // Функция для вычисления количества дней до ближайшего дня рождения
    int daysUntilBirthday(int currentDay, int currentMonth, int currentYear,
        int birthdayDay, int birthdayMonth);
}

#endif
