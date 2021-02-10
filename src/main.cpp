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
void display_patient_records(std::string ssn, const std::vector<Patient> *patients)
{
    for (const Patient &patient : *patients)
    {
        if (patient.getSSN() == ssn)
        {
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Information of patient with the SSN number of " + patient.getSSN() << std::endl;
            std::cout << "First Name: " + patient.getFirstName() << std::endl;
            std::cout << "Last Name: " + patient.getLastLast() << std::endl;
            std::cout << "Age: " + std::to_string(patient.getAge()) << std::endl;

            std::string hasUnderlyingHealthProblems = patient.getHasUnderlyingHealthProblems() ? "Yes" : "No";
            std::cout << "Has underlying health problems: " + hasUnderlyingHealthProblems << std::endl;

            std::cout << "Gender: " + patient.getGender() << std::endl;
            std::cout << "Admission Date: " + patient.getAdmissionDate() << std::endl;
            if (patient.hasDischarged())
            {
                std::cout << "Discharged Date: " + patient.getDischargedDate() << std::endl;
            }

            if (patient.hasPassedAway())
            {
                std::cout << "Death Date: " + patient.getDeathDate() << std::endl;
            }
            std::cout << "--------------------------------" << std::endl;
        }
    }
}
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

void add_new_patience(std::vector<Patient> *patients)
{
    std::string ssn;
    std::string firstName;
    std::string lastName;
    int age;
    bool hasUnderlyingHealthProblems;
    Gender gender;
    Date admissionDate;
    Date dischargedDate;
    Date deathDate;

    // These values will be used to store whatever user specifies in the terminal
    std::string hasUnderlyingHealthProblemsString;
    std::string genderString;
    std::string admissionDateString;
    std::string dischargedDateString;
    std::string deathDateString;
    std::string hasDischargedString;
    std::string hasPassedAwayString;

    std::cout << "Enter social security number: ";
    std::cin >> ssn;

    std::cout << "Enter first name: ";
    std::cin >> firstName;

    std::cout << "Enter last name: ";
    std::cin >> lastName;

    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << "Does the patient have underlying health issues? (yes/no): ";
    std::cin >> hasUnderlyingHealthProblemsString;

    if (hasUnderlyingHealthProblemsString == "yes")
    {
        hasUnderlyingHealthProblems = true;
    }
    else
    {
        hasUnderlyingHealthProblems = false;
    }

    std::cout << "Enter Gender (F/M): ";
    std::cin >> genderString;

    if (genderString == "F" || genderString == "f")
    {
        gender = Female;
    }
    else
    {
        gender = Male;
    }

    std::cout << "Enter admission date (year, month, day, hour, minute): ";
    std::cin.ignore();
    getline(std::cin, admissionDateString);
    admissionDate.insert(admissionDateString);

    std::cout << "Has the patient discharged? (yes/no): ";
    std::cin >> hasDischargedString;
    if (hasDischargedString == "yes" || hasDischargedString == "y")
    {
        std::cout << "Enter discharged date (year, month, day, hour, minute): ";
        std::cin.ignore();
        getline(std::cin, dischargedDateString);
        dischargedDate.insert(dischargedDateString);
    }

    std::cout << "Has the patient passed away? (yes/no): ";
    std::cin >> hasPassedAwayString;
    if (hasPassedAwayString == "yes" || hasPassedAwayString == "y")
    {
        std::cout << "Enter death date (year, month, day, hour, minute): ";
        std::cin.ignore();
        getline(std::cin, deathDateString);
        deathDate.insert(deathDateString);
    }

    Patient p(ssn, firstName, lastName, age, hasUnderlyingHealthProblems, gender, admissionDate, dischargedDate, deathDate);

    (*patients).push_back(p);
}

int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "  Welcome to the COVID patients management app  " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::vector<Patient> patients;

    bool exit = false;
    while (!exit)
    {
        int option;
        std::string ssn;

        std::cout << "Menu:" << std::endl;
        std::cout << " [1] Add a new patient" << std::endl;
        std::cout << " [2] Show a patient's records" << std::endl;
        std::cout << " [3] Edit a patient's records" << std::endl;
        std::cout << " [4] Delete a patient's records" << std::endl;
        std::cout << " [5] Show all patients' records currently in hospitalization " << std::endl;
        std::cout << " [6] Show all patients' records who have passed away " << std::endl;
        std::cout << " [7] Show all patients' records who have discharged " << std::endl;
        std::cout << " [8] Show all patients' records ordered by hospitalization duration" << std::endl;
        std::cout << " [9] Percentage of dead patients who had underlying health problems and were over 70" << std::endl;
        std::cout << "[10] Male to female deaths ratio" << std::endl;
        std::cout << "[11] Exit" << std::endl;

        std::cout << "Please choose an option: ";
        if (!(std::cin >> option))
        {
            std::cout << std::endl;
            std::cout << "Bad input specified. Quiting..." << std::endl;
            std::cout << std::endl;
            break;
        }

        switch (option)
        {
        case 1:
            std::cout << "---Adding a new patient---" << std::endl;
            add_new_patience(&patients);
            break;
        case 2:
            std::cout << "---Showing a patient's records---" << std::endl;
            std::cout << "Enter the patient's SSN: ";
            std::cin >> ssn;
            display_patient_records(ssn, &patients);
            break;
        case 11:
            std::cout << "Exiting out of the application..." << std::endl;
            exit = true;
            break;
        default:
            std::cout << std::endl;
            std::cout << "---No valid option was choosen. Please try again.---" << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    return 0;
}
