#include <bits/stdc++.h>
using namespace std;

bool isvow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check(const string &a, const string &b) {
    int ndiff = 0;
    for (int i = 0; i < 4; ++i) {
        ndiff += a[i] != b[i];
    }
    return ndiff > 1;
}

int main() {
    string vow;
    string con;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (isvow(c)) {
            vow.push_back(c);
        } else con.push_back(c);
    }
    vector<string> words;
    for (char v1 : vow) for (char v2 : vow) {
        for (char c1 : con) for (char c2 : con) {
            string s(4,'?');
            s[0] = v1;
            s[1] = v2;
            s[2] = c1;
            s[3] = c2;
            words.push_back(s);
        }
    }
    cerr << "Generated " << words.size() << " words" << endl;
    int n = words.size();
    vector<string> ans_compressed;
    vector<string> ans;

    int step = 1;
    for (char v1 : vow) for (char v2 : vow) {
        for (int i = 0; i < con.size(); ++i) {
            char c1 = con[i];
            char c2 = con[(i+step)%con.size()];
            string s(4, '?');
            s[0] = v1;
            s[1] = v2;
            s[2] = c1;
            s[3] = c2;
            ans_compressed.push_back(s);
        }

        ++step;
    }

    for (int i = 1; i < ans_compressed.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            bool b = check(ans_compressed[i], ans_compressed[j]);
            if (!b) {
                cerr << ans_compressed[i] << " " << ans_compressed[j] << endl;
            }
            assert(b);
        }
    }

    for (int mask = 0; mask < 16; ++mask) {
        if (__builtin_popcount(mask) != 2) continue;
        for (string s : ans_compressed) {
            string t(4, '?');
            int vp = 0;
            int cp = 2;
            for (int i = 0; i < 4; ++i) {
                if ((mask >> i) & 1) {
                    t[i] = s[vp++];
                } else {
                    t[i] = s[cp++];
                }
            }
            ans.push_back(t);
        }
    }

    cerr << ans.size() << endl;

    cout << "ans = [";
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0)cout << ",";
        cout << "\"" << ans[i] << "\"";
    }
    cout << "]" << endl;
    cout << "print(len(ans))" << endl;
    cout << "print(\"\\n\".join(ans))" << endl;
}
