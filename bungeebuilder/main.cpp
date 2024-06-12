#include <iostream>
#include <stack>
#include <utility>
using namespace std;
using ii = pair<int,int>;

const int mxN = 1e6+5;

int n;
int a[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i];

    stack<ii> stk;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int mn = a[i];
        while (stk.size() && stk.top().first < a[i]) {
            auto [val, mini] = stk.top();
            stk.pop();
            if (stk.size())stk.top().second = min(stk.top().second, mini);
        }
        if (stk.size()) {
            ans = max(ans, a[i] - stk.top().second);
        }
        stk.push({a[i], a[i]});
    }
    while (stk.size())stk.pop();
    for (int i = n - 1; i >= 0; --i) {
        int mn = a[i];
        while (stk.size() && stk.top().first < a[i]) {
            auto [val, mini] = stk.top();
            stk.pop();
            if (stk.size())stk.top().second = min(stk.top().second, mini);
        }
        if (stk.size()) {
            ans = max(ans, a[i] - stk.top().second);
        }
        stk.push({a[i], a[i]});
    }
    cout << ans << endl;
}
