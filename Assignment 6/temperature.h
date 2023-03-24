#pragma once
#include "std_lib_facilities.h"

struct Temps {
    double max;
    double min;
};

istream &operator>>(istream &is, Temps &t);
vector<Temps> readTemps(filesystem::path path);
void tempStats(vector<Temps> tempVector);
double roundDouble(double number, int precision);   // Ikke i bruk