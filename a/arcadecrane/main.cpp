#include <bits/stdc++.h>
using namespace std;

using state = array<int, 5>;

const int mxN = 1001;
int n;
int a[mxN];
vector<pair<int,int>> ans;

map<state, pair<int, int>> dp;

void do_op(int* a, int n, int f, int t) {
    array<int, 3> vals = {a[f], a[f+1], a[f+2]};
    int ptr = f;
    for (int i = f + 3; i < n; ++i) {
        a[ptr++] = a[i];
    }
    ptr = n - 1 - 3;
    for (int i = n - 1; i > t+2; --i) {
        a[i] = a[ptr--];
    }
    a[t+0] = vals[0];
    a[t+1] = vals[1];
    a[t+2] = vals[2];
}

void bfs() {
    state start = {1,2,3,4,5};
    dp[start] = {-1,-1};
    queue<state> q;
    q.push(start);
    while (q.size()) {
        auto s = q.front();
        q.pop();

        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                state nxt = s;
                do_op(nxt.data(), 5, i, j);
                if (!dp.count(nxt)) {
                    dp[nxt] = {j, i};
                    q.push(nxt);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int big = n; big > 5; --big) {
        int big_idx;
        for (int i = 0; i < n; ++i) {
            if (a[i] == big) {
                big_idx = i;
                break;
            }
        }
        if (big_idx == 0) {
            do_op(a, n, 0, 2);
            ans.push_back({0, 2});
            big_idx = 2;
        } else if (big_idx == 1) {
            do_op(a, n, 0, 1);
            ans.push_back({0, 1});
            big_idx = 2;
        }

        do_op(a, n, big_idx - 2, big - 1 - 2);
        ans.push_back({big_idx - 2, big - 1 - 2});
    }

    bfs();

    for (;;) {
        state ptr = {a[0], a[1], a[2], a[3], a[4]};
        assert(dp.count(ptr));
        auto [f, t] = dp[ptr];
        if (f == -1) break;
        do_op(a, n, f, t);
        ans.push_back({f, t});
    }

    cout << ans.size() << endl;
    for (auto [i, j] : ans)cout << i+1 << " " << j+1 << endl;
}
