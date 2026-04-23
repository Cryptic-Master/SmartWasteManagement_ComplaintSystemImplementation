#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User {
protected:
    int userId;
    string name;
    string username;
    string password;

public:
    User(int id, string n, string uname, string pwd)
        : userId(id), name(n), username(uname), password(pwd) {}

    virtual ~User() {}

    bool login(string uname, string pwd) {
        return (username == uname && password == pwd);
    }

    virtual string getRole() const = 0;
    int getId() const { return userId; }
    string getName() const { return name; }
};

class Citizen : public User {
public:
    Citizen(int id, string n, string uname, string pwd)
        : User(id, n, uname, pwd) {}

    string getRole() const override {
        return "Citizen";
    }
};
class Driver : public User {
public:
    Driver(int id, string n, string uname, string pwd)
        : User(id, n, uname, pwd) {}

    string getRole() const override {
        return "Driver";
    }
};
class Technician : public User {
public:
    Technician(int id, string n, string uname, string pwd)
        : User(id, n, uname, pwd) {}

    string getRole() const override {
        return "Technician";
    }
};
#endif