#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<tuple<string,int,int>> stuff;
    for (int i = 0; i < n; ++i) {
        string s; int a, b;
        cin >> s >> a >> b;
        stuff.emplace_back(s,a,b);
    }
    sort(begin(stuff), end(stuff), [](const auto& t1, const auto& t2) {
        const auto& [s1, a1, b1] = t1;
        const auto& [s2, a2, b2] = t2;
        if (a1 == 0 && a2 == 0) {
            return b1 > b2;
        }
        if (a1 == 0) return true;
        if (a2 == 0) return false;

        // b1 / a1 > b2 / a2
        return b1 * a2 > b2 * a1;
    });
    for (const auto& [s, _, __] : stuff) cout << s << '\n';
}
