#ifndef Date_h
#define Date_h
#include <iostream>
#include <sstream>

class Date
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    std::string getMonthName(int m) const;
    std::string getFormattedMin(int m) const;
    std::string getFormattedHour(int h) const;

public:
    Date();
    Date(int y, int m, int d, int h, int min);
    void insert(std::string dateString);
    std::string getDate() const;
    bool hasValue() const;
};

#endif /* Date_h */
