#ifndef SMARTBIN_H
#define SMARTBIN_H
#include <string>
#include <iostream>
using namespace std;

class SmartBin {
private:
    string binId;
    string location;
    double fillLevel;
    bool sensorWorking;

public:
    SmartBin(string id, string loc)
        : binId(id), location(loc), fillLevel(0.0), sensorWorking(true) {}

    void updateFillLevel(double level) {
        if (level >= 0 && level <= 100) {
            fillLevel = level;
        }
    }

    bool needsCollection() {
        return fillLevel > 80.0;
    }

    string getId() const { return binId; }
    string getLocation() const { return location; }
    double getFillLevel() const { return fillLevel; }

    void display() const {
        cout << "Bin ID: " << binId << endl;
        cout << "Location: " << location << endl;
        cout << "Fill Level: " << fillLevel << "%" << endl;
        if (fillLevel > 80) {
            cout << "Status: NEEDS COLLECTION" << endl;
        } else if (fillLevel > 60) {
            cout << "Status: Getting full" << endl;
        } else {
            cout << "Status: OK" << endl;
        }
        cout << "------------------------" << endl;
    }
};
#endif