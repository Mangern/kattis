#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 1;

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        q.push(a);

        while (a - q.front() >= k) {
            q.pop();
        }

        ans = max(ans, (int)q.size());
    }

    cout << ans << endl;
}
