#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
using namespace std;

class person{
static int latest_id;
public:
     int id;
    long long int phone_no;
    string name, address;

    static int get_next_id() {
        return rand();
    }
       
    void get_person_data()
    {
        id = rand();
        cout << "Getting Data " << endl
             << endl;
        cout << "Enter the Name " << endl;
        cin >> name;
        cout << "Enter the Phone Number " << endl;
        cin >> phone_no;
        cout << "Enter the Address " << endl;
        cin.ignore(); 
        getline(cin, address);
        
    }

    void put_person_data(ofstream &file)
    {
        cout << endl
             << endl
             << "Putting Data " << endl
             << endl;
        cout << "Id no : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Phone No : " << phone_no << endl;
        cout << "Address : " << address << endl;

        
        //file << "ID: " << id << ", Name: " << name << ", Phone No: " << phone_no << ", Address: " << address << endl;
    }
};
int person::latest_id=0;
class packet
{
public:
    long int price;
    int duration, choice;

    void packet_accept()
    {
        cout << "What packet Do you Want " << endl;
        cout << "1. Duration :1 Year " << endl
             << " Price :2700" << endl;
        cout << "2. Duration :6 Month " << endl
             << " Price : 2000" << endl;
        cout << "3. Duration :3 Month " << endl
             << " Price : 1500" << endl;
        cout << "4. Duration :2 Month " << endl
             << " Price : 700" << endl;
        cout << "5. Duration :1 Month " << endl
             << " Price : 500" << endl;

        cout << endl
             << "Enter the Choice " << endl;
        cin >> choice;

        switch (choice)
        {
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

class customer : public person, public packet
{
public:
    void get_customer_data()
    {
        ofstream outFile("customer_data.txt", ios::app); 
        if (!outFile)
        {
            cerr << "Error opening file." << endl;
            exit;
        }
        get_person_data();
        packet_accept();
        
        outFile << "ID: " << id << ", Name: " << name << ", Phone No: " << phone_no << ", Address: " << address ;
        outFile << ", Amount: " << price << endl;
        outFile.close();
    }

    void put_customer_data()
    {
                ofstream outFile("customer_data.txt", ios::app); 
        if (!outFile)
        {
            cerr << "Error opening file." << endl;
            exit;
        }
        put_person_data(outFile);   
    }

    void show_customer_data()
    {
        int search_id;
        cout << "Enter ID to search: ";
        cin >> search_id;

        ifstream inFile("customer_data.txt");
        if (!inFile)
        {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        while (getline(inFile, line))
        {
            size_t found = line.find("ID: " + to_string(search_id));
            if (found != string::npos)
            {
                cout << "Customer Data:" << endl;
                cout << line << endl;
                return;
            }
        }

        cout << "Customer with ID " << search_id << " not found." << endl;
    }

    void show_all_customer_data()
    {
        ifstream inFile("customer_data.txt");
        if (!inFile)
        {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        cout << "All Customer Data:" << endl;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
    }
};

class Employee : public customer
{
public:
    void get_employee_data()
    {
        get_person_data();
        save_employee_data();
    }

    void save_employee_data()
    {
        ofstream outFile("employee_data.txt", ios::app); 
        if (!outFile)
        {
            cerr << "Error opening file." << endl;
            return;
        }

        outFile.close();
        cout << "Employee data saved successfully." << endl;
    }

    void put_employee_data(){
                ofstream outFile("employee_data.txt", ios::app); 
        if (!outFile)
        {
            cerr << "Error opening file." << endl;
            return;
        }
        put_person_data(outFile);
        outFile.close();
    }
};

class Admin:public Employee{
    public:
    string name,password;

    void admin_entery(){
        cout<<"Enter the Name "<<endl;
        cin>>name;
        cout<<"Enter the Password "<<endl;
        cin>>password;

         ofstream outFile("Admin_data.txt", ios::app); 
        if (!outFile)
        {
            cerr << "Error opening file." << endl;
            return;
        }
        outFile<<"Name :"<<name<<" Password :"<<password;
        outFile.close();
        cout << "Admin data saved successfully." << endl;
        
    }

    void admin_only(){
     
    string input_name, input_password;
    cout << "Enter your name: ";
    cin >> input_name;
    cout << "Enter your password: ";
    cin >> input_password;

    ifstream inFile("Admin_data.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

   string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(":");
        if (pos != string::npos) {
            string storedName = line.substr(6, pos - 6); // Extract stored name
            string storedPassword = line.substr(pos + 1); // Extract stored password

            if (input_name == storedName && input_password == storedPassword) {
                cout << "Welcome, " << input_name << "! Access granted." << endl;
                return;
            }
        }
    }

    cout << "Access denied. User not found or incorrect credentials." << endl;
}

    
};

int main()
{

    customer c1;
     c1.get_customer_data();
    // c1.put_customer_data();

    // c1.show_all_customer_data();

    //  c1.show_customer_data();

    // Employee e1;
    // e1.get_employee_data();

    // e1.put_employee_data();

    // Admin a1;
    // a1.admin_entery();
    // a1.admin_only();

    return 0;
}
