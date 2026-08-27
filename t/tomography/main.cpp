#include <bits/stdc++.h>
using namespace std;

const int mxN = 1001;

int n, m;
int r[mxN];
int c[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    sort(r,r+n);
    reverse(r,r+n);
    sort(c,c+m);
    reverse(c,c+m);

    for (int i = 0; i < n; ++i) {
        sort(c,c+m);
        reverse(c,c+m);
        for (int j = 0; j < r[i]; ++j)--c[j];
    }
    for (int j = 0; j < m; ++j)if (c[j] != 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

}

