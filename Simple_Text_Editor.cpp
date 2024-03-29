#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cctype>
#include <stdlib.h>

using namespace std;

string the_file;

void write_to_file() {
    cout << "enter file you want to edit: ";
    cin >> the_file;
    cin.ignore();
    cout << "Type here: ";
    string add_to_file;
    getline(cin, add_to_file);

    unique_ptr<ofstream> file(new ofstream(the_file, ios::app));

    *file << add_to_file << endl;
    file->close();
}

void read_file(string the_file) {
    ifstream file(the_file);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << the_file << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void delete_file() {
    cout << "enter the file you want to delete: ";
    cin >> the_file;

    cout << "Are you sure you want to delete this file? enter y or n: ";
    char option;
    cin >> option;

    switch (tolower(option)) {
        case 'y': 
        {
            int result = remove(the_file.c_str());
            if (result == 0) {
                cout << "file has been deleted \n";
            } else {
                cout << "failed to delete file \n";
            }
            
            break;
        }
        case 'n':{

            cout << "File will not be deleted.\n";
            break;
        }
        default:
            cout << "That is an invalid option.\n";
            break;
    }
}

int main() {
    char choice;
    while (choice != 'q') {
        cout << "would you like to (W)rite to a file, (D)elete file, (R)ead file, Or (Q)uit: ";
        cin >> choice;

        switch (tolower(choice)) {
            case 'w':
                write_to_file();
                read_file(the_file);
                break;
            case 'r':
                cout << "select file you want to read: ";
                cin >> the_file;
                read_file(the_file);
                break;
            case 'd':
                delete_file();
                break;
                 default:
                cout<<"Invalid input \n"<<endl;

        }
    }
    system("clear");
    return 0;
}
