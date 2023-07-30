// WA?????
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 501;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

pair<string,string> recover(string x, string y) {
    if (x.length() != y.length())return {"NONE", ""};
    string oy = y;
    y = x + "$" + y + y;

    vector<int> z_y = z(y);
    int x_l = x.length();

    int cnt = 0;
    int gi = -1;
    for (int i = x_l+2; i < z_y.size(); ++i) {
        int g = z_y[i];
        if (g == x_l) {
            if (i+x_l >= y.length())continue;
            gi = i+x_l;
            ++cnt;
        }
    }
    if (cnt == 0) {
        return {"NONE", ""};
    } else if (cnt > 1) {
        return {"MANY", ""};
    } else {
        string fst = y.substr(gi);
        string lst = y.substr(x.length()+1, x.length() - fst.length());

        if (fst.empty() || lst.empty() || fst+lst != x || lst+fst != oy) {
            return {"NONE", ""};
        } else {
            return {"UNIQUE\n"+fst, "\n"+lst};
        }
    }
}

ll n;

string a[mxN][mxN];
ll s_row[mxN];
ll len[mxN];
ll sm = 0;


int main() {
    cin >> n;


    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        if (i != j)s_row[i] += a[i][j].length();
        sm += a[i][j].length();
    }

    if (n > 2) {
        if ((sm - n)%((n-1)*(n-1)) != 0) {
            cout << "NONE" << endl;
            return 0;
        }

        ll s = (sm-n)/((n-1)*(n-1));

        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            if ((s_row[i] - s) % (n-2) != 0) {
                cout << "NONE" << endl;
                return 0;
            }
            len[i] = (s_row[i] - s) / (n-2);
            if (len[i] <= 0) {
                cout << "NONE" << endl;
                return 0;
            }

            int p = (i == 0 ? 1 : 0);

            ans.push_back(a[i][p].substr(0, len[i]));
        }
        cout << "UNIQUE" << endl;
        for (auto x : ans)cout << x << endl;
        return 0;
    }

    auto res = recover(a[0][1], a[1][0]);
    cout << res.first << res.second << endl;
}
