#include "Date.h"

std::string Date::getMonthName(int m) const
{
    switch (m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Not Valid";
    }
}

std::string Date::getFormattedMin(int m) const
{
    if (m < 10)
    {
        return "0" + std::to_string(m);
    }
    else
    {
        return std::to_string(m);
    }
}

std::string Date::getFormattedHour(int h) const
{
    if (h < 10)
    {
        return "0" + std::to_string(h);
    }
    else
    {
        return std::to_string(h);
    }
}

Date::Date(int y, int m, int d, int h, int min)
{
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min;
}

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    minute = 0;
}

std::string Date::getDate() const
{
    return getMonthName(month) + " " + std::to_string(day) + ", " + std::to_string(year) + " " + getFormattedHour(hour) + ":" + getFormattedMin(minute);
}

// Convert a date string to a Date object
void Date::insert(std::string dateString)
{
    std::string year;
    std::string month;
    std::string day;
    std::string hour;
    std::string min;

    std::replace(dateString.begin(), dateString.end(), ',', ' ');
    std::istringstream linestream(dateString);

    linestream >> year >> month >> day >> hour >> min;

    this->year = std::stoi(year);
    this->month = std::stoi(month);
    this->day = std::stoi(day);
    this->hour = std::stoi(hour);
    this->minute = std::stoi(min);
}

bool Date::hasValue() const
{
    if (this->year == 0)
        return false;
    return true;
}

bool Date::operator<(const Date &other) const
{
    if (year < other.year)
    {
        return true;
    }
    else if (year > other.year)
    {
        return false;
    }
    else if (year == other.year)
    {
        if (month < other.month)
        {
            return true;
        }
        else if (month > other.month)
        {
            return false;
        }
        else if (month == other.month)
        {
            if (day < other.day)
            {
                return true;
            }
            else if (day > other.day)
            {
                return false;
            }
            else if (day == other.day)
            {
                if (hour < other.hour)
                {
                    return true;
                }
                else if (hour > other.hour)
                {
                    return false;
                }
                else if (hour == other.hour)
                {
                    if (minute < other.minute)
                    {
                        return true;
                    }
                    else if (minute > other.minute)
                    {
                        return false;
                    }
                    else if (minute == other.minute)
                        return false;
                }
            }
        }
    }
    return false;
}
