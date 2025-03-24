#ifndef VALIDDATE_H
#define VALIDDATE_H

#include <string>

bool parseDate(const std::string& dateStr, int& day, int& month, int& year);

bool isValidDate(int day, int month);
#endif

#pragma once
