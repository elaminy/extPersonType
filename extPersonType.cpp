#include <iostream>
#include <string>

using namespace std;

class personType {
public:
    void print() const {
        cout << firstName << " " << lastName;
    }

    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    personType(string first = "", string last = "") {
        firstName = first;
        lastName = last;
    }

private:
    string firstName;
    string lastName;
};

class dateType {
public:
    void setDate(int month, int day, int year) {
        dMonth = month;
        dDay = day;
        dYear = year;
    }

    int getMonth() const {
        return dMonth;
    }

    int getDay() const {
        return dDay;
    }

    int getYear() const {
        return dYear;
    }

    void printDate() const {
        cout << dMonth << "-" << dDay << "-" << dYear;
    }

    dateType(int month = 1, int day = 1, int year = 1900) {
        setDate(month, day, year);
    }

private:
    int dMonth, dDay, dYear;
};

class addressType {
public:
    void setAddress(string street, string city, string state, string zip) {
        aStreet = street;
        aCity = city;
        aState = state;
        aZip = zip;
    }

    void printAddress() const {
        cout << aStreet << ", " << aCity << ", " << aState << " " << aZip;
    }

    addressType(string street = "", string city = "", string state = "", string zip = "") {
        setAddress(street, city, state, zip);
    }

private:
    string aStreet, aCity, aState, aZip;
};

class extPersonType : public personType {
public:
    void setInfo(string first, string last, string street, string city, string state, string zip, int month, int day, int year, string phone, string relation) {
        setName(first, last);
        address.setAddress(street, city, state, zip);
        birthDate.setDate(month, day, year);
        setPhoneNumber(phone);
        setRelationship(relation);
    }

    void printInfo() const {
        print(); // Call personType's print
        cout << endl;
        birthDate.printDate();
        cout << endl;
        address.printAddress();
        cout << endl;
        cout << phoneNumber << endl;
        cout << relationship;
    }

    bool isBirthday(int month) const {
        return birthDate.getMonth() == month;
    }

    void setRelationship(string relation) {
        if (relation == "Family" || relation == "Friend" || relation == "Business") {
            relationship = relation;
        }
        else {
            relationship = "Friend"; // Default or an error handler could be here
        }
    }

    string getRelationship() const {
        return relationship;
    }

    void setPhoneNumber(string phone) {
        phoneNumber = phone;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    extPersonType(string first = "", string last = "", string street = "", string city = "", string state = "", string zip = "", int month = 1, int day = 1, int year = 1900, string phone = "", string relation = "Friend")
        : personType(first, last), birthDate(month, day, year), address(street, city, state, zip), phoneNumber(phone), relationship(relation) {}

private:
    addressType address;
    dateType birthDate;
    string phoneNumber;
    string relationship;
};

int main() {
    // Example usage
    extPersonType person("John", "Doe", "123 Main St", "Anytown", "Anystate", "12345", 1, 1, 1990, "555-1234", "Friend");
    person.printInfo();

    return 0;
}
