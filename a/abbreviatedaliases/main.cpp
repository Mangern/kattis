#include <bits/stdc++.h>
using namespace std;


struct node {
    int count;
    map<char, node*> next;

    node() {
        count = 0;
    }
};

void insert(node* n, const string& s, int i = 0) {
    ++n->count;
    if (i == s.length()) {
        return;
    }

    if (!n->next.count(s[i])) {
        n->next[s[i]] = new node{};
    }
    insert(n->next[s[i]], s, i + 1);
}

int mlen(node* n, const string& s, int i = 0) {
    if (n->count == 1) {
        return i;
    }
    assert(i < s.length());
    return mlen(n->next[s[i]], s, i + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    node* root = new node{};

    int n, l;
    cin >> n >> l;

    vector<string> strs(n);
    for (auto &s : strs) {
        cin >> s;
        insert(root, s);
    }

    int ans = 0;

    for (const auto& s : strs) {
        ans += mlen(root, s);
    }
    cout << ans << endl;
}
