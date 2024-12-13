#include <iostream>

namespace std; // Add the std namespace

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    Node* next;

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

// Function to insert a new term into the polynomial
void insertTerm(Node*& poly, int coef, int exp) {
    Node* newNode = new Node(coef, exp);

    if (poly == nullptr) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPoly(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coefficient;
        if (poly->exponent != 0) {
            cout << "x^" << poly->exponent;
        }
        poly = poly->next;
        if (poly != nullptr) {
            cout << " + ";
        }
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* current = result;

    while (poly1 != nullptr && poly2 != nullptr) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            // Exponents are equal, add coefficients
            insertTerm(result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (current == nullptr) {
            current = result;
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
        }
    }

    // Copy remaining terms from the non-empty polynomial
    while (poly1 != nullptr) {
        insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to delete the entire polynomial
void deletePoly(Node*& poly) {
    while (poly != nullptr) {
        Node* temp = poly;
        poly = poly->next;
        delete temp;
    }
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Insert terms into the first polynomial: 3x^2 + 2x + 5
    insertTerm(poly1, 3, 2);
    insertTerm(poly1, 2, 1);
    insertTerm(poly1, 5, 0);

    // Insert terms into the second polynomial: 4x^3 - 2x^2 + 1
    insertTerm(poly2, 4, 3);
    insertTerm(poly2, -2, 2);
    insertTerm(poly2, 1, 0);

    cout << "Polynomial 1: ";
    displayPoly(poly1);

    cout << "Polynomial 2: ";
    displayPoly(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    displayPoly(result);

    // Delete the linked lists to free memory
    deletePoly(poly1);
    deletePoly(poly2);
    deletePoly(result);

    return 0;
}
