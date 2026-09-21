#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool check(const string& s) {
    int n = s.length();

    vector<int> cnt_lft(n,0), cnt_rgt(n,0);

    for (int i = 1; i < n; ++i) {
        cnt_lft[i] = cnt_lft[i-1] + (s[i-1] == '>');
    }
    for (int i = n - 2; i >= 0; --i) {
        cnt_rgt[i] = cnt_rgt[i+1] + (s[i+1] == '<');
    }

    for (int i = 0; i < n; ++i) {
        if (cnt_lft[i] + cnt_rgt[i] != a[i]) {
            return false;
        }
    }
    return true;
}

void fail() {
    cout << "impossible" << endl;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;

    string res(n, '?');

    queue<int> q;
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i-1]) > 1) {
            fail();
        }
        if (q.empty() && a[i] - a[i-1] == 1) {
            res[i] = '>';
            q.push(i);
        } else if (q.empty() && a[i-1] - a[i] == 1) {
            res[i] = '<';
            q.push(i);
        }
    }

    if (q.empty()) {
        for (int i = 0; i < n; ++i) {
            res[i] = "<>"[i&1];
        }
        if (check(res)) {
            cout << "possible" << endl;
            cout << res << endl;
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            res[i] = "><"[i&1];
        }
        if (check(res)) {
            cout << "possible" << endl;
            cout << res << endl;
            return 0;
        }
        fail();
    }

    while (q.size()) {
        int i = q.front();
        q.pop();

        if (i > 0 && res[i-1] == '?') {
            if (res[i] == '<') {
                if (a[i-1] > a[i]) {
                    res[i-1] = '<';
                    q.push(i-1);
                } else if (a[i-1] == a[i]) {
                    res[i-1] = '>';
                    q.push(i-1);
                } else {
                    fail();
                }
            } else { // if res[i] == '>'
                if (a[i-1] > a[i]) {
                    fail();
                } else if (a[i-1] == a[i]) {
                    res[i-1] = '<';
                    q.push(i-1);
                } else {
                    res[i-1] = '>';
                    q.push(i-1);
                }
            }
        }

        if (i + 1 < n && res[i+1] == '?') {
            if (res[i] == '<') {
                if (a[i+1] > a[i]) {
                    fail();
                } else if (a[i+1] == a[i]) {
                    res[i+1] = '>';
                    q.push(i+1);
                } else {
                    res[i+1] = '<';
                    q.push(i+1);
                }
            } else { // if res[i] == '>'
                if (a[i+1] > a[i]) {
                    res[i+1] = '>';
                    q.push(i+1);
                } else if (a[i+1] == a[i]) {
                    res[i+1] = '<';
                    q.push(i+1);
                } else {
                    fail();
                }
            }
        }
    }
    if (check(res)) {
        cout << "possible" << endl;
        cout << res << endl;
        return 0;
    }
    fail();
}
