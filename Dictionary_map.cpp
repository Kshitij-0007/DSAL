#include <iostream>
#include <map>
#include <cmath>
using namespace std;

class Dictionary {
    map<string, string> dictionary;

public:
    void addKeyword(const string& keyword, const string& meaning) {
        dictionary[keyword] = meaning;
    }

    void deleteKeyword(const string& keyword) {
        dictionary.erase(keyword);
    }

    void updateKeyword(const string& keyword, const string& newMeaning) {
        dictionary[keyword] = newMeaning;
    }

    void displayAscending() {
        for (const auto& entry : dictionary) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

    void displayDescending() {
        for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
    }

    int maxComparisons() {
        if (dictionary.empty()) return 0;
        return (int)(log2(dictionary.size()));
    }
};

int main() {
    Dictionary dict;
    dict.addKeyword("apple", "A fruit");
    dict.addKeyword("banana", "Another fruit");
    dict.addKeyword("cherry", "Yet another fruit");

    cout << "Dictionary in ascending order:" << endl;
    dict.displayAscending();

    cout << "\nDictionary in descending order:" << endl;
    dict.displayDescending();
    cout << "\nMax comparisons for finding a keyword: " << dict.maxComparisons() << endl;
    return 0;
}
