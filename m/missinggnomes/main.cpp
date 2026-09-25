#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> rem;
    vector<int> ans;
    int n, m;
    cin >> n >> m;

    deque<int> que;

    for (int i = 1; i<= n; ++i)rem.insert(i);

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        rem.erase(x);
        que.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        if (rem.empty()) {
            ans.push_back(que.front());
            que.pop_front();
        } else if (que.empty()) {
            ans.push_back(*rem.begin());
            rem.erase(rem.begin());
        } else {
            if (*rem.begin() < que.front()) {
                ans.push_back(*rem.begin());
                rem.erase(rem.begin());
            } else {
                ans.push_back(que.front());
                que.pop_front();
            }
        }
    }
    for (auto x : ans)cout << x << endl;
}
