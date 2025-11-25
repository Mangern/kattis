#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct song {
    ll idx;
    ll f;
    string name;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<song> songs;
    for (int i = 0; i < n; ++i) {
        ll f;
        cin >> f;
        string s;
        cin >> s;
        songs.push_back({(ll)i, f, s});
    }

    sort(begin(songs), end(songs), [&](auto s1, auto s2) {
        // q1 = s1.f / (n - s1.idx), q2 = s2.f / (n - s2.idx)
        // q1 > q2 <=> s1.f * (n - s2.idx) > 
        ll q1 = s1.f * (s1.idx+1);
        ll q2 = s2.f * (s2.idx+1);

        if (q1 != q2) {
            return q1 > q2;
        }
        return s1.idx < s2.idx;
    });

    for (int i = 0; i < m; ++i) {
        cout << songs[i].name << endl;
    }
}
