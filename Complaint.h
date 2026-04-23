#ifndef COMPLAINT_H
#define COMPLAINT_H
#include<iostream>
#include <string>
using namespace std;
class Complaint {
private:
    int complaintId;
    string description;
    string submittedBy;
    string assignedTo;
    string status;

public:
    Complaint(int id, string desc, string citizen)
        : complaintId(id), description(desc),
          submittedBy(citizen), assignedTo("Not assigned"),
          status("Submitted") {}

    void assignTo(string techName) {
        assignedTo = techName;
        status = "Assigned";
        cout << "Complaint #" << complaintId << " assigned to " << techName << endl;
    }

    void resolve() {
        status = "Resolved";
        cout << "Complaint #" << complaintId << " resolved!" << endl;
    }

    int getId() const { return complaintId; }
    string getDescription() const { return description; }
    string getStatus() const { return status; }
    string getSubmittedBy() const { return submittedBy; }
    string getAssignedTo() const { return assignedTo; }

    void display() const {
        cout << "\nComplaint #" << complaintId << endl;
        cout << "Description: " << description << endl;
        cout << "Submitted by: " << submittedBy << endl;
        cout << "Assigned to: " << assignedTo << endl;
        cout << "Status: " << status << endl;
    }
};
#endif