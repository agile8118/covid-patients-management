#ifndef Patient_h
#define Patient_h

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

    void update(std::string firstName, std::string lastName, int age, bool hasUnderlyingHealthProblems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate);

    bool hasDischarged() const;
    bool hasPassedAway() const;

    // Getters
    std::string getSSN() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    bool getHasUnderlyingHealthProblems() const;
    Gender getGender() const;
    Date getAdmissionDate() const;
    Date getDischargedDate() const;
    Date getDeathDate() const;

    // Setters
    void setSSN(std::string ssn);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setAge(int age);
    void setHasUnderlyingHealthProblems(bool hasUnderlyingHealthProblems);
    void setGender(Gender gender);
    void setAdmissionDate(Date admissionDate);
    void setDischargedDate(Date dischargedDate);
    void setDeathDate(Date deathDate);
};

#endif /* Patient_h */
