#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> q;

    for (int i = 0; i < n; ++i)q.push_back(i);

    vector<int> ans(n);
    int p = 1;

    while (q.size()) {
        for (int i= 0; i < p; ++i) {
            q.push_back(q.front());
            q.pop_front();
        }
        ans[q.front()] = p;
        q.pop_front();
        ++p;
    }
    for (auto x : ans)cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)solve();
}
