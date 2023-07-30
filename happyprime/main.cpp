#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 50000;

bool is_prime[mxN];
bool vis[mxN];
bool is_happy[mxN];

void sieve() {
    memset(is_prime,1,sizeof is_prime);

    is_prime[0] = 0;
    is_prime[1] = 0;

    for (ll i = 2; i < mxN; ++i) {
        if (!is_prime[i])continue;
        for (ll j = i * i; j < mxN; j += i) {
            is_prime[j] = false;
        }
    }
}

bool happy(ll n) {
    if (vis[n]) {
        return is_happy[n];
    }
    ll save_n = n;

    ll s_dig = 0;
    while (n) {
        s_dig += (n%10)*(n%10);
        n /= 10;
    }
    vis[save_n] = 1;
    is_happy[save_n] = happy(s_dig);
    return is_happy[save_n];
}

int main() {
    sieve();
    vis[1] = 1;
    is_happy[1] = 1;
    int tc;
    cin >> tc;
    while (tc-->0) {
        int k,m;
        cin >> k >> m;
        cout << k << " " << m << " ";

        if (is_prime[m] && happy(m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
