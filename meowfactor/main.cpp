#include <iostream>
using namespace std;
using ll = long long;
using lll = __int128;

int main() {
    ll n;
    cin >> n;

    ll ans = 1;
    for (lll a = 2; ; ++a) {
        lll x = (a * a * a);
        x = x * x * x; // ans**9

        if (x > n) break;
        if (n % x == 0)ans = a;
    }
    cout << ans << endl;
}
