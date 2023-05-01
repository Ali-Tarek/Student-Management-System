#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H

#include <bits/stdc++.h>

using namespace std;

class student{
private:

    int Id;
    string Name, Dep;
    float Gpa;

public:

    student() = default;

    friend istream& operator>>(istream& in, student& obj) {
        cout << "Id: ";
        in >> obj.Id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, obj.Name);

        cout << "GPA: ";
        in >> obj.Gpa;

        cout << "Department: ";
        in >> obj.Dep;

        return in;
    }

    friend ostream& operator<<(ostream& out, const student& obj) {

        out << '[' << obj.Id << ", " << obj.Name << ", " << obj.Gpa << ", " << obj.Dep << "]\n";
        return out;
    }

    bool operator<(const student& other) const {
        return (Id < other.Id);
    }

    bool operator>(const student& other) const {
        return (Id > other.Id);
    }


};


#endif //MAIN_CPP_STUDENT_H
