#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a patient
struct Patient {
    string name;
    int age;
    string gender;
    string illness;
};

// Define a structure to represent a doctor
struct Doctor {
    string name;
    string specialization;
};

// Define a structure to represent a hospital
struct Hospital {
    string name;
    vector<Doctor> doctors;
    vector<Patient> patients;
};

// Function to add a new patient to the hospital
void addPatient(Hospital& hospital) {
    Patient newPatient;
    cout << "Enter patient name: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newPatient.name);
    cout << "Enter patient age: ";
    cin >> newPatient.age;
    cout << "Enter patient gender: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newPatient.gender);
    cout << "Enter patient illness: ";
    getline(cin, newPatient.illness);

    hospital.patients.push_back(newPatient);
    cout << "Patient added successfully!" << endl;
}

// Function to add a new doctor to the hospital
void addDoctor(Hospital& hospital) {
    Doctor newDoctor;
    cout << "Enter doctor name: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newDoctor.name);
    cout << "Enter doctor's specialization: ";
    getline(cin, newDoctor.specialization);

    hospital.doctors.push_back(newDoctor);
    cout << "Doctor added successfully!" << endl;
}

// Function to display all patients in the hospital
void displayPatients(const Hospital& hospital) {
    cout << "\nPatients:" << endl;
    cout << "-----------------------------------" << endl;
    for (const auto& patient : hospital.patients) {
        cout << "Name: " << patient.name << ", Age: " << patient.age << ", Gender: " << patient.gender << ", Illness: " << patient.illness << endl;
    }
    cout << "-----------------------------------" << endl;
}

// Function to display all doctors in the hospital
void displayDoctors(const Hospital& hospital) {
    cout << "\nDoctors:" << endl;
    cout << "-----------------------------------" << endl;
    for (const auto& doctor : hospital.doctors) {
        cout << "Name: " << doctor.name << ", Specialization: " << doctor.specialization << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    Hospital hospital;
    hospital.name = "ABC Hospital";

    int choice;

    do {
        cout << "\nHospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Display Patients\n";
        cout << "4. Display Doctors\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(hospital);
                break;
            case 2:
                addDoctor(hospital);
                break;
            case 3:
                displayPatients(hospital);
                break;
            case 4:
                displayDoctors(hospital);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}