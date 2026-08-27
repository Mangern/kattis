#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void gcd(ll a, ll b, ll k) {
    if (max(a,b)<=k) {
        cout << max(a,b) << " " << min(a,b) << endl;
        exit(0);
    }
    gcd(b,a%b,k);
}

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    k=sqrt(k);
    gcd(a,b,k);
}
