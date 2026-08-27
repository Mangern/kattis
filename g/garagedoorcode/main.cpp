#include <bits/stdc++.h>
using namespace std;

string cur;
void gen(const string& s, int i, int k, set<string> &ret) {
    if (k == 0) {
        ret.insert(cur);
        return;
    }
    if (i >= s.length()) return;
    cur.push_back(s[i]);
    gen(s, i+1, k - 1, ret);
    cur.pop_back();
    gen(s, i+1, k, ret);
}

int main() {
    int k, n;
    cin >> k >> n;

    set<string> pos;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (i == 0) {
            gen(s, 0, k, pos);
        } else {
            set<string> tmp;
            gen(s, 0, k, tmp);
            if (tmp.size()<pos.size())swap(tmp,pos);
            for (auto it = begin(pos); it != end(pos); ) {
                if (tmp.count(*it)) {
                    it = next(it);
                } else {
                    it = pos.erase(it);
                }
            }
        }
    }

    cout << pos.size() << endl;
    for (auto &s : pos)cout << s << endl;
}
