#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left, right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    shared_ptr<Node> root = nullptr;

    shared_ptr<Node> insert(shared_ptr<Node> n, int val) {
        if (!n) return make_shared<Node>(val);
        val < n->data ? n->left = insert(n->left, val) : n->right = insert(n->right, val);
        return n;
    }

    shared_ptr<Node> search(shared_ptr<Node> n, int key) {
        if (!n || n->data == key) return n;
        return key < n->data ? search(n->left, key) : search(n->right, key);
    }

    int findMin(shared_ptr<Node> n) {
        while (n->left) n = n->left;
        return n->data;
    }

    int depth(shared_ptr<Node> n) {
        if (!n) return 0;
        return 1 + max(depth(n->left), depth(n->right));
    }

    void swapChildren(shared_ptr<Node> n) {
        if (!n) return;
        swap(n->left, n->right);
        swapChildren(n->left);
        swapChildren(n->right);
    }

public:
    void insert(int val) { root = insert(root, val); }
    void searchAndDisplay(int key) {
        cout << (search(root, key) ? "Found " : "Not Found ") << key << '\n';
    }
    void showMin() { cout << "Min: " << findMin(root) << '\n'; }
    void showDepth() { cout << "Longest Path: " << depth(root) << '\n'; }
    void swapTree() { swapChildren(root); }
};

int main() {
    BST t;
    for (int v : {50, 30, 20, 40, 70, 60, 80, 55}) t.insert(v);

    t.showDepth();
    t.showMin();
    t.swapTree();
    t.searchAndDisplay(60);
    t.searchAndDisplay(90);
}
