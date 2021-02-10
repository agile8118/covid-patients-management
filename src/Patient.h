#ifndef Patient_hpp
#define Patient_hpp

#include <iostream>
#include "Date.h"

enum Gender
{
    Female = 0,
    Male
};

class Patient
{
private:
    std::string ssn;
    std::string firstName;
    std::string lastName;
    int age;
    bool has_underlying_health_problems;
    Gender gender;
    Date admissionDate;
    Date dischargedDate;
    Date deathDate;

public:
    Patient();
    Patient(std::string ssn, std::string firstName, std::string lastName, int age, bool has_underlying_health_problems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate);
};

#endif /* Patient_hpp */
