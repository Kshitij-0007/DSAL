#include <iostream>
#include <string>
using namespace std;
struct Node {
    string k, m; Node *l, *r;
    Node(string key, string mean) : k(key), m(mean), l(r = nullptr) {}
};
class Dict {
    Node* root = nullptr;
    Node* insert(Node* n, string k, string m) {
        if (!n) return new Node(k, m);
        if (k < n->k) n->l = insert(n->l, k, m);
        else if (k > n->k) n->r = insert(n->r, k, m);
        return n;
    }
    Node* minNode(Node* n) { while (n && n->l) n = n->l; return n; }
    Node* del(Node* n, string k) {
        if (!n) return nullptr;
        if (k < n->k) n->l = del(n->l, k);
        else if (k > n->k) n->r = del(n->r, k);
        else {
            if (!n->l) { Node* t = n->r; delete n; return t; }
            if (!n->r) { Node* t = n->l; delete n; return t; }
            Node* t = minNode(n->r);
            n->k = t->k; n->m = t->m;
            n->r = del(n->r, t->k);
        }
        return n;
    }
    Node* update(Node* n, string k, string m) {
        if (!n) return nullptr;
        if (k < n->k) n->l = update(n->l, k, m);
        else if (k > n->k) n->r = update(n->r, k, m);
        else n->m = m;
        return n;
    }
    void show(Node* n, bool asc) {
        if (!n) return;
        show(asc ? n->l : n->r, asc);
        cout << n->k << ": " << n->m << endl;
        show(asc ? n->r : n->l, asc);
    }
    int comps(Node* n, string k, int c) {
        if (!n) return c;
        if (k == n->k) return c + 1;
        return comps(k < n->k ? n->l : n->r, k, c + 1);
    }
public:
    void add(string k, string m) { root = insert(root, k, m); }
    void del(string k) { root = del(root, k); }
    void upd(string k, string m) { root = update(root, k, m); }
    void disp(bool asc) { show(root, asc); }
    int maxCmp(string k) { return comps(root, k, 0); }
};

int main() {
    Dict d; int c; string k, m;
    do {
        cout << "1.Add 2.Del 3.Upd 4.Asc 5.Desc 6.Cmp 7.Exit\nChoice: "; cin >> c;
        if (c == 1 || c == 3) { cout << "Key: "; cin >> k; cout << "Meaning: "; cin.ignore(); getline(cin, m); (c == 1 ? d.add(k, m) : d.upd(k, m)); }
        else if (c == 2) { cout << "Key: "; cin >> k; d.del(k); }
        else if (c == 4) d.disp(true);
        else if (c == 5) d.disp(false);
        else if (c == 6) { cout << "Key: "; cin >> k; cout << "Comparisons: " << d.maxCmp(k) << endl; }
    } while (c != 7);
    return 0;
}
