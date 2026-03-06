#include <bits/stdc++.h>
using namespace std;

vector<int> get_idxs(int n, string key) {
    vector<int> alive(n);
    iota(begin(alive), end(alive), 0);

    vector<int> ret;
    bool flag = 0;
    vector<bool> vis(n, 0);
    for (int j = 0; j < key.length(); ++j) {
        int k = key[j] - 'a' + 2;
        if (!flag) {
            for (int i = k - 1; i < alive.size(); i += k) {
                ret.push_back(alive[i]);
                vis[alive[i]] = 1;
            }
        } else {
            for (int i = (int)alive.size() - 1 - (k - 1); i >= 0; i -= k) {
                ret.push_back(alive[i]);
                vis[alive[i]] = 1;
            }
        }
        flag = !flag;
        vector<int> nalive;
        for (int i : alive) {
            if (!vis[i]) nalive.push_back(i);
        }
        swap(alive, nalive);
    }

    if (!flag) {
        for (int i = 0; i < alive.size(); ++i) {
            ret.push_back(alive[i]);
        }
    } else {
        for (int i = (int)alive.size() - 1; i >= 0; --i) {
            ret.push_back(alive[i]);
        }
    }
    return ret;
}

string encrypt(string txt, string key) {
    vector<int> idxs = get_idxs(txt.length(), key);
    string ret(txt.length(), '?');
    for (int i = 0; i < txt.length(); ++i) {
        ret[idxs[i]] = txt[i];
    }
    return ret;
}

string decrypt(string txt, string key) {
    vector<int> idxs = get_idxs(txt.length(), key);
    string ret(txt.length(), '?');
    for (int i = 0; i < txt.length(); ++i) {
        ret[i] = txt[idxs[i]];
    }
    return ret;
}


int main() {
    string t, k;
    cin >> t >> k;
    string line;
    getline(cin, line);
    getline(cin, line);

    string txt;
    for (char c : line) {
        if (isalpha(c)) {
            txt.push_back(tolower(c));
        }
    }

    if (t == "E") {
        cout << encrypt(txt, k) << endl;
    } else {
        cout << decrypt(txt, k) << endl;
    }
}
