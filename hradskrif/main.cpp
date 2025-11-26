#include <bits/stdc++.h>
using namespace std;

struct node {
    map<char,node*> nxt;
    int cnt;
    int ends;

    node() {
        cnt = 0;
        ends = 0;
    }
};

node *root;

void insert(node *ptr, const string &s, int idx = 0) {
    ++ptr->cnt;
    if (idx == s.length()) {
        ++(ptr->ends);
        return;
    }
    node*& nxt = ptr->nxt[s[idx]];
    if (nxt == 0) {
        nxt = new node();
    }
    insert(nxt, s, idx + 1);
}

bool has(node *ptr, const string &s, int idx = 0) {
    if (idx == s.length()) return ptr->ends;
    node *nxt = ptr->nxt[s[idx]];
    if (!nxt)return false;
    return has(nxt, s, idx+1);
}

// shortest way to type s[idx:] starting at ptr
int shortest(node *ptr, const string &s, int idx = 0) {
    if (idx == s.length()) return 0;
    if (ptr->cnt == 1) return 1;
    node *nxt = ptr->nxt[s[idx]];
    return 1 + shortest(nxt, s, idx + 1);
}

int main() {
    int n;
    cin >> n;
    root = new node();
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        string &s = a[i];
        cin >> s;
        if (has(root,s)) continue;
        insert(root, s);
    }

    int ans = 0;
    for (const string &s : a) {
        ans += s.length() - shortest(root, s);
    }

    cout << ans << endl;
}
