#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

void load() {
    ifstream f("contacts.txt");
    Contact c;
    while (getline(f, c.name)) {
        getline(f, c.phone);
        getline(f, c.email);
        contacts.push_back(c);
    }
}

void save() {
    ofstream f("contacts.txt");
    for (auto &c : contacts) {
        f << c.name << "\n" << c.phone << "\n" << c.email << "\n";
    }
}

void addContact() {
    Contact c;
    cout << "Name: ";
    getline(cin, c.name);
    cout << "Phone: ";
    getline(cin, c.phone);
    cout << "Email: ";
    getline(cin, c.email);
    contacts.push_back(c);
    save();
}

void listContacts() {
    if (contacts.empty()) {
        cout << "No contacts.\n";
        return;
    }
    for (int i = 0; i < contacts.size(); i++) {
        cout << i+1 << ". " << contacts[i].name << " | " 
             << contacts[i].phone << " | " << contacts[i].email << "\n";
    }
}

void searchContact() {
    string key;
    cout << "Search name: ";
    getline(cin, key);
    for (auto &c : contacts) {
        if (c.name.find(key) != string::npos) {
            cout << c.name << " | " << c.phone << " | " << c.email << "\n";
        }
    }
}

void deleteContact() {
    listContacts();
    if (contacts.empty()) return;
    cout << "Delete number: ";
    int n;
    cin >> n;
    cin.ignore();
    if (n > 0 && n <= contacts.size()) {
        contacts.erase(contacts.begin() + (n - 1));
        save();
        cout << "Deleted.\n";
    }
}

int main() {
    load();
    while (true) {
        cout << "\n1.Add\n2.List\n3.Search\n4.Delete\n5.Exit\nChoice: ";
        int c;
        cin >> c;
        cin.ignore();
        if (c == 1) addContact();
        else if (c == 2) listContacts();
        else if (c == 3) searchContact();
        else if (c == 4) deleteContact();
        else if (c == 5) break;
    }
    return 0;
}
