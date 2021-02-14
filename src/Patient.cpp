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

void Patient::update(std::string firstName, std::string lastName, int age, bool hasUnderlyingHealthProblems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate)
{
    setFirstName(firstName);
    setLastName(lastName);
    setAge(age);
    setHasUnderlyingHealthProblems(hasUnderlyingHealthProblems);
    setGender(gender);
    setAdmissionDate(admissionDate);
    setDischargedDate(dischargedDate);
    setDeathDate(deathDate);
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

// Getters
std::string Patient::getSSN() const
{
    return this->ssn;
}

std::string Patient::getFirstName() const
{
    return this->firstName;
}

std::string Patient::getLastName() const
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

Gender Patient::getGender() const
{
    return this->gender;
}

Date Patient::getAdmissionDate() const
{
    return this->admissionDate;
}

Date Patient::getDischargedDate() const
{
    return this->dischargedDate;
}

Date Patient::getDeathDate() const
{
    return this->deathDate;
}

// Setters
void Patient::setSSN(std::string ssn)
{
    this->ssn = ssn;
}

void Patient::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Patient::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Patient::setAge(int age)
{
    this->age = age;
}

void Patient::setHasUnderlyingHealthProblems(bool hasUnderlyingHealthProblems)
{
    this->hasUnderlyingHealthProblems = hasUnderlyingHealthProblems;
}

void Patient::setGender(Gender gender)
{
    this->gender = gender;
}

void Patient::setAdmissionDate(Date admissionDate)
{
    this->admissionDate = admissionDate;
}

void Patient::setDischargedDate(Date dischargedDate)
{
    this->dischargedDate = dischargedDate;
}

void Patient::setDeathDate(Date deathDate)
{
    this->deathDate = deathDate;
}
