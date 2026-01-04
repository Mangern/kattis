#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e7;

int dist[mxN];

#define trans(n) ((n)%2==0?(n/2):(3*(n)+1))

int getdist(ll n) {
    if (n >= mxN) {
        return 1 + getdist(trans(n));
    }
    int &r = dist[n];
    if (r != -1) return r;
    if (n == 1) return r = 0;
    return r = 1 + getdist(trans(n));
}

int main() {
    memset(dist, -1, sizeof dist);

    int ans = 0;
    dist[0] = 0;

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        if (getdist(i)>dist[ans]) {
            ans=i;
        }
    }
    cout << ans << endl;
}
