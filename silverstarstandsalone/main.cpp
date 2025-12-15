#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isp(int n) {
    if (n <= 5) return n == 2 || n == 3 || n == 5;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> primes;

    for (int i = 2; i <= 211; ++i) if (isp(i))primes.push_back(i);

    vector<ll> dp(primes.size());
    dp[0] = 1;

    for (int i = 1; i < primes.size(); ++i) {
        dp[i] = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (primes[i] - primes[j] > 14) break;
            dp[i] += dp[j];
        }
    }

    ll p;
    cin >> p;
    int i = find(begin(primes), end(primes), p) - begin(primes);
    cout << dp[i] << endl;
}
