#include <algorithm>
#include <bits/stdc++.h>
#include <random>
using namespace std;

const int mxN = 1505;

int n;
int tr[mxN];
int a[mxN];
int p[mxN];

int query(int i, int j) {
    i = p[i];
    j = p[j];

    ++i, ++j;
    cout << "? " << i << " " << j << endl;
    int f;
    cin >> f;
    return f;
}

void gen() {
    iota(tr,tr+n, 1);

    for (int i = 1; i < n; ++i) {
        int j = rand() % i;
        swap(tr[i], tr[j]);
    }
}

// 5 1 2 4 3
//
// 6 5 4 3 2 1
//
// 2 1 3 5 4 6
//
// 3 5 1 2 7 4 6

int main() {
    cin >> n;

    mt19937 rng(0);
    iota(p, p+n, 0);
    shuffle(p, p+n, rng);

    int mx = query(0, 1);
    int m1 = 0, m2 = 1;
    for (int i = 2; i < n; ++i) {
        int v = query(m1, i);
        if (v < mx) {
            a[p[i]] = v;
        } else if (v == mx) {
            a[p[m1]] = mx;
            m1 = i;
            mx = query(i, m2);
        } else {
            a[p[m2]] = mx;
            m2 = i;
            mx = v;
        }
    }

    a[p[m1]] = a[p[m2]] = mx;
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}
