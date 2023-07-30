#include <bits/stdc++.h>
using namespace std;

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

pair<string,string> brute(string x, string y) {
    if (x.length() != y.length())return {"NONE", ""};

    int n = x.length();
    int cnt = 0;
    string la, lb;
    for (int i = 1; i < n; ++i) {
        string a = x.substr(0, i);
        string b = x.substr(i,n);

        if (b + a == y) {
            ++cnt;
            la = a;
            lb = b;
        }
    }

    if (!cnt) {
        return {"NONE", ""};
    } else if (cnt == 1) {
        return {"UNIQUE\n" + la,"\n" + lb};
    } else {
        return {"MANY", ""};
    }
}

bool increment(string& s) {
    int l = s.length();
    for (int i = l - 1; i >= 0; --i) {
        if (s[i] < 'z') {
            ++s[i];
            break;
        } else {
            s[i] = 'a';
            if (i == 0)return true;
        }
    }
    return false;
}

int main() {
    for (int l = 1; ; ++l) {
        cout << "Length: " << l << endl;
        string s(l, 'a');
        string t(l, 'a');
        string nd(l, 'z');

        while (s != nd) {
            while (true) {
                string tst = s+t;
                string sts = t+s;

                if (recover(tst, sts) != brute(tst,sts)) {
                    cout << "Fail on s: " << s << " t: " << t << endl;
                }

                if (increment(t))break;
            }
            if (increment(s))break;
        } 
    }
}
