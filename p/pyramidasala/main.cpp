#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int n, m;
int preorder[mxN];
vector<int> inorder_idx[mxN];
int postorder_idx[mxN];
vector<int> child[mxN];

void search(int pl, int pr, int il, int ir, int par = 0) {
    int root = preorder[pl];

    for (int ptr = pl + 1; ptr <= pr; ) {
        int ch = preorder[ptr];
        child[root].push_back(ch);
        int idx = postorder_idx[ch];
        int take = idx - il + 1;
        search(ptr, ptr + take - 1, il, idx);
        il = idx + 1;
        ptr += take;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    for (int i = 0; i < m; ++i) {
        int j;
        cin >> j;
        inorder_idx[j].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        postorder_idx[x] = i;
    }
    search(0, n - 1, 0, n - 1);

    for (int i = 1; i <= n; ++i) {
        cout << i << ":";
        for (auto c : child[i]) cout << " " << c;
        cout << endl;
    }
}
