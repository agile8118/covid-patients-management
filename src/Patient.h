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
    bool hasUnderlyingHealthProblems;
    Gender gender;
    Date admissionDate;
    Date dischargedDate;
    Date deathDate;

public:
    Patient();
    Patient(std::string ssn, std::string firstName, std::string lastName, int age, bool hasUnderlyingHealthProblems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate);

    bool hasDischarged() const;
    bool hasPassedAway() const;

    // Getters
    std::string getSSN() const;
    std::string getFirstName() const;
    std::string getLastLast() const;
    int getAge() const;
    bool getHasUnderlyingHealthProblems() const;
    std::string getGender() const;
    std::string getAdmissionDate() const;
    std::string getDischargedDate() const;
    std::string getDeathDate() const;
};

#endif /* Patient_hpp */
