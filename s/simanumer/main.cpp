#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    ll cnt;
    node* nxt[10];

    node() {
        cnt = 0;
        for (int i = 0; i < 10; ++i) {
            nxt[i] = 0;
        }
    }
};

void insert(node *n, const string &s, int i = 0) {
    n->cnt++;
    if (i >= s.length()) return;

    int idx = s[i] - '0';
    if (n->nxt[idx] == nullptr) {
        n->nxt[idx] = new node();
    }
    insert(n->nxt[idx], s, i + 1);
}

ll query(node *n, const string &s, int i = 0) {
    if (i >= s.length()) {
        return n->cnt;
    }
    int idx = s[i] - '0';
    if (n->nxt[idx] == nullptr) return 0;
    return query(n->nxt[idx], s, i + 1);
}

int main() {
    node *root = new node();

    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(root, s);
    }

    int q;
    cin >> q;

    while (q-->0) {
        string s;
        cin >> s;
        cout << query(root, s) << endl;
    }
}
