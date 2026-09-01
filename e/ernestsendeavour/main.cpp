#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5+5;
int p[mxN];
int rnk[mxN];
array<int,2> orig[mxN];

int find(int i) {
    return p[i] == i ? i : (p[i] = find(p[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return;
    if (rnk[i] > rnk[j]) {
        p[j] = i;
        if (orig[j][0] != -1)orig[i][0] = orig[j][0];
        if (orig[j][1] != -1)orig[i][1] = orig[j][1];
    } else {
        p[i] = j;
        if (orig[i][0] != -1)orig[j][0] = orig[i][0];
        if (orig[i][1] != -1)orig[j][1] = orig[i][1];
        if (rnk[i] == rnk[j]) {
            ++rnk[j];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        int k;
        cin >> k;
        if (k == 1) orig[i] = {i, -1};
        else if (k == 2) orig[i] = {-1, i};
        else orig[i] = {-1, -1};
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        join(u,v);
    }

    for (int i = 0; i < n; ++i) if (find(i) == i) {
        if (orig[i][0] != -1 && orig[i][1] != -1) {
            cout << orig[i][0]+1 << " " << orig[i][1]+1 << endl;
            return 0;
        }
    }

    cout << "safe" << endl;
}
