#include <iostream>
#include <vector>
#include <cmath>

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

int number_of_discharged_patients(const std::vector<Patient> *patients)
{
    int i = 0;
    for (const Patient &patient : *patients)
    {
        if (patient.hasDischarged())
        {
            ++i;
        }
    }

    return i;
}

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
    std::cout << "Information of patient with the SSN of " + patient.getSSN() << std::endl;
    std::cout << "First Name: " + patient.getFirstName() << std::endl;
    std::cout << "Last Name: " + patient.getLastName() << std::endl;
    std::cout << "Age: " + std::to_string(patient.getAge()) << std::endl;

    std::string hasUnderlyingHealthProblems = patient.getHasUnderlyingHealthProblems() ? "Yes" : "No";
    std::cout << "Has underlying health problems: " + hasUnderlyingHealthProblems << std::endl;

    std::cout << "Gender: " << (patient.getGender() == Female ? "Female" : "Male") << std::endl;
    std::cout << "Admission Date: " + patient.getAdmissionDate().getDate() << std::endl;
    if (patient.hasDischarged())
    {
        std::cout << "Discharged Date: " + patient.getDischargedDate().getDate() << std::endl;
    }

    if (patient.hasPassedAway())
    {
        std::cout << "Death Date: " + patient.getDeathDate().getDate() << std::endl;
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
            std::string ageString;
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
            std::cin.ignore();
            getline(std::cin, firstName);

            std::cout << "New last name "
                      << "[" << patient.getLastName() << "]: ";
            getline(std::cin, lastName);

            std::cout << "New age "
                      << "[" << std::to_string(patient.getAge()) << "]: ";
            getline(std::cin, ageString);
            std::stringstream ageStr(ageString);
            ageStr >> age;

            std::cout << "Underlying health issues [" << (patient.getHasUnderlyingHealthProblems() ? "yes" : "no")
                      << "] (yes/no): ";
            getline(std::cin, hasUnderlyingHealthProblemsString);
            if (hasUnderlyingHealthProblemsString.length() > 0)
                hasUnderlyingHealthProblems = hasUnderlyingHealthProblemsString == "yes" ? true : false;
            else
                hasUnderlyingHealthProblems = patient.getHasUnderlyingHealthProblems();

            std::cout << "New Gender "
                      << "[" << (patient.getGender() == Female ? "Female" : "Male")
                      << "] (M/F): ";
            getline(std::cin, genderString);
            if (genderString.length() > 0)
                gender = (genderString == "F" || genderString == "f") ? Female : Male;
            else
                gender = patient.getGender();

            std::cout << "New admission date "
                      << "[" << patient.getAdmissionDate().getDate() << "] (year, month, day, hour, minute): ";
            getline(std::cin, admissionDateString);
            if (admissionDateString.length() > 0)
                admissionDate.insert(admissionDateString);

            std::cout << "Has the patient discharged [" << (patient.hasDischarged() ? ("Current discharged date is: " + patient.getDischargedDate().getDate()) : "no")
                      << "] (yes/no): ";
            getline(std::cin, hasDischargedString);

            if (hasDischargedString.length() > 0)
            {
                if (hasDischargedString == "yes" || hasDischargedString == "y")
                {
                    std::cout << "Enter discharged date (year, month, day, hour, minute): ";
                    std::cin.ignore();
                    getline(std::cin, dischargedDateString);
                    dischargedDate.insert(dischargedDateString);
                }
            }
            else
            {
                dischargedDate = patient.getDischargedDate();
            }

            std::cout << "Has the patient passed away [" << (patient.hasPassedAway() ? ("Current death date is: " + patient.getDeathDate().getDate()) : "no")
                      << "] (yes/no): ";
            getline(std::cin, hasPassedAwayString);

            if (hasPassedAwayString.length() > 0)
            {
                if (hasPassedAwayString == "yes" || hasPassedAwayString == "y")
                {
                    std::cout << "Enter death date (year, month, day, hour, minute): ";
                    getline(std::cin, deathDateString);
                    deathDate.insert(deathDateString);
                }
            }
            else
            {
                deathDate = patient.getDeathDate();
            }

            patient.update(firstName, lastName, age, hasUnderlyingHealthProblems, gender, admissionDate, dischargedDate, deathDate);

            std::cout << "---Patient's records updated successfully.---" << std::endl;
        }
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

