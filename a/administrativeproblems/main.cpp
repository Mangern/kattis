#include <array>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using tup = array<int, 3>;

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, tup> cars;

    for (int i = 0; i < n; ++i) {
        string s;
        int p, q, k;
        cin >> s >> p >> q >> k;
        cars[s] = {p, q, k};
    }

    set<string> names;
    unordered_set<string> incons;
    unordered_map<string, long long> cost;
    unordered_map<string, string> has;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        string s;
        cin >> s;
        char e;
        cin >> e;

        names.insert(s);

        if (e == 'p') {
            string c;
            cin >> c;

            if (has.count(s)) {
                incons.insert(s);
            } else {
                has[s] = c;
                cost[s] += cars.at(c)[1];
            }
        } else if (e == 'r') {
            int d;
            cin >> d;

            if (!has.count(s)) {
                incons.insert(s);
            } else {
                auto [p, q, k] = cars.at(has[s]);
                cost[s] += k * d;
                has.erase(s);
            }
        } else {
            int sev;
            cin >> sev;

            if (!has.count(s)) {
                incons.insert(s);
            } else {
                auto [p, q, k] = cars.at(has[s]);
                cost[s] += (p * sev + 99) /100;
            }
        }
    }

    for (const auto& [k, v] : has) {
        incons.insert(k);
    }

    for (const auto& name : names) {
        cout << name << " ";
        if (incons.count(name))cout << "INCONSISTENT" << endl;
        else cout << cost[name] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)solve();
}
