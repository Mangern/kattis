#include <bits/stdc++.h>
using namespace std;

struct node {
    char data;
    node *lft, *rgt;
    node(char c) { data = c; lft=0; rgt=0; }
};

void insert(node*& n, char c) {
    if (n == 0) {
        n = new node(c);
        return;
    }

    if (c < n->data)insert(n->lft, c);
    else insert(n->rgt, c);
}

void preorder(node* n) {
    if (!n) return;
    cout << n->data;
    preorder(n->lft);
    preorder(n->rgt);
    delete n;
}

int main() {
    for (;;) {
        vector<string> ops;

        string s;
        while (true) {
            cin >> s;
            if (s[0] == '*' || s[0] == '$') break;
            ops.push_back(s);
        }

        node *root = 0;

        for (int i = ops.size() - 1; i >= 0; --i) {
            for (char c : ops[i])insert(root, c);
        }

        preorder(root);
        cout << "\n";

        if (s[0] == '$') break;
    }
}
