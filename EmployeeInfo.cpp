#include <bits/stdc++.h>
using namespace std;

struct Employee {
    int id; char name[50], role[50]; double salary;
};

vector<Employee> emps;

void load() {
    ifstream in("employees.dat", ios::binary);
    if (!in) return;
    Employee e;
    while (in.read((char*)&e, sizeof(e))) emps.push_back(e);
}

void save() {
    ofstream out("employees.dat", ios::binary | ios::trunc);
    for (auto& e : emps) out.write((char*)&e, sizeof(e));
}

void add() {
    Employee e;
    cout << "ID: "; cin >> e.id; cin.ignore();
    cout << "Name: "; cin.getline(e.name, 50);
    cout << "Role: "; cin.getline(e.role, 50);
    cout << "Salary: "; cin >> e.salary;
    emps.push_back(e);
    sort(emps.begin(), emps.end(), [](auto& a, auto& b){ return a.id < b.id; });
    save(); cout << "Added.\n";
}

void removeEmp() {
    int id; cout << "ID to delete: "; cin >> id;
    auto it = remove_if(emps.begin(), emps.end(), [id](auto& e){ return e.id == id; });
    if (it == emps.end()) return void(cout << "Not found.\n");
    emps.erase(it, emps.end()); save(); cout << "Deleted.\n";
}

void search() {
    int id; cout << "ID to search: "; cin >> id;
    auto it = lower_bound(emps.begin(), emps.end(), id, [](auto& e, int k){ return e.id < k; });
    if (it != emps.end() && it->id == id)
        cout << "ID: " << it->id << "\nName: " << it->name << "\nRole: " << it->role << "\nSalary: " << it->salary << '\n';
    else cout << "Not found.\n";
}

int main() {
    load(); int ch;
    do {
        cout << "\n1.Add 2.Delete 3.Search 4.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: add(); break;
            case 2: removeEmp(); break;
            case 3: search(); break;
            case 4: cout << "Bye!\n"; break;
            default: cout << "Invalid\n";
        }
    } while (ch != 4);
}
