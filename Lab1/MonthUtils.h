#ifndef MONTH_UTILS_H
#define MONTH_UTILS_H

#include <string>
using namespace std;

// Функция для получения названия месяца по его порядковому номеру
string getMonthName(int month);

// Функция для получения даты по порядковому номеру дня в году
void getDateFromDayNumber(int dayNumber, int year, int& day, int& month);

// Функция для вычисления даты для события с заданным порядковым номером дня
void getEventDate(int eventDayNumber, int year, int& day, int& month);

#endif 
