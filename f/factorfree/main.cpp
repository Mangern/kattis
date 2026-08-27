#include <bits/stdc++.h>
using namespace std;

using ii = array<int,3>;

const int mxN = 1e6+4;

int n;
int a[mxN];
int p[mxN];

const ii ERR = {-1, -1, -1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Return {root, leftmost, rightmost}
ii solve(int l, int r) {
    if (l == r) {
        return {l, l, l};
    }
    if (l + 1 == r) {
        if (gcd(a[l], a[r]) != 1)return ERR;
        p[r] = l;
        return {l, l, r};
    }

    int mid = (l+r)/2;

    ii l_tree = solve(l, mid);
    ii r_tree = solve(mid+1, r);

    if (l_tree[0] == -1 || r_tree[0] == -1)return ERR;

    if (l_tree[0] == mid && r_tree[0] == mid+1) {
        if (gcd(a[mid], a[mid+1]) != 1)return ERR;
        p[mid+1] = mid;
        return {mid, 
    }
}

int main() {
    memset(p, -1, sizeof p);
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> a[i];

    ii ret = solve(0, n - 1);

    if (ret[0] == -1) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; ++i)cout << p[i]+1 << " ";
        cout << endl;
    }
    return 0;
}
