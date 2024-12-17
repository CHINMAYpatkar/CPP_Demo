#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Package {
public:
    string destination;
    string startDate;
    string endDate;
    float price;

    Package(string dest, string start, string end, float pr) : destination(dest), startDate(start), endDate(end), price(pr) {}
};

class TravelAgency {
private:
    vector<Package> packages;

public:

    void addPackage(string dest, string start, string end, float pr) {
        Package newPackage(dest, start, end, pr);
        packages.push_back(newPackage);
        cout << "Package added successfully!" << endl;
    }

    void displayPackages() {
        cout << "Available Packages:" << endl;
        for (int i = 0; i < packages.size(); ++i) {
            cout << i+1 << ". Destination: " << packages[i].destination << ", Start Date: " << packages[i].startDate
                 << ", End Date: " << packages[i].endDate << ", Price: $" << packages[i].price << endl;
        }
    }


    void searchByDestination(string dest) {
        cout << "Packages to " << dest << ":" << endl;
        for (int i = 0; i < packages.size(); ++i) {
            if (packages[i].destination == dest) {
                cout << "Destination: " << packages[i].destination << ", Start Date: " << packages[i].startDate
                     << ", End Date: " << packages[i].endDate << ", Price: $" << packages[i].price << endl;
            }
        }
    }
};

int main() {
    TravelAgency agency;

    // Adding some sample packages
    agency.addPackage("Paris", "2024-06-01", "2024-06-07", 1500);
    agency.addPackage("Tokyo", "2024-07-15", "2024-07-21", 2000);
    agency.addPackage("New York", "2024-08-10", "2024-08-17", 1800);

    int choice;
    string destination;
    cout << "Welcome to the Travel Agency Management System!" << endl;

    do {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Display available packages" << endl;
        cout << "2. Search packages by destination" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                agency.displayPackages();
                break;
            case 2:
                cout << "Enter destination: ";
                cin >> destination;
                agency.searchByDestination(destination);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 3);

    return 0;
}












    