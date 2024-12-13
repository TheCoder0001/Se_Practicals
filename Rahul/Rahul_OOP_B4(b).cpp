#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    
public:
	string Name;
    int Id;
    char Div;

    void get_data()
    {
        cout << "Enter Name: " << endl;
        cin >> Name;
        cout << "Enter ID: " << endl;
        cin >> Id;
        cout << "Enter Division: " << endl;
        cin >> Div;
    }

    void show()
    {
        cout << "\n Name: " << Name;
        cout << "\n Id: " << Id;
        cout << "\n Division: " << Div << endl;
    }
};

int main()
{
	string filename;
    cout<<"Enter a filename:";
    cin>>filename;
    fstream f1;
    f1.open(filename, ios::out); // Open file for writing in binary mode
    if (!f1)
    {
        cerr << "Could not open file for writing\n";
        return 1;
    }

    Student I[5];
	Student O[5];
    int i, n;

    cout << "ENTER NUMBER OF STUDENTS: " << endl;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << endl << "ENTER INFO for Student " << i + 1 << endl; // The student number display
        I[i].get_data();
		f1 << I[i].Name << ' ' << I[i].Id << ' ' << I[i].Div << '\n';
    }
	f1.close();
	
    // Open file for reading in binary mode
	f1.open(filename, ios::in); 
    if (!f1)
    {
        cerr << "Could not open file for reading\n";
        return 1;
    }

    cout << "\nINFORMATION\n";
    for(int i = 0; i < n; i++)
	{
        f1 >> O[i].Name >> O[i].Id >> O[i].Div;
		O[i].show();
    }
    f1.close();

    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    string Name;
    int Id;
    char Div;

    void get_data() {
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter ID: ";
        cin >> Id;
        cout << "Enter Division: ";
        cin >> Div;
    }

    void show() {
        cout << "\nName: " << Name;
        cout << "\nId: " << Id;
        cout << "\nDivision: " << Div << endl;
    }
};

int main() {
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;

    fstream f1;
    f1.open(filename, ios::out); // Open file for writing
    if (!f1) {
        cerr << "Could not open file for writing\n";
        return 1;
    }

    Student* I;
    Student* O;

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    I = new Student[n];
    O = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter info for Student " << i + 1 << endl;
        I[i].get_data();
        f1 << I[i].Name << ' ' << I[i].Id << ' ' << I[i].Div << '\n';
    }
    f1.close();

    f1.open(filename, ios::in); // Open file for reading
    if (!f1) {
        cerr << "Could not open file for reading\n";
        return 1;
    }

    cout << "\nINFORMATION\n";
    for (int i = 0; i < n; i++) {
        f1 >> O[i].Name >> O[i].Id >> O[i].Div;
        O[i].show();
    }
    f1.close();

    delete[] I;
    delete[] O;

    return 0;
}
*/