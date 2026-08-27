#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;

    cin >> n;

    map<string, stack<pair<string,int>>> mp;
    int sz = 1;
    bool fail = 0;


    stack<pair<string,int>> lst;

    while (n-->0) {
        string t;
        cin >> t;

        if (t == "{") {
            if (fail)continue;
            ++sz;
        } else if (t == "}") {
            if (fail)continue;

            while (lst.size() && lst.top().second == sz) {
                mp[lst.top().first].pop();
                lst.pop();
            }

            --sz;
        } else if (t == "TYPEOF") {
            string name;
            cin >> name;
            if (fail)continue;

            if (!mp.count(name)) {
                cout << "UNDECLARED" << endl;
                continue;
            } 
            while (mp[name].size() && mp[name].top().second > sz)mp[name].pop();
            if (mp[name].size()) {
                cout << mp[name].top().first << endl;
            } else {
                cout << "UNDECLARED" << endl;
            }
        } else if (t == "DECLARE") {
            string name, type;
            cin >> name >> type;
            if (fail)continue;
            if (mp.count(name)) {
                while (mp[name].size() && mp[name].top().second > sz)mp[name].pop();
                if (mp[name].size() && mp[name].top().second == sz) {
                    cout << "MULTIPLE DECLARATION" << endl;
                    fail = 1;
                }
            }
            mp[name].push({type, sz});
            lst.push({name,sz});
        }
    }
}
