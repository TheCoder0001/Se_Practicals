#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class PersonClass
{
private:
    char name[40], clas[10], div[2], dob[15], bloodgrp[5];

public:
    int roll;
    static int count; // static data
    friend class PersonnelClass;

    // Default constructor
    PersonClass()
    {
        roll = 0;
    }

    // Destructor
    ~PersonClass()
    {
        cout << "\nPersonClass Destructor Called for Roll Number: " << roll;
    }

    // Static method
    static void TotalRecordCount()
    {
        cout << "\n\n\nTOTAL NUMBER OF RECORDS CREATED: " << count;
    }

    // Inline DisplayData function
    inline void DisplayData()
    {
        cout << "\n";
        cout << roll << " "
             << name << " "
             << clas << " "
             << div << " "
             << dob << " "
             << bloodgrp << " ";
    }
};

class PersonnelClass
{
private:
    char address[30], telephone_no[15], policy_no[10], license_no[10];

public:
    ~PersonnelClass()
    {
        // Destructor to clean up dynamically allocated memory
        cout << "\nPersonnelClass Destructor Called";
    }

    void InputData(PersonClass *obj);
    void DisplayData(PersonClass *obj);
    friend class PersonClass;
};

// Definition of static member
int PersonClass::count = 0;

void PersonnelClass::InputData(PersonClass *obj)
{
    cout << "\nROLLNO: ";
    cin >> obj->roll;
    cout << "\nNAME: ";
    cin >> obj->name;
    cout << "\nCLASS: ";
    cin >> obj->clas;
    cout << "\nDIVISION: ";
    cin >> obj->div;
    cout << "\nDATE OF BIRTH(DD-MM-YYYY): ";
    cin >> obj->dob;
    cout << "\nBLOOD GROUP: ";
    cin >> obj->bloodgrp;
    cout << "\nADDRESS: ";
    cin >> this->address;
    cout << "\nTELEPHONE NUMBER: ";
    cin >> this->telephone_no;
    cout << "\nDRIVING LICENSE NUMBER: ";
    cin >> this->license_no;
    cout << "\nPOLICY NUMBER: ";
    cin >> this->policy_no;
    obj->count++;
}

void PersonnelClass::DisplayData(PersonClass *obj)
{
    obj->DisplayData();
    cout << this->address << " "
         << this->telephone_no << " "
         << this->license_no << " "
         << this->policy_no;
}

int main()
{
    PersonnelClass *a[10];
    PersonClass *c[10];
    int n = 0, i, choice;
    char ans;
    do
    {
        cout << "\n\nMENU: ";
        cout << "\n\t1. Input Data\n\t2. Display Data\n\t3. Delete Data";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\n\tENTER THE DETAILS";
            cout << "\n —————————————";
            do
            {
                a[n] = new PersonnelClass;
                c[n] = new PersonClass;
                a[n]->InputData(c[n]);
                n++;
                PersonClass::TotalRecordCount();
                cout << "\n\nDo you want to add more records? (y/n): ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
            break;

        case 2:
            cout << "\n——————————————————————————-";
            cout << "\n Roll Name Class Div BirthDate Address Telephone Blood_Gr Licence Policy ";
            cout << "\n——————————————————————————";
            for (i = 0; i < n; i++)
                a[i]->DisplayData(c[i]);
            PersonClass::TotalRecordCount();
            break;

        case 3:
            cout << "\n\n\tDELETE DATA";
            cout << "\n —————————————";
            if (n > 0) {
                int rollToDelete;
                cout << "\nEnter Roll Number to delete: ";
                cin >> rollToDelete;
                int deleteIndex = -1;

                // Find the index of the record with the specified roll number
                for (i = 0; i < n; i++) {
                    if (c[i]->roll == rollToDelete) {
                        deleteIndex = i;
                        break;
                    }
                }

                // Delete the record if found
                if (deleteIndex != -1) {
                    delete a[deleteIndex];
                    delete c[deleteIndex];
                    cout << "\nRecord with Roll Number " << rollToDelete << " deleted successfully.";
                    // Shift the remaining records to fill the gap
                    for (i = deleteIndex; i < n - 1; i++) {
                        a[i] = a[i + 1];
                        c[i] = c[i + 1];
                    }
                    n--; // Decrement the count of records
                    PersonClass::TotalRecordCount();
                } else {
                    cout << "\nRecord with Roll Number " << rollToDelete << " not found.";
                }
            } else {
                cout << "\nNo records to delete.";
            }
            break;
        }
        cout << "\n\nDo you want to go to the main menu? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    // Delete dynamically allocated objects and display a message
    for (i = 0; i < n; i++)
    {
        delete a[i];
        delete c[i];
    }

    cout << "\nAll objects deleted successfully.\n";

    return 0;
}
