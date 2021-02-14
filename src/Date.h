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

    // Validators
    bool checkYear(int y) const;
    bool checkMonth(int m) const;
    bool checkDay(int d) const;
    bool checkHour(int h) const;
    bool checkMinute(int m) const;

public:
    Date();
    Date(int y, int m, int d, int h, int min);
    void insert(std::string dateString);
    std::string getDate() const;
    bool hasValue() const;

    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    int operator-(const Date &other) const; // returns the difference between 2 times in days (expects all months to be 30 days)
};

#endif /* Date_h */
