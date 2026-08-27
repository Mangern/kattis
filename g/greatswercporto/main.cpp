#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n;
int idx[256];

vector<string> adds;
vector<int> perm;

bool checkadds() {
    for (int i = 0; i < n; ++i) {
        if (perm[idx[(int)adds[i].back()]] == 0) return false;
    }
    int carry = 0;
    for (int col = 0; col < adds[n-1].length(); ++col) {
        int sm = carry;
        for (int i = 0; i < n - 1; ++i) {
            if (col >= adds[i].length())continue;
            sm += perm[idx[(int)adds[i][col]]];
        }
        int v = sm % 10;
        if (v != perm[idx[(int)adds[n-1][col]]]) return false;
        carry = sm / 10;
    }
    return carry == 0;
}

int main() {

    cin >> n;
    adds.resize(n);
    memset(idx, -1, sizeof idx);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> adds[i];

        reverse(begin(adds[i]), end(adds[i]));

        for (char c : adds[i]) {
            if (idx[c] == -1)idx[c] = m++;
        }
    }

    perm.resize(10);
    iota(begin(perm), end(perm), 0);

    int ans = 0;
    do {
        bool bad =0;
        for (int i = m+1; i < 10; ++i) {
            if (perm[i] < perm[i-1])bad=1;
        }
        if (bad) continue;
        if (checkadds()) {
            ++ans;
        }
    } while (next_permutation(begin(perm), end(perm)));
    cout << ans << endl;

    return 0;
}
