#include <iostream>
using namespace std;
using ll = long long;

bool win(ll n, ll m) {
    if (n % m == 0) return 1;
    if (n > 2 * m) return 1;
    // m < n < 2 * m
    // -> m, n - m
    return !win(m, n - m);
}

int main() {
    ll n, m;
    cin >> n >> m;
    if (n < m)swap(n, m);
    cout << (win(n, m) ? "win" : "lose") << endl;
}
