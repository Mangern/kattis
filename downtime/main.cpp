#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ll ans = 1;
    ll n, k;
    cin >> n >> k;

    queue<ll> q;

    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;

        while (q.size() && t - q.front() >= 1000) {
            q.pop();
        }
        q.push(t);

        while (ans * k < q.size())++ans;
    }
    cout << ans << endl;
}
