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

int number_of_deaths(const std::vector<Patient> *patients)
{
    int i = 0;
    for (const Patient &patient : *patients)
    {
        if (patient.hasPassedAway())
        {
            ++i;
        }
    }

    return i;
}

// int number_of_discharged_patients(const std::vector<Patient> *patients)
// {
// }

int number_of_hospitalized_patients(const std::vector<Patient> *patients)
{
    int i = 0;
    for (const Patient &patient : *patients)
    {
        if (!patient.hasPassedAway() && !patient.hasDischarged())
        {
            ++i;
        }
    }

    return i;
}

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
    hasUnderlyingHealthProblems = hasUnderlyingHealthProblemsString == "yes" ? true : false;

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

void display_patient_records(Patient patient)
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Information of patient with the SSN number of " + patient.getSSN() << std::endl;
    std::cout << "First Name: " + patient.getFirstName() << std::endl;
    std::cout << "Last Name: " + patient.getLastName() << std::endl;
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

void edit_patient_records(std::string ssn, std::vector<Patient> *patients)
{
    for (Patient &patient : *patients)
    {
        if (patient.getSSN() == ssn)
        {
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

            std::cout << "(For each field either specify a new info or hit enter to skip.)" << std::endl;

            std::cout << "New first name "
                      << "[" << patient.getFirstName() << "]: ";
            std::cin >> firstName;

            std::cout << "New last name "
                      << "[" << patient.getLastName() << "]: ";
            std::cin >> lastName;

            std::cout << "New age "
                      << "[" << std::to_string(patient.getAge()) << "]: ";
            std::cin >> age;

            std::cout << "Underlying health issues [" << (patient.getHasUnderlyingHealthProblems() ? "yes" : "no")
                      << "] (yes/no): ";
            std::cin >> hasUnderlyingHealthProblemsString;
            hasUnderlyingHealthProblems = hasUnderlyingHealthProblemsString == "yes" ? true : false;

            std::cout << "New Gender "
                      << "[" << patient.getGender() << "] (M/F): ";
            std::cin >> genderString;
            gender = (genderString == "F" || genderString == "f") ? Female : Male;

            std::cout << "New admission date "
                      << "[" << patient.getAdmissionDate() << "] (year, month, day, hour, minute): ";
            std::cin.ignore();
            getline(std::cin, admissionDateString);
            if (admissionDateString.length() > 0)
                admissionDate.insert(admissionDateString);

            std::cout << "Has the patient discharged [" << (patient.hasDischarged() ? ("Current discharged date is: " + patient.getDischargedDate()) : "no")
                      << "] (yes/no): ";

            std::cin >> hasDischargedString;
            if (hasDischargedString == "yes" || hasDischargedString == "y")
            {
                std::cout << "Enter discharged date (year, month, day, hour, minute): ";
                std::cin.ignore();
                getline(std::cin, dischargedDateString);
                dischargedDate.insert(dischargedDateString);
            }

            std::cout << "Has the patient passed away [" << (patient.hasPassedAway() ? ("Current death date is: " + patient.getDeathDate()) : "no")
                      << "] (yes/no): ";

            std::cin >> hasPassedAwayString;
            if (hasPassedAwayString == "yes" || hasPassedAwayString == "y")
            {
                std::cout << "Enter death date (year, month, day, hour, minute): ";
                std::cin.ignore();
                getline(std::cin, deathDateString);
                deathDate.insert(deathDateString);
            }

            patient.update(firstName, lastName, age, hasUnderlyingHealthProblems, gender, admissionDate, dischargedDate, deathDate);
        }
    }
}

void display_all_patients(const std::vector<Patient> *patients)
{
    for (const Patient &patient : *patients)
    {
        display_patient_records(patient);
    }
}

void delete_patient_records(std::string ssn, std::vector<Patient> *patients)
{
    for (int i = 0; i < patients->size(); ++i)
    {
        if (patients->operator[](i).getSSN() == ssn)
        {
            patients->erase(patients->begin() + i);
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Patient's records with SSN of " + patients->operator[](i).getSSN() + " was successfully removed." << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
    }
}

void display_hospitalized_patients_records(const std::vector<Patient> *patients)
{
    std::cout << "Currently we have " + std::to_string(number_of_hospitalized_patients(patients)) + " patient(s) in hospitalization." << std::endl;
    for (const Patient &patient : *patients)
    {
        if (!patient.hasPassedAway() && !patient.hasDischarged())
        {
            display_patient_records(patient);
        }
    }
}

void display_deceased_patients_records(const std::vector<Patient> *patients)
{
    std::cout << "As of now " + std::to_string(number_of_deaths(patients)) + " patient(s) have died." << std::endl;
    for (const Patient &patient : *patients)
    {
        if (patient.hasPassedAway())
        {
            display_patient_records(patient);
        }
    }
}

//
//void display_discharged_patients_records() {
//
//}
//

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

int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "  Welcome to the COVID patients management app  " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::vector<Patient> patients;

    Date admissionDate(2019, 12, 21, 4, 45);
    Date dischargedDate;
    Date deathDate(2020, 2, 24, 4, 45);
    Patient p("1234", "Patrick", "Jobs", 20, false, Male, admissionDate, dischargedDate, deathDate);
    patients.push_back(p);

    Date admissionDate1(2020, 11, 18, 4, 45);
    Date dischargedDate1(2020, 12, 21, 4, 45);
    Date deathDate1;
    Patient p1("652341", "Anthony", "Fiski", 32, true, Male, admissionDate1, dischargedDate1, deathDate1);
    patients.push_back(p1);

    Date admissionDate2(2020, 11, 18, 4, 45);
    Date dischargedDate2(2020, 12, 21, 4, 45);
    Date deathDate2;
    Patient p2("31324", "Meredith", "Brown", 28, false, Female, admissionDate2, dischargedDate2, deathDate2);
    patients.push_back(p2);

    Date admissionDate3(2020, 7, 1, 4, 45);
    Date dischargedDate3;
    Date deathDate3;
    Patient p3("621310", "Jay", "Dunphie", 56, true, Male, admissionDate3, dischargedDate3, deathDate3);
    patients.push_back(p3);

    Date admissionDate4(2021, 1, 18, 4, 45);
    Date dischargedDate4;
    Date deathDate4;
    Patient p4("012314", "Alex", "Pritchet", 25, true, Female, admissionDate4, dischargedDate4, deathDate4);
    patients.push_back(p4);

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
        std::cout << "[11] Show all patient's records" << std::endl;
        std::cout << "[12] Exit" << std::endl;

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
            for (Patient &patient : patients)
            {
                if (patient.getSSN() == ssn)
                {
                    display_patient_records(patient);
                }
            }
            break;
        case 3:
            std::cout << "---Editing a patient's records---" << std::endl;
            std::cout << "Enter the patient's SSN: ";
            std::cin >> ssn;
            edit_patient_records(ssn, &patients);
            break;
        case 4:
            std::cout << "---Deleteing a patient's records---" << std::endl;
            std::cout << "Enter the patient's SSN: ";
            std::cin >> ssn;
            delete_patient_records(ssn, &patients);
            break;
        case 5:
            std::cout << "---Showing all patients' records currently in hospitalization---" << std::endl;
            display_hospitalized_patients_records(&patients);
            break;
        case 6:
            std::cout << "---Showing all patients' records who have died---" << std::endl;
            display_deceased_patients_records(&patients);
            break;
        case 11:
            std::cout << "---Showing all patient's records---" << std::endl;
            display_all_patients(&patients);
            break;
        case 12:
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
