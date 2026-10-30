#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    map<string, int> m;
    map<int, string> m2;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m.count(s) == 0) {
            m2[m.size()] = s;
            m[s] = m.size();
        }
        v.push_back(m[s]);
    }

    for (int i = m.size(); i < k; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string s = string(1, c);
            if (m.count(s) == 0){ 
                m[s] = i;
                m2[i] = s;
                break;
            }
        }
    }

    vector<vector<int>> e(k, vector<int>(k, 0));
    int prev = v[0];
    for (int i = 1; i < n; i++) {
        e[prev][v[i]]++;
        e[v[i]][prev]++;
        prev = v[i];
    }

    for (int i = 0; i < k; i++) {
        e[i][i] = 0;
    }

    vector<vector<int>> by_count(k+1);
    for (int i = 0; i < (1 << k); i++) {
        int c = 0;
        for (int j = 0; j < k; j++) {
            if ((1 << j) & i) c++;
        }
        by_count[c].push_back(i);
    }

    vector<int> dp(1 << k, -1);
    vector<int> prevl(1 << k);
    vector<int> unconnected(1 << k);
    for (int c = 0; c < k; c++) {
        for (int i : by_count[c]) {
            //cout << i << " " << dp[i] << endl;
            int u = unconnected[i];
            
            for (int b = 0; b < k; b++) {
                if ((1 << b)&i) continue;
                int con = 0;
                int uncon = 0;
                for (int a = 0; a < k; a++) {
                    if (a==b) continue;
                    if (((1<<a)&i)) {
                        con += e[a][b];
                    } else {
                        uncon += e[a][b];
                    }
                }
                int j = i | (1 << b);
                unconnected[j] = u - con + uncon;
                if (dp[i]+u <= dp[j] || dp[j] == -1) {
                    dp[j] = dp[i] + u;
                    prevl[j] = b;
                }
            }

        }
    }


    int s = (1 << k)-1;
    vector<string> res;
    for (int i = 0; i < k; i++) {
        int b = prevl[s];
        res.push_back(m2[b]);
        s ^= 1 << b;
    }

    reverse(res.begin(), res.end());
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";
}
