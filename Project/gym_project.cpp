#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class person {
public:
    int id;
    long long int phone_no;
    string name, address;

    void get_person_data() {
        cout << "Getting Data " << endl << endl;
        cout << "Enter the Name " << endl;
        cin >> name;
        cout << "Enter the Phone Number " << endl;
        cin >> phone_no;
        cout << "Enter the Address " << endl;
        cin.ignore(); // Ignore any previous newline character
        getline(cin, address);
        id++;
    }

    void put_person_data(ofstream& file) {
        cout << endl << endl << "Putting Data " << endl << endl;
        cout << "Id no : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Phone No : " << phone_no << endl;
        cout << "Address : " << address << endl;

        // Write data to the file
        file << "ID: " << id << ", Name: " << name << ", Phone No: " << phone_no << ", Address: " << address << endl;
    }
};

class packet {
public:
    long int price;
    int duration, choice;

    void packet_accept() {
        cout << "What packet Do you Want " << endl;
        cout << "1. Duration :1 Year " << endl << " Price :2700" << endl;
        cout << "2. Duration :6 Month " << endl << " Price : 2000" << endl;
        cout << "3. Duration :3 Month " << endl << " Price : 1500" << endl;
        cout << "4. Duration :2 Month " << endl << " Price : 700" << endl;
        cout << "5. Duration :1 Month " << endl << " Price : 500" << endl;

        cout << endl << "Enter the Choice " << endl;
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
    }
};

class customer : public person, public packet {
public:
    void get_customer_data() {
        get_person_data();
        packet_accept();
    }

    void put_customer_data(ofstream& file) {
        put_person_data(file);
        cout << "Amount is " << price;

        // Write price to the file
        file << ", Amount: " << price << endl;
    }
};

int main() {
    ofstream outFile("customer_data.txt", ios::app); // Open file for appending
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    customer c1;
    c1.get_customer_data();
    c1.put_customer_data(outFile);

    outFile.close();

    return 0;
}
