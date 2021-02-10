#include "Patient.h"

Patient::Patient(std::string ssn, std::string firstName, std::string lastName, int age, bool hasUnderlyingHealthProblems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate)
{

    this->ssn = ssn;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->hasUnderlyingHealthProblems = hasUnderlyingHealthProblems;
    this->gender = gender;
    this->admissionDate = admissionDate;
    this->dischargedDate = dischargedDate;
    this->deathDate = deathDate;
}

Patient::Patient()
{
    this->ssn = "0000000000";
    this->firstName = "Not Set";
    this->lastName = "Not Set";
    this->age = 0;
    this->hasUnderlyingHealthProblems = false;
    this->gender = Female;
    this->admissionDate = Date();
    this->dischargedDate = Date();
    this->deathDate = Date();
}

bool Patient::hasDischarged() const
{
    if (this->dischargedDate.hasValue())
        return true;
    return false;
}

bool Patient::hasPassedAway() const
{
    if (this->deathDate.hasValue())
        return true;
    return false;
}

std::string Patient::getSSN() const
{
    return this->ssn;
}

std::string Patient::getFirstName() const
{
    return this->firstName;
}

std::string Patient::getLastLast() const
{
    return this->lastName;
}

int Patient::getAge() const
{
    return this->age;
}

bool Patient::getHasUnderlyingHealthProblems() const
{
    return this->hasUnderlyingHealthProblems;
}

std::string Patient::getGender() const
{
    if (this->gender == Female)
    {
        return "Female";
    }
    else
    {
        return "Male";
    }
}

std::string Patient::getAdmissionDate() const
{
    return this->admissionDate.getDate();
}

std::string Patient::getDischargedDate() const
{
    return this->dischargedDate.getDate();
}

std::string Patient::getDeathDate() const
{
    return this->deathDate.getDate();
}
