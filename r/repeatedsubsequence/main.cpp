#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> idx(26, -1);
    vector<int> prv(n, -1);

    int mini = -1;
    int minl = n + 2;
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (idx[c] != -1) {
            prv[i] = idx[c];

            if (i - prv[i] < minl) {
                mini = i;
                minl = i - prv[i];
            }
        }
        idx[c] = i;
    }
    if (mini == -1) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < prv[mini]; ++i) {
        cout << s[i];
    }
    for (int i = mini; i < n; ++i)cout << s[i];
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0)solve();
}
