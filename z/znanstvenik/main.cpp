#include <bits/stdc++.h>
using namespace std;

struct node {
    node* parent;
    node* nxt[26];

    node() : parent{0} {
        memset(nxt, 0, sizeof nxt);
    }
};

node* insert(node* n, const string& s, int i = 0) {
    if (i == s.length()) {
        return n;
    }

    if (n->nxt[s[i] - 'a'] == 0) {
        n->nxt[s[i] - 'a'] = new node();
        n->nxt[s[i] - 'a']->parent = n;
    }
    return insert(n->nxt[s[i] - 'a'], s, i+1);
}

int main() {
    node* root = new node{};

    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (auto &s: grid) cin >> s;

    vector<node*> leafs;
    for (int j = 0; j < c; ++j) {
        string s;
        for (int i = r - 1; i >= 0; --i) {
            s.push_back(grid[i][j]);
        }
        leafs.push_back(insert(root, s));
    }

    for (int i = 0; i < r; ++i) {
        vector<node*> nleaf;

        for (auto ptr : leafs) {
            nleaf.push_back(ptr->parent);
        }

        sort(begin(nleaf), end(nleaf));

        for (int j = 1; j < c; ++j) {
            if (nleaf[j-1] == nleaf[j]) {
                cout << i << endl;
                return 0;
            }
        }

        swap(leafs, nleaf);
    }
}
