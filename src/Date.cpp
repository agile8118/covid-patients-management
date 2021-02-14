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
    if (checkYear(y))
        year = y;

    if (checkMonth(m))
        month = m;

    if (checkDay(d))
        day = d;

    if (checkHour(h))
        hour = h;

    if (checkMinute(min))
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

    if (!regex_match(dateString, std::regex("(\\d)+(\\W)+\\ ?(\\d)+(\\W)+\\ ?(\\d)+(\\W)+\\ ?(\\d)+(\\W)+\\ ?(\\d)+")))
        throw std::invalid_argument("Invalid date. Make sure to specify the date in the proper format (year, month, day, hour, minute). Received '" + dateString + "'.");

    std::string year;
    std::string month;
    std::string day;
    std::string hour;
    std::string min;

    std::replace(dateString.begin(), dateString.end(), ',', ' ');
    std::replace(dateString.begin(), dateString.end(), '.', ' ');
    std::replace(dateString.begin(), dateString.end(), '-', ' ');
    std::replace(dateString.begin(), dateString.end(), '_', ' ');
    std::replace(dateString.begin(), dateString.end(), ':', ' ');
    std::istringstream linestream(dateString);

    linestream >> year >> month >> day >> hour >> min;

    if (checkYear(std::stoi(year)))
        this->year = std::stoi(year);
    if (checkMonth(std::stoi(month)))
        this->month = std::stoi(month);
    if (checkDay(std::stoi(day)))
        this->day = std::stoi(day);
    if (checkHour(std::stoi(hour)))
        this->hour = std::stoi(hour);
    if (checkMinute(std::stoi(min)))
        this->minute = std::stoi(min);
}

bool Date::hasValue() const
{
    if (this->year == 0)
        return false;
    return true;
}

/********************************/
/** Validators */
/********************************/
bool Date::checkYear(int y) const
{
    if (y > 1970 && y < 2050)
        return true;
    else
        throw std::invalid_argument("Invalid year. Year must be between 1970-2050, received '" + std::to_string(y) + "'.");
}

bool Date::checkMonth(int m) const
{
    if (m > 0 && m <= 12)
        return true;
    else
        throw std::invalid_argument("Invalid month. Month must be between 1-12, received '" + std::to_string(m) + "'.");
}

bool Date::checkDay(int d) const
{
    if (d > 0 && d <= 31)
        return true;
    else
        throw std::invalid_argument("Invalid day. Day must be between 1-31, received '" + std::to_string(d) + "'.");
}

bool Date::checkHour(int h) const
{
    if (h >= 0 && h <= 24)
        return true;
    else
        throw std::invalid_argument("Invalid hour. Hour must be between 1-24, received '" + std::to_string(h) + "'.");
}

bool Date::checkMinute(int m) const
{
    if (m >= 0 && m <= 60)
        return true;
    else
        throw std::invalid_argument("Invalid minute. Minute must be between 1-60, received '" + std::to_string(m) + "'.");
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

/********************************/
/** Operator overloaders */
/********************************/
bool Date::operator>(const Date &other) const
{
    if (*this < other)
        return false;
    else
        return true;
}

// Calculate how many days is the difference between 2 days (expects all months to be 30 days)
int Date::operator-(const Date &other) const
{
    Date greaterDate = (*this > other) ? *this : other;
    Date smallerDate = (*this > other) ? other : *this;

    int yearD;
    int monthD;
    int dayD;

    yearD = greaterDate.year - smallerDate.year;
    if (yearD > 0)
    {
        // If the 2 dates does not have the same year...
        monthD = (12 - smallerDate.month) + greaterDate.month - 1;
        dayD = (30 - smallerDate.day) + greaterDate.day;
    }
    else
    {
        // If the 2 dates have the same year...
        monthD = greaterDate.month - smallerDate.month - 1;
        if (monthD < 0)
        {
            monthD = 0;
            dayD = greaterDate.day - smallerDate.day;
        }
        else
        {
            dayD = (30 - smallerDate.day) + greaterDate.day;
        }
    }

    if (yearD > 0)
        yearD = yearD - 1;

    return (yearD * 365 + monthD * 30 + dayD);
}
