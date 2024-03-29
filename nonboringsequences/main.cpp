#include <bits/stdc++.h>
using namespace std;

const int mxN = 200005;

int a[mxN];
int nxt[mxN];
int prv[mxN];

inline bool uniq(int i, int l, int r) {
    return prv[i] < l && nxt[i] > r;
}

bool search(int l, int r) {
    if (l >= r)return false;

    int i = l;
    int j = r;
    int midx = -1;

    while (i <= j) {
        if (uniq(i, l, r)) {
            midx = i;
            break;
        }
        if (uniq(j, l, r)) {
            midx = j;
            break;
        }
        ++i;
        --j;
    }

    if (midx == -1)return true;
    if (search(l, midx-1))return true;
    if (search(midx+1, r))return true;
    return false;
}

void testcase() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (auto& x : b)cin >> x;
    map<int,int> remap;
    int tim = 0;

    for (int i = 0; i < n; ++i) {
        if (!remap.count(b[i])) {
            remap[b[i]] = tim++;
        }
        a[i] = remap[b[i]];
    }

    vector<int> idx(n, -1);

    for (int i = 0; i < n; ++i) {
        prv[i] = idx[a[i]];
        idx[a[i]] = i;
    }

    idx = vector<int>(n, n);
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = idx[a[i]];
        idx[a[i]] = i;
    }

    if (search(0, n - 1)) {
        cout << "boring" << endl;
    } else {
        cout << "non-boring" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t-->0)testcase();
}