void display_discharged_patients_records(const std::vector<Patient> *patients)
{
    std::cout << "As of now " + std::to_string(number_of_discharged_patients(patients)) + " patient(s) have discharged." << std::endl;
    for (const Patient &patient : *patients)
    {
        if (patient.hasDischarged())
        {
            display_patient_records(patient);
        }
    }
}

void display_all_patients(std::vector<Patient> *patients)
{
    // Sort the records first by the admission date
    std::sort(patients->begin(), patients->end(), [](const Patient &lhs, const Patient &rhs) {
        return lhs.getAdmissionDate() < rhs.getAdmissionDate();
    });

    for (const Patient &patient : *patients)
    {
        display_patient_records(patient);
    }
}

void display_percentage_of_dead(int over_age, bool underlying_health_problems, const std::vector<Patient> *patients)
{
    int count = 0;
    for (const Patient &patient : *patients)
    {

        if (patient.getHasUnderlyingHealthProblems() == underlying_health_problems && patient.getAge() > over_age && patient.hasPassedAway())
            ++count;
    }
    float percentage = (float(count) / float(number_of_deaths(patients))) * 100;

    // Determine how many characters to remove from the percentage value
    int toErase = percentage < 10 ? 1 : (percentage == 100 ? 3 : 2);

    std::cout << "--------------------------------" << std::endl;
    std::cout << std::to_string(percentage).erase(toErase) << "% of dead patients were over 70 and had underlying health problems." << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void display_men_to_women_patients_ratio(const std::vector<Patient> *patients)
{
    int menCount = 0;
    int womenCount = 0;

    for (const Patient &patient : *patients)
    {
        if (patient.getGender() == Female)
        {
            ++womenCount;
        }

        if (patient.getGender() == Male)
        {
            ++menCount;
        }
    }

    float percentage = (float(menCount) / float(womenCount + menCount)) * 100;
    int toErase = percentage < 10 ? 1 : (percentage == 100 ? 3 : 2);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Men consist " + std::to_string(percentage).erase(toErase) + "% of all the patients." << std::endl;
    std::cout << "Male patients to women patients ratio is " << float(menCount) / float(womenCount) << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "  Welcome to the COVID patients management app  " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::vector<Patient> patients;

    // Inserting some seed data
    patients.push_back(Patient("1", "Patrick", "Davis", 71, true, Male, Date(2020, 12, 21, 4, 45), Date(2020, 2, 24, 4, 45), Date()));
    patients.push_back(Patient("87623654", "Anthony", "Johnson", 89, true, Male, Date(2020, 12, 18, 4, 45), Date(2020, 12, 21, 4, 45), Date()));
    patients.push_back(Patient("24587905", "Meredith", "Brown", 28, false, Female, Date(2020, 12, 12, 4, 45), Date(2020, 12, 21, 4, 45), Date()));
    patients.push_back(Patient("67535763", "Jay", "Dunphie", 56, true, Male, Date(2020, 12, 1, 4, 45), Date(), Date()));
    patients.push_back(Patient("13498376", "Alex", "Smith", 25, true, Female, Date(2020, 12, 18, 5, 45), Date(), Date()));
    patients.push_back(Patient("13465209", "Luke", "Heimert", 72, true, Male, Date(2020, 12, 17, 1, 50), Date(), Date(2019, 4, 19, 12, 1)));
    patients.push_back(Patient("42719475", "Emma", "Miller", 23, false, Female, Date(2020, 1, 9, 1, 50), Date(2019, 6, 11, 7, 40), Date()));

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
        std::cout << " [8] Show all patients' records (sorted by admission date)" << std::endl;
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
        case 7:
            std::cout << "---Showing all patients' records who have discharged---" << std::endl;
            display_discharged_patients_records(&patients);
            break;
        case 8:
            std::cout << "---Showing all patients' records (sorted by admission date) ---" << std::endl;
            display_all_patients(&patients);
            break;
        case 9:
            display_percentage_of_dead(70, true, &patients);
            break;
        case 10:
            display_men_to_women_patients_ratio(&patients);
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
