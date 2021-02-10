#include <iostream>
#include <vector>
#include "Date.h"
#include "Patient.h"

/** The hospital capacity is 100 patients */

/**
 A patient's records includes:
    - Social Security Number
    - First Name
    - Last Name
    - Age
    - Gender
    - Admission Date
    - Discharged Date (for recoverd patients)
    - Death Date (for the deceased)
    - Has Underlying Health Problems
 */

//
//void edit_patience_records(string ssn) {
//
//}
//
//void delete_patience(string ssn) {
//
//}
//
//void display_hospitalized_patiences_records() {
//
//}
//
//int number_of_deaths() {
//
//}
//
//void display_deceased_patients_records() {
//
//}
//
//void display_discharged_patients_records() {
//
//}
//
//int number_of_discharged_patients() {
//
//}
//
//void display_patient_records(string ssn) {
//
//}
//
//void display_patients_by_hospitalization_date() {
//
//}
//
//void percentage_of_dead(int age, bool underlying_health_problems) {
//
//}
//
//void men_to_women_patients_ratio() {
//
//}
//

void add_new_patience(std::vector<Patient> &patients)
{
    //    std::string ssn;
    //    std::string firstName;
    //    std::string lastName;
    //    int age;
    //    bool hasUnderlyingHealthProblems;
    //    Gender gender;
    Date admissionDate;
    //    Date dischargedDate;
    //    Date deathDate;
    //
    //
    //    std::string hasUnderlyingHealthProblemsString;
    //    std::string genderString;
    std::string admissionDateString;

    //    std::string dischargedDateString;
    //    std::string deathDateString;
    //
    //    std::cout << "Adding a new patient..." << std::endl;
    //
    //    std::cout << "Enter social security number:" << std::endl;
    //    std::cin >> ssn;
    //
    //    std::cout << "Enter first name:" << std::endl;
    //    std::cin >> firstName;
    //
    //    std::cout << "Enter last name:" << std::endl;
    //    std::cin >> lastName;
    //
    //    std::cout << "Enter age:" << std::endl;
    //    std::cin >> age;
    //
    //    std::cout << "Does the patient have underlying health issues? (yes/no):" << std::endl;
    //    std::cin >> hasUnderlyingHealthProblemsString;
    //    if (hasUnderlyingHealthProblemsString == "yes") {
    //        hasUnderlyingHealthProblems = true;
    //    } else {
    //        hasUnderlyingHealthProblems = false;
    //    }
    //
    //    std::cout << "Enter Gender (F/M):" << std::endl;
    //    std::cin >> genderString;
    //    if (genderString == "F") {
    //        gender = Female;
    //    } else {
    //        gender = Male;
    //    }

    std::cout << "Enter admission date (year, month, day, hour, minute):" << std::endl;
    getline(std::cin, admissionDateString);
    admissionDate.insert(admissionDateString);

    //    std::cout << "Enter discharged date (year, month, day, hour, minute):" << std::endl;
    //    std:: cin >> dischargedDateString;
    //    dischargedDate.insert(dischargedDate);
    //
    //    std::cout << "Enter death date (year, month, day, hour, minute):" << std::endl;
    //    std::cin >> deathDateString;
    //    deathDate.insert(deathDateString);

    //    Patient p(ssn, firstName, lastName, age, hasUnderlyingHealthProblems, gender, admissionDate, dischargedDate, deathDate);

    //    patients.push_back(p);
}

int main()
{
    std::vector<Patient> patients;

    add_new_patience(patients);

    // Date date(2020, 12, 18, 19, 59);
    // std::cout << date.getDate() << std::endl;

    return 0;
}
