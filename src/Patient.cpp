#include "Patient.h"

Patient::Patient(std::string ssn, std::string firstName, std::string lastName, int age, bool has_underlying_health_problems, Gender gender, Date admisionDate, Date dischargedDate, Date deathDate)
{

    this->ssn = ssn;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->has_underlying_health_problems = has_underlying_health_problems;
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
    this->has_underlying_health_problems = false;
    this->gender = Female;
    this->admissionDate = Date();
    this->dischargedDate = Date();
    this->deathDate = Date();
}
