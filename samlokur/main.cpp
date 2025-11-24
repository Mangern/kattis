#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);

    sort(begin(idx), end(idx), [&](auto i, auto j) {
        return b[i] < b[j];
    });

    queue<int> big;
    queue<int> smol;

    for (int i : idx) {
        if (a[i] == 4) {
            smol.push(i);
        } else if (a[i] > 4) {
            big.push(i);
        }
    }

    for (int i = 0; i < k; ++i) {
        while (smol.size() && b[smol.front()] <= i)smol.pop();
        while (big.size() && b[big.front()] <= i)big.pop();
        if (big.empty()) {
            return 0;
        }
        if (smol.empty()) {
            big.pop();
            if (big.empty())return 0;
            big.pop();
            continue;
        }

        if (b[big.front()] < b[smol.front()]) {
            big.pop();
            if (big.size() > smol.size() && b[big.front()] < b[smol.front()]) {
                big.pop();
                continue;
            }
            smol.pop();
            continue;
        }

        smol.pop();
        big.pop();
    }

    return 1;
}

int main() {
    cout << (solve() ? "Jebb" : "Neibb") << endl;
}
