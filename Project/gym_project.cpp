#include <iostream>
#include <fstream>
#include <iomanip> // For setw and setfill
#include <cstdlib>
#include <limits> // For clearing input buffer
using namespace std;

class person {
    static int latest_id;

public:
    int id;
    long long int phone_no;
    string name, address;

    static int get_next_id() {
        return rand();
    }

    void get_person_data() {
        id = rand();
        cout << "Getting Data " << endl << endl;
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the Phone Number: ";
        cin >> phone_no;
        cout << "Enter the Address: ";
        cin.ignore();
        getline(cin, address);

    }

    void put_person_data() {
        cout << endl << endl << "Putting Data " << endl << endl;
        cout << "Id no : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Phone No : " << phone_no << endl;
        cout << "Address : " << address << endl;



    }
};
int person::latest_id = 0;

class packet {
public:
    long int price;
    int duration, choice;

    void packet_accept() {
        cout << "What packet Do you Want " << endl;
        cout << setw(2) << setfill(' ') << "1. Duration :1 Year   Price : 2700" << endl;
        cout << setw(2) << setfill(' ') << "2. Duration :6 Month   Price : 2000" << endl;
        cout << setw(2) << setfill(' ') << "3. Duration :3 Month   Price : 1500" << endl;
        cout << setw(2) << setfill(' ') << "4. Duration :2 Month   Price :  700" << endl;
        cout << setw(2) << setfill(' ') << "5. Duration :1 Month   Price :  500" << endl;
        cout << endl << "Enter the Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                price = 2700;
                break;
            case 2:
                price = 2000;
                break;
            case 3:
                price = 1500;
                break;
            case 4:
                price = 700;
                break;
            case 5:
                price = 500;
                break;
            default:
                cout << "Enter the Valid Option Packet is not inserted ";
        }
        cout << "Amount is " << price;
    }
};

class customer : public person, public packet {
public:
    void get_customer_data() {
        ofstream outFile("customer_data.txt", ios::app);
        if (!outFile) {
            cerr << "Error opening file." << endl;
            exit(1);
        }
        get_person_data();
        packet_accept();

        outFile << "ID: " << id << ", Name: " << name << ", Phone No: " << phone_no << ", Address: " << address;
        outFile << ", Amount: " << price << endl;
        outFile.close();
    }

    void show_customer_data() {
        int search_id;
        cout << "Enter ID to search: ";
        cin >> search_id;

        ifstream inFile("customer_data.txt");
        if (!inFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            size_t found = line.find("ID: " + to_string(search_id));
            if (found != string::npos) {
                cout << "Customer Data:" << endl;
                cout << line << endl;
                return;
            }
        }

        cout << "Customer with ID " << search_id << " not found." << endl;
    }

    void show_all_customer_data() {
        ifstream inFile("customer_data.txt");
        if (!inFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        cout << "All Customer Data:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }

    static void sum_all_amounts() {
        ifstream inFile("customer_data.txt");
        if (!inFile) {
            cerr << "Error opening file." << endl;
            exit(1);
        }

        int sum = 0;
        string line;
        while (getline(inFile, line)) {
            size_t found = line.find("Amount: ");
            if (found != string::npos) {
                string amountStr = line.substr(found + 8);
                int amount = stoi(amountStr);
                sum += amount;
            }
        }

        inFile.close();
        cout << "Total amount entered in customer_data.txt: " << sum << endl;
    }
};

class Employee : public customer {
public:
    void get_employee_data() {
        ofstream outFile("employee_data.txt", ios::app);
        if (!outFile) {
            cerr << "Error opening file." << endl;
            exit(1);
        }
        get_person_data();
        outFile << "ID: " << id << ", Name: " << name << ", Phone No: " << phone_no << ", Address: " << address;
        cout << "Employee data saved successfully." << endl;
        outFile.close();
    
    }



};

class Admin : public Employee {
public:
    string name, password;

    void get_all_amount() {
        customer::sum_all_amounts();
    }

    void show_menu() {
        int choice,num=0;
        while(num==0){
            // Clear screen
             // ANSI escape code for clearing screen
            cout << "Menu:" << endl;
            cout << setw(2) << setfill(' ') << "1. Customer (Add customer data)" << endl;
            cout << setw(2) << setfill(' ') << "2. Employee" << endl;
            cout << setw(2) << setfill(' ') << "3. Show Customer Data (By ID)" << endl;
            cout << setw(2) << setfill(' ') << "4. Show All Customer Data" << endl;
            cout << setw(2) << setfill(' ') << "5. Sum All Amounts" << endl;
            cout << setw(2) << setfill(' ') << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    get_customer_data();
                    cout << "\033[2J\033[1;1H";
                    break;
                case 2:
                    get_employee_data();
                    cout << "\033[2J\033[1;1H";
                    break;
                case 3:
                    show_customer_data();
                    
                    break;
                case 4:
                    show_all_customer_data();
                    
                    break;
                case 5:
                    get_all_amount();
                    
                    break;
                case 6:
                    cout << "Exiting program." << endl;
                    num=1;
                    return;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            }
        }
        }
};

int main() {
    Admin admin;
    admin.show_menu();
    return 0;
}
