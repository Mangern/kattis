#include <bits/stdc++.h>
using namespace std;

struct cat {
    int l;
    int time;
    string name;



    bool operator< (const cat& other) const {
        if (l != other.l)return l < other.l;
        return time > other.time;
    }
};

int main() {
    int n;
    cin >> n;

    set<cat> pq;
    map<string,int> tim;
    map<string,int> lvl;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            string s;
            cin >> s;
            int x;
            cin >> x;
            pq.insert({x ,i, s});
            lvl[s] = x;
            tim[s] = i;
        } else if (t == 1) {
            string s;
            int x;
            cin >> s >> x;
            pq.erase({lvl[s], tim[s], s});
            lvl[s] += x;
            pq.insert({lvl[s], tim[s], s});
        } else if (t == 2) {
            string s;
            cin >> s;
            pq.erase({lvl[s], tim[s], s});
            lvl.erase(s);
            tim.erase(s);
        } else {
            if (pq.empty()) {
                cout << "The clinic is empty" << endl;
            } else {
                cout << (--pq.end())->name << endl;
            }
        }
    }
}
