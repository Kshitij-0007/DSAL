#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> phoneBook;
    int n;
    cout << "Enter the number of entries: ";
    cin >> n;

    cout << "Enter name and phone number pairs:\n";
    for (int i = 0; i < n; i++) {
        string name, number;
        cin >> name >> number;
        phoneBook[name] = number;
    }

    cout << "Enter names to search (type 'exit' to stop):\n";
    string query;
    while (cin >> query && query != "exit") {
        if (phoneBook.find(query) != phoneBook.end()) {
            cout << query << " -> " << phoneBook[query] << endl;
        } else {
            cout << query << " not found" << endl;
        }
    }

    return 0;
}
