#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int period(ll n) {
    vector<ll> a(n);
    iota(begin(a),end(a),1);
    for (int it = 0; ; ++it) {
        vector<ll> b(n);
        // 0 1 2 3 4
        int p = 0;
        for (int i = 0; i < n/2; ++i) {
            b[p++] = a[n/2+i];
            b[p++] = a[i];
        }
        if(n&1)b[p++]=a[n-1];
        swap(a,b);
        bool s=1;
        for (int i = 1; i < n; ++i) {
            if (a[i]<a[i-1]) {
                s=0;
                break;
            }
        }
        if (s) return it+1;
    }
    assert(false);
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll p = period(n);
    k %= p;
    vector<ll> a(n);
    iota(begin(a),end(a),1);
    for (int it = 0; it < k; ++it) {
        vector<ll> b(n);
        // 0 1 2 3 4
        int p = 0;
        for (int i = 0; i < n/2; ++i) {
            b[p++] = a[n/2+i];
            b[p++] = a[i];
        }
        if(n&1)b[p++]=a[n-1];
        swap(a,b);
    }
    for (auto x : a)cout << x << " ";
    cout << endl;
}
