#include <iostream>
#include <vector>
#include "User.h"
#include "Complaint.h"
#include "ComplaintService.h"
#include "SmartBin.h"
using namespace std;

void showMenu() {
    cout << "\n=== SMART WASTE SYSTEM ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Submit Complaint" << endl;
    cout << "3. Assign Complaint to Technician" << endl;
    cout << "4. Resolve Complaint" << endl;
    cout << "5. View All Complaints" << endl;
    cout << "6. Check Bin Status" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    cout << "(: ------------------ :)" << endl;
    cout << "   COPMPLAINT SYSTEM" << endl;
    cout << "(: ------------------ :)" << endl;

    Citizen citizen1(101, "John Smith", "john", "pass123");
    Technician tech1(201, "Ahmed Ali", "ahmed", "tech123");
    Driver driver1(301, "Mohamed Said", "mohamed", "drive123");

    ComplaintService complaintService;

    vector<SmartBin> bins;
    bins.push_back(SmartBin("BIN-001", "Main Street"));
    bins.push_back(SmartBin("BIN-002", "Park Avenue"));
    bins.push_back(SmartBin("BIN-003", "Market Square"));

    bins[0].updateFillLevel(85.0);
    bins[1].updateFillLevel(30.0);
    bins[2].updateFillLevel(92.0);

    bool running = true;
    while (running) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (citizen1.login(username, password)) {
                    cout << "Welcome Citizen " << citizen1.getName() << "!" << endl;
                } else if (tech1.login(username, password)) {
                    cout << "Welcome Technician " << tech1.getName() << "!" << endl;
                } else if (driver1.login(username, password)) {
                    cout << "Welcome Driver " << driver1.getName() << "!" << endl;
                } else {
                    cout << "Login failed!" << endl;
                }
                break;
            }
            case 2: {
                string description, name;
                cout << "Your name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Complaint description: ";
                getline(cin, description);

                complaintService.createComplaint(description, name);
                break;
            }
            case 3: {
                int compId;
                cout << "Enter complaint ID to assign: ";
                cin >> compId;
                complaintService.assignComplaint(compId, tech1.getName());
                break;
            }
            case 4: {
                int compId;
                cout << "Enter complaint ID to resolve: ";
                cin >> compId;
                complaintService.resolveComplaint(compId);
                break;
            }
            case 5: {
                complaintService.displayAllComplaints();
                break;
            }
            case 6: {
                cout << "\n=== SMART BIN STATUS ===" << endl;
                int needsCollection = 0;

                for (SmartBin& bin : bins) {
                    bin.display();
                    if (bin.needsCollection()) needsCollection++;
                }

                cout << "\nSUMMARY: " << needsCollection << " out of "
                     << bins.size() << " bins need collection." << endl;
                break;
            }
            case 7: {
                cout << "Thank you for using Smart Waste System!" << endl;
                running = false;
                break;
            }
            default:
                cout << "Invalid choice! Please enter 1-7." << endl;
        }
    }
    return 0;
}