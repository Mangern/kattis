#include <bits/stdc++.h>
using namespace std;

int id[256];
string order = "ATGC";

vector<int> pf[4];

int main() {
    id['A'] = 0;
    id['T'] = 1;
    id['G'] = 2;
    id['C'] = 3;

    string s;
    cin >> s;

    pf[0].push_back(0);
    pf[1].push_back(0);
    pf[2].push_back(0);
    pf[3].push_back(0);

    for (char c : s) {
        for (int i = 0; i < 4; ++i) {
            pf[i].push_back(pf[i].back() + (id[c] == i));
        }
    }

    int q;
    cin >> q;
    pair<int,int> prs[4];
    while (q-->0) {
        int l, r;
        cin >> l >> r, --l;
        for (int i = 0; i < 4; ++i) {
            prs[i] = {pf[i][l] - pf[i][r], i};
        }
        sort(prs, prs+4);
        for (int i = 0; i < 4; ++i) {
            cout << order[prs[i].second];
        }
        cout << '\n';
    }
}
