#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    ll cnt;
    node() { cnt = 0; }
    map<char, node*> nxt;
};

void insert(node* node, const string& s, int i) {
    node->cnt++;
    if (i >= s.length()) return;
    if (node->nxt[s[i]] == 0)node->nxt[s[i]] = new struct node();
    insert(node->nxt[s[i]], s, i + 1);
}

ll query(node* node, const string& s, int i) {
    if (i >= s.length()) return node->cnt;
    auto nxt = node->nxt[s[i]];
    if (nxt == 0) return 0;
    return query(nxt, s, i+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    node *root = new node();
    ll n, q;
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(root, s, 0);
    }

    cin >> q;
    while (q-->0) {
        string s;
        cin >> s;
        cout << query(root, s, 0) << endl;
    }
}
