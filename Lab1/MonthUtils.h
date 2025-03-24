#ifndef MONTH_UTILS_H
#define MONTH_UTILS_H

#include <string>
using namespace std;

// ������� ��� ��������� �������� ������ �� ��� ����������� ������
string getMonthName(int month);

// ������� ��� ��������� ���� �� ����������� ������ ��� � ����
void getDateFromDayNumber(int dayNumber, int year, int& day, int& month);

// ������� ��� ���������� ���� ��� ������� � �������� ���������� ������� ���
void getEventDate(int eventDayNumber, int year, int& day, int& month);

#endif 
