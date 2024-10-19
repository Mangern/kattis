#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const ll BIG = 1000000000000000000;

ll fib[90];

void pre() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 88; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

char solve(ll n, ll k) {
    if (n == 1) return 'N';
    if (n == 2) return 'A';

    if (fib[n-2] > k) {
        return solve(n - 2, k);
    }
    return solve(n - 1, k - fib[n-2]);
}

int main() {
    pre();

    ll n, k;
    cin >> n >> k;

    n = min(n, 88LL);

    --k;
    cout << solve(n, k) << endl;
}
