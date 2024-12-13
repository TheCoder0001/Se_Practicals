// This code as all that is needed for required operations just proper conditions are missing

#include <iostream>
#include <string>

using namespace std;

// Node structure to represent a club member
struct Node {
    int prn;          // Student PRN
    string name;      // Student Name
    Node* next;       // Pointer to the next node in the linked list

    // Constructor to initialize a node with given PRN and Name
    Node(int prn, string name) : prn(prn), name(name), next(nullptr) {}
};

// ClubList class to manage the linked list of club members
class ClubList {
private:
    Node* head;       // Pointer to the first node in the linked list
    Node* president;  // Pointer to the President node
    Node* secretary;  // Pointer to the Secretary node

public:
    // Constructor to initialize an empty linked list
    ClubList() : head(nullptr), president(nullptr), secretary(nullptr) {}

    // Function to add a new member at the end of the list
    void addMember(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = newNode;
            president = newNode;  // First member is the President
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        secretary = newNode;  // Last member is the Secretary
        cout << "Member added: PRN " << prn << ", Name " << name << endl;
    }

    // Function to delete a member by PRN
    void deleteMember(int prn) {
        Node* temp = head;
        Node* prev = nullptr;

        // Search for the node with the given PRN
        while (temp != nullptr && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }

        // If the node is found, delete it
        if (temp != nullptr) {
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            cout << "Member deleted: PRN " << prn << endl;
        } else {
            cout << "Member not found with PRN " << prn << endl;
        }
    }

    // Function to compute the total number of members
    int getTotalMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display all members
    void displayMembers() {
        Node* temp = head;
        cout << "Club Members:" << endl;
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
        cout << "President: PRN " << president->prn << ", Name " << president->name << endl;
        cout << "Secretary: PRN " << secretary->prn << ", Name " << secretary->name << endl;
    }

    // Function to concatenate two linked lists
    void concatenateLists(ClubList& otherList) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = otherList.head;
        secretary = otherList.secretary;  // Update Secretary to the last member of the concatenated list
        cout << "Lists concatenated successfully." << endl;
    }

    // Function to insert a member at a specific position
    void insertAtPosition(int position, int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            president = newNode;
        } else {
            Node* temp = head;
            for (int i = 2; i < position && temp->next != nullptr; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == nullptr) {
                secretary = newNode;
            }
        }
        cout << "Member inserted at position " << position << ": PRN " << prn << ", Name " << name << endl;
    }
};

int main() {
    ClubList division1;
    ClubList division2;

    int choice;
    do {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Add Member\n2. Delete Member\n3. Compute Total Members\n";
        cout << "4. Display Members\n5. Concatenate Two Divisions\n";
        cout << "6. Insert Member at Position\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int prn;
                string name;
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, name);
                division1.addMember(prn, name);
                break;
            }
            case 2: {
                int prn;
                cout << "Enter PRN to delete: ";
                cin >> prn;
                division1.deleteMember(prn);
                break;
            }
            case 3:
                cout << "Total Members: " << division1.getTotalMembers() << endl;
                break;
            case 4:
                division1.displayMembers();
                break;
            case 5:
                division1.concatenateLists(division2);
                break;
            case 6: {
                int position, prn;
                string name;
                cout << "Enter position to insert: ";
                cin >> position;
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, name);
                division1.insertAtPosition(position, prn, name);
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
