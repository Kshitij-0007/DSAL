#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename K, typename V>
class Dict {
    vector<list<pair<K, V>>> table;
    int size;
    int hash(K key) { return key % size; }

public:
    Dict(int s) : size(s), table(s) {}

    void add(K key, V val) {
        int i = hash(key);
        for (auto& p : table[i])
            if (p.first == key) { p.second = val; return; }
        table[i].emplace_back(key, val);
    }

    bool get(K key, V& val) {
        for (auto& p : table[hash(key)])
            if (p.first == key) { val = p.second; return true; }
        return false;
    }

    void del(K key) {
        table[hash(key)].remove_if([&](auto& p) { return p.first == key; });
    }
};

int main() {
    Dict<int, string> d(10);
    d.add(1, "One");
    d.add(2, "Two");
    d.add(3, "Three");

    string val;
    cout << (d.get(2, val) ? "Found: " + val : "Not Found") << endl;

    d.del(2);
    cout << (d.get(2, val) ? "Found: " + val : "Not Found") << endl;

    return 0;
}
