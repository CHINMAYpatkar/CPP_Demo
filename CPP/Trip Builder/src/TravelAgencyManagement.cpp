/*
 * TravelAgencyManagement.cpp
 *
 *  Created on: 30-May-2024
 *      Author: Chinmay
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class TravelAgency {
    public:
        vector<string> *v;

    public:

        TravelAgency() {
            v = new vector<string>;
        }


        ~TravelAgency() {
            delete v;
        }


        void newEntry() {
            string destination, mode, startDate, endDate, passengerName;
            int age;
            cout << "Enter destination to add: ";
            cin >> destination;
            cout << "Enter start date (YYYY-MM-DD): ";
            cin >> startDate;
            cout << "Enter end date (YYYY-MM-DD): ";
            cin >> endDate;
            cout << "Choose mode for travel: ";
            cin >> mode;
            cout << "Enter passenger name: ";
            cin >> passengerName;
            cout << "Enter passenger age: ";
            cin >> age;

            string entryData = destination + " " + startDate + " " + endDate + " " + mode + " " + passengerName + " " + to_string(age);
            v->push_back(entryData);

            cout << "Travel entry added successfully.\n";
        }

        void changeEntry() {
            string destination;
            cout << "Enter the destination you want to modify: ";
            cin >> destination;

            bool found = false;
            for (auto &entry : *v) {
                istringstream iss(entry);
                string entryDestination, entryStartDate, entryEndDate, entryMode, entryPassengerName;
                int entryAge;
                iss >> entryDestination >> entryStartDate >> entryEndDate >> entryMode >> entryPassengerName >> entryAge;
                if (entryDestination == destination) {
                    cout << "Enter new destination: ";
                    cin >> destination;
                    cout << "Enter start date (YYYY-MM-DD): ";
                    cin >> entryStartDate;
                    cout << "Enter end date (YYYY-MM-DD): ";
                    cin >> entryEndDate;
                    cout << "Choose mode for travel: ";
                    cin >> entryMode;
                    cout << "Enter passenger name: ";
                    cin >> entryPassengerName;
                    cout << "Enter passenger age: ";
                    cin >> entryAge;


                    entry = destination + " " + entryStartDate + " " + entryEndDate + " " + entryMode + " " + entryPassengerName + " " + to_string(entryAge);

                    cout << "Travel entry updated successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Destination not found.\n";
            }
        }

        void printEntries() {
            cout << "Listing all travel entries:" << endl;
            for (const auto &entry : *v) {
                cout << entry << endl;
            }
            cout << endl;
        }

        void deleteEntry() {
            string destination;
            cout << "Enter the destination you want to delete: ";
            cin >> destination;

            bool found = false;
            for (auto it = v->begin(); it != v->end(); ++it) {
                istringstream iss(*it);
                string entryDestination, entryStartDate, entryEndDate, entryMode, entryPassengerName;
                int entryAge;
                iss >> entryDestination >> entryStartDate >> entryEndDate >> entryMode >> entryPassengerName >> entryAge;
                if (entryDestination == destination) {
                    v->erase(it);
                    cout << "Travel entry deleted successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Destination not found.\n";
            }
        }
};

class AdvancedTravelAgency : public TravelAgency {

public:
    void printEntryCount() {
        cout << "Advanced Travel Agency Information" << endl;
        cout << "Number of travel entries: " << v->size() << endl;
    }
};

int main() {
    TravelAgency *agency = new TravelAgency();
    int choice;
    while (true) {
        cout << "*Travel Agency Management System ***" << endl;
        cout << "Choose 1 to add new travel entry" << endl;
        cout << "Choose 2 to modify a travel entry" << endl;
        cout << "Choose 3 to display all travel entries" << endl;
        cout << "Choose 4 to delete a travel entry" << endl;
        cout << "Choose 5 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Adding New Travel Entry" << endl;
                agency->newEntry();
                break;
            case 2:
                cout << "Modifying Travel Entry" << endl;
                agency->printEntries();
                agency->changeEntry();
                break;
            case 3:
                cout << "Displaying All Travel Entries" << endl;
                agency->printEntries();
                break;
            case 4:
                cout << "Deleting Travel Entry" << endl;
                agency->printEntries();
                agency->deleteEntry();
                break;
            case 5:
                cout << "Exiting Travel Agency Management System. Goodbye!" << endl;
                delete agency;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}







