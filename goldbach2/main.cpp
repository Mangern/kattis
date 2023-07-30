#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 32005;

vector<int> primes;
bool is_prime[mxN];

void sieve() {
    memset(is_prime, 1, sizeof is_prime);

    is_prime[0] = 0;
    is_prime[1] = 0;

    for (ll i = 2; i < mxN; ++i) {
        if (!is_prime[i])continue;
        primes.push_back(i);

        for (ll j = i * i; j < mxN; j += i) {
            is_prime[j] = 0;
        }
    }
}

int main() {
    sieve();
    int TC;
    cin >> TC;

    while (TC-->0) {
        int n;
        cin >> n;

        vector<array<int,2>> ans;
        for (auto p : primes) {
            if (2 * p > n)break;
            if (is_prime[n-p])ans.push_back({p,n-p});
        }
        cout << n << " has " << ans.size() << " representation(s)" << endl;

        for (auto [a, b] : ans)cout << a << "+" << b << endl;
        cout << endl;
    }
}
