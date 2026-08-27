#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    stack<int> stk;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        while (stk.size() && a[stk.top()] < a[i]) stk.pop();

        if (stk.size() && a[stk.top()] == a[i]) {
            ans += i - stk.top() - 1;
            stk.pop();
        }
        stk.push(i);
    }
    cout << ans << endl;
}
