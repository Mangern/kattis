#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)cin >> x;

    vector<ll> ans_take(n);
    vector<ll> ans_free(n);

    ans_take[0] = a[0];
    ans_free[0] = 0;

    for (int i = 1; i < n; ++i) {
        ans_take[i] = a[i] + min(ans_free[i-1], ans_take[i-1]);
        ans_free[i] = ans_take[i-1];
    }

    cout << min(ans_take[n-1], ans_free[n-1]) << endl;
}
