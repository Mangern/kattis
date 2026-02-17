#include <bits/stdc++.h>
using namespace std;

int AAA = 6969;

// return negative if negated. 0 if v
int getvar() {
    string s;
    if (!(cin >> s))return AAA;
    if (s == "v") return 0;
    if (s[0] == '~') {
        return -(stoi(s.substr(2)));
    }
    if (s[0] != 'X')return AAA + stoi(s);
    return stoi(s.substr(1));
}

int main() {
    int T;
    cin >> T;
    int n, m;
    cin >> n;
    while (T-->0) {
        cin >> m;
        vector<vector<int>> clauses;
        int var = getvar();
        int nn;
        for (int i = 0; i < m; ++i) {
            clauses.emplace_back();
            clauses.back().push_back(var);
            for (;;) {
                int nxt = getvar();
                if (nxt == 0) {
                    var = getvar();
                    clauses.back().push_back(var);
                    continue;
                } else if (nxt >= AAA) {
                    nn = nxt - AAA;
                    break;
                } else {
                    var = nxt;
                    break;
                }
            }
        }

        // cout << n << endl;
        // for (auto c : clauses) {
        //     for (auto x : c) cout << x << " ";
        //     cout << endl;
        // }

        bool ok = 0;
        for (int mask = 0; !ok && mask < (1<<n); ++mask) {
            ok = 1;
            for (const auto &clause : clauses) {
                ok = 0;
                for (int v : clause) {
                    int id = abs(v)-1;
                    int ex = v>0;
                    if (((mask >> id) & 1) == ex) {
                        ok=1;
                        break;
                    }
                }
                if (!ok) break;
            }
        }

        cout << (ok ? "" : "un") << "satisfiable" << endl;

        n=nn;
    }
}
