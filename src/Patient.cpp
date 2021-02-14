#include "Patient.h"

Patient::Patient(std::string ssn, std::string firstName, std::string lastName, int age, bool hasUnderlyingHealthProblems, Gender gender, Date admissionDate, Date dischargedDate, Date deathDate)
{

    this->ssn = ssn;
    this->firstName = firstName;
    this->lastName = lastName;
    if (checkAge(age))
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

int Patient::hospitalizationDuration(Date currentDate) const
{
    if (this->hasPassedAway())
    {
        return this->getDeathDate() - this->getAdmissionDate();
    }
    else if (this->hasDischarged())
    {
        return this->getDischargedDate() - this->getAdmissionDate();
    }
    else
    {
        return currentDate - this->getAdmissionDate();
    }
}

bool Patient::checkAge(int age) const
{
    if (age > 0 && age < 200)
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Invalid age. Age must be between 1-200, received '" + std::to_string(age) + "'");
    }
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
    if (checkAge(age))
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
    if (admissionDate.hasValue())
    {
        this->admissionDate = admissionDate;
    }
}

void Patient::setDischargedDate(Date dischargedDate)
{
    if (dischargedDate.hasValue() && dischargedDate < admissionDate)
        throw std::invalid_argument("Invalid discharged date. Discharged date must be older than the admission date. Received '" + dischargedDate.getDate() + "'");

    // A patinet can't be both dead and discharged
    if (hasPassedAway())
        setDeathDate(Date());

    this->dischargedDate = dischargedDate;
}

void Patient::setDeathDate(Date deathDate)
{
    if (dischargedDate.hasValue() && deathDate < admissionDate)
        throw std::invalid_argument("Invalid death date. Death date must be older than the admission date. Received '" + deathDate.getDate() + "'");

    // A patinet can't be both dead and discharged
    if (hasDischarged())
        setDischargedDate(Date());

    this->deathDate = deathDate;
}
