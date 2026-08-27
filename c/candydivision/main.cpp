#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;


    set<ll> ans;
    for (ll i = 1; i <= n; ++i) {
        if (i * i > n)break;
        if (n % i != 0)continue;

        ans.insert(i - 1);
        ans.insert(n / i - 1);
    }

    for (auto x : ans)cout << x << " ";
    cout << endl;
}
