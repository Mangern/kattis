#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;){
        string s;
        cin >> s;
        if (s == "0") break;

        vector<string> pool;
        int N= 0;
        vector<string> dub;

        for (char c : s) {
            if (islower(c))pool.push_back(string(1,c));
            else if (c == 'N')++N;
            else dub.push_back(string(1,c));
        }

        if (!pool.size()) {
            cout << "no WFF possible" << endl;
            continue;
        }

        while (N) {
            string s = pool.back();
            pool.pop_back();
            pool.push_back("N"+s);
            --N;
        }

        while (dub.size() > 0 && pool.size() >= 2) {
            string s = pool.back();
            pool.pop_back();
            string t = pool.back();
            pool.pop_back();
            string d = dub.back();
            dub.pop_back();
            pool.push_back(d + s + t);
        }

        cout << pool.back() << endl;
    }
}
