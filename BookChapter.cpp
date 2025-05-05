#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name; vector<Node*> children;
    Node(string n) : name(n) {}
    void add(Node* c) { children.push_back(c); }
    void print(int lvl = 0) {
        cout << string(lvl * 2, ' ') << name << '\n';
        for (auto c : children) c->print(lvl + 1);
    }
};

int main() {
    auto input = [](string msg) { cout << msg; string x; getline(cin, x); return x; };
    auto inputInt = [](string msg) { cout << msg; int x; cin >> x; cin.ignore(); return x; };

    Node* book = new Node(input("Enter book name: "));
    int ch = inputInt("Enter number of chapters: ");

    while (ch--) {
        Node* chap = new Node(input("Chapter name: "));
        int sec = inputInt("Number of sections: ");
        while (sec--) {
            Node* section = new Node(input("  Section name: "));
            int sub = inputInt("  Number of subsections: ");
            while (sub--) section->add(new Node(input("    Subsection name: ")));
            chap->add(section);
        }
        book->add(chap);
    }

    book->print();
}
