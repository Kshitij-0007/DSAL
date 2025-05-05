#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<vector<int>>& root, int i, int j, vector<int>& keys) {
    if (i > j) return nullptr;
    Node* node = new Node(keys[root[i][j]]);
    node->left = buildTree(root, i, root[i][j] - 1, keys);
    node->right = buildTree(root, root[i][j] + 1, j, keys);
    return node;
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (!root) return;
    space += height;
    printTree(root->right, space);
    for (int i = height; i < space; i++) cout << " ";
    cout << root->key << "\n";
    printTree(root->left, space);
}

float optimalBST(vector<int>& keys, vector<float>& p, int n, vector<vector<int>>& root) {
    vector<vector<float>> cost(n, vector<float>(n, 0));
    vector<vector<float>> sum(n, vector<float>(n, 0));

    for (int i = 0; i < n; i++) {
        cost[i][i] = p[i];
        sum[i][i] = p[i];
        root[i][i] = i;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = numeric_limits<float>::max();
            sum[i][j] = sum[i][j - 1] + p[j];

            for (int r = i; r <= j; r++) {
                float c = (r > i ? cost[i][r - 1] : 0) + 
                          (r < j ? cost[r + 1][j] : 0) + 
                          sum[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    vector<int> keys = {10, 20, 30, 40};
    vector<float> p = {0.1, 0.2, 0.4, 0.3};
    int n = keys.size();

    vector<vector<int>> root(n, vector<int>(n, 0));

    cout << "Optimal BST Cost: " << optimalBST(keys, p, n, root) << endl;

    Node* bstRoot = buildTree(root, 0, n - 1, keys);

    cout << "Tree Structure:\n";
    printTree(bstRoot);

    return 0;
}
