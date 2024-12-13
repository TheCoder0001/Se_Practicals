#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileCreator {
    
    private:
        ofstream fileStream;
    public:
        // Constructor that takes a filename and creates the file
        FileCreator(string filename) {
            fileStream.open(filename, ios::out);
            if (!fileStream.is_open()) {
                cerr << "Error opening file: " << filename << endl;
            } else {
                cout << "File created successfully: " << filename << endl;
            }
        }
    
        // Destructor to close the file when the object is destroyed
        ~FileCreator() {
            if (fileStream.is_open()) {
                fileStream.close();
                cout << "File closed." << endl;
            }
        }
    
        // Function to write content to the file
        void writeContent(string content) {
            if (fileStream.is_open()) {
                fileStream << content;
                cout << "Content written to file." << endl;
            } else {
                cerr << "File is not open." << endl;
            }
        }

};

int main() {
    // Create an instance of FileCreator, which will create a file named "example.txt"
    FileCreator fileCreator("example.txt");

    // Write content to the file
    fileCreator.writeContent("Hello, this is some content.");

    // The file will be closed when the FileCreator object goes out of scope (end of main function)

    return 0;
}
