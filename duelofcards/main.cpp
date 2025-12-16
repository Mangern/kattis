#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> have(2*n,0);
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x, --x;
        have[x] = 1;
    }

    sort(begin(a), end(a));

    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int> maxq;

    for (int i = 0; i < 2 * n; ++i) if (!have[i]) {
        minq.push(i);
        maxq.push(i);
    }

    int ansmin = 0;
    int ansmax = 0;

    for (int i = 0; i < n; ++i) {
        while (minq.size() && minq.top() < a[i]) minq.pop();

        if (minq.size()) {
            minq.pop();
        } else ++ansmin;
    }

    for (int i = n - 1; i >= 0; --i) {
        while (maxq.size() && maxq.top() > a[i]) maxq.pop();
        if (maxq.size()) {
            ++ansmax;
            maxq.pop();
        }
    }
    cout << ansmin << " " << ansmax << endl;
}
