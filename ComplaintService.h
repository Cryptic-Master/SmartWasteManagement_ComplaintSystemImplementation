#ifndef COMPLAINTSERVICE_H
#define COMPLAINTSERVICE_H
#include <vector>
#include <iostream>
#include "Complaint.h"
using namespace std;
class ComplaintService {
private:
    vector<Complaint> complaints;
    int nextId = 1001;

public:
    void createComplaint(string description, string citizenName) {
        Complaint newComplaint(nextId++, description, citizenName);
        complaints.push_back(newComplaint);
        cout << "New complaint created! ID: " << newComplaint.getId() << endl;
    }

    bool assignComplaint(int complaintId, string techName) {
        for (Complaint& comp : complaints) {
            if (comp.getId() == complaintId) {
                comp.assignTo(techName);
                return true;
            }
        }
        cout << "Complaint #" << complaintId << " not found!" << endl;
        return false;
    }

    bool resolveComplaint(int complaintId) {
        for (Complaint& comp : complaints) {
            if (comp.getId() == complaintId) {
                comp.resolve();
                return true;
            }
        }
        cout << "Complaint #" << complaintId << " not found!" << endl;
        return false;
    }

    Complaint getComplaint(int complaintId) {
        for (Complaint& comp : complaints) {
            if (comp.getId() == complaintId) {
                return comp;
            }
        }

        return Complaint(-1, "Not found", "Unknown");
    }

    void displayAllComplaints() {
        if (complaints.empty()) {
            cout << "No complaints in system." << endl;
            return;
        }

        cout << "\n=== ALL COMPLAINTS ===" << endl;
        for (Complaint& comp : complaints) {
            comp.display();
        }
        cout << "Total: " << complaints.size() << " complaints" << endl;
    }

    void displayComplaintsByStatus(string status) {
        cout << "\n=== COMPLAINTS WITH STATUS: " << status << " ===" << endl;
        bool found = false;

        for (Complaint& comp : complaints) {
            if (comp.getStatus() == status) {
                comp.display();
                found = true;
            }
        }

        if (!found) {
            cout << "No complaints with status: " << status << endl;
        }
    }
};
#endif