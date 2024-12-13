#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// User-defined structure for personal records
struct PersonalRecord {
    string name;
    string dob;
    string phoneNumber;

    // Constructor for initializing the record
    PersonalRecord(string n, string d, string phone) : name(n), dob(d), phoneNumber(phone) {}
};

// Function to display a personal record
void displayRecord(const PersonalRecord& record) {
    cout << "Name: " << record.name << "\tDOB: " << record.dob << "\tPhone: " << record.phoneNumber << endl;
}

int main() {
    // Vector to store personal records
    vector<PersonalRecord> personalRecords;

    // Getting input from the user
    cout << "Enter personal records. To stop, enter 'stop' for the name.\n";
    while (true) {
        string name, dob, phoneNumber;

        cout << "\nEnter Name (or 'stop' to finish): ";
        getline(cin, name);

        if (name == "stop") {
            break; // Stop entering records
        }

        cout << "Enter Date of Birth: ";
        getline(cin, dob);

        cout << "Enter Telephone Number: ";
        getline(cin, phoneNumber);

        personalRecords.push_back(PersonalRecord(name, dob, phoneNumber));
    }

    // Sorting the records based on names
    sort(personalRecords.begin(), personalRecords.end(), [](const PersonalRecord& a, const PersonalRecord& b) {
        return a.name < b.name;
    });

    // Displaying sorted records
    cout << "\nSorted Records based on Name:\n";
    for (const auto& record : personalRecords) {
        displayRecord(record);
    }

    // Searching for a record based on name
    string searchName;
    cout << "\nEnter a name to search: ";
    getline(cin, searchName);

    auto iter = find_if(personalRecords.begin(), personalRecords.end(), [searchName](const PersonalRecord& record) {
        return record.name == searchName;
    });

    // Display the search result
    if (iter != personalRecords.end()) {
        cout << "Record found:\n";
        displayRecord(*iter);
    } else {
        cout << "Record not found.\n";
    }

    return 0;
}
