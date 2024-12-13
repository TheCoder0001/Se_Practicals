// Refer this code over the other one

#include <iostream>
#include <iomanip>
using namespace std;

// Node representing a seat
struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int number) : seatNumber(number), isBooked(false), next(nullptr), prev(nullptr) {}
};

// Circular Linked List representing seats
class SeatList {
private:
    Seat* head;

public:
    SeatList() : head(nullptr) {}

    // Initialize the circular linked list with 70 seats
    void initialize() {
        for (int i = 1; i <= 70; ++i) {
            Seat* newSeat = new Seat(i);
            addSeat(newSeat);
        }
    }

    // Add a seat to the circular linked list
    void addSeat(Seat* newSeat) {
        if (head == nullptr) {
            head = newSeat;
            head->next = head;
            head->prev = head;
        } else {
            Seat* lastSeat = head->prev;
            lastSeat->next = newSeat;
            newSeat->prev = lastSeat;
            newSeat->next = head;
            head->prev = newSeat;
        }
    }

    // Display the seats in the specified format
    void displaySeats() {
        Seat* current = head;

        cout << endl << endl;

        int count = 0;
        do {
            cout << "S" << setfill('0') << setw(2) << current->seatNumber << " :|";
            if (current->isBooked) {
                cout << "_B_| ";
            } else {
                cout << "___| ";
            }

            current = current->next;
            count++;

            // Start a new line before every 10th seat
            if (count % 10 == 0) {
                cout << endl;
            }
        } while (current != head);

        cout << endl;
    }

    // Book a seat
    void bookSeat(int seatNumber) {
        Seat* current = head;

        do {
            if (current->seatNumber == seatNumber && !current->isBooked) {
                current->isBooked = true;
                cout << "Seat booked: S" << setfill('0') << setw(2) << seatNumber << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Seat not available or invalid seat number." << endl;
    }

    // Cancel a booked seat
    void cancelBooking(int seatNumber) {
        Seat* current = head;

        do {
            if (current->seatNumber == seatNumber && current->isBooked) {
                current->isBooked = false;
                cout << "Booking canceled: S" << setfill('0') << setw(2) << seatNumber << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Seat not booked or invalid seat number." << endl;
    }
};

int main() {
    SeatList seatList;

    // Initialize seats
    seatList.initialize();

    int choice;
    do {
        cout << "\nCinemax Theater Booking System\n";
        cout << "1. Display seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                seatList.displaySeats();
                break;

            case 2: {
                // Book a seat
                int seat;
                cout << "Enter seat number: ";
                cin >> seat;

                if (seat >= 1 && seat <= 70) {
                    seatList.bookSeat(seat);
                } else {
                    cout << "Invalid seat number." << endl;
                }
                break;
            }

            case 3: {
                // Cancel booking
                int seat;
                cout << "Enter seat number: ";
                cin >> seat;

                if (seat >= 1 && seat <= 70) {
                    seatList.cancelBooking(seat);
                } else {
                    cout << "Invalid seat number." << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
