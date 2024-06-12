#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    string pat;
    while (getline(cin, pat)) {
        cout << pat << ": ";
        int sm = 0;
        for (char c : pat)sm += c - '0';
        if (sm % pat.length()) {
            cout << "invalid # of balls" << endl;
            continue;
        }
        int n = sm / pat.length();

        bool fail = 0;
        set<int> st;
        for (int i = 0; i < pat.length(); ++i) {
            st.insert((i+pat[i]-'0')%pat.length());
        }
        if (st.size() != pat.length()) {
            cout << "invalid pattern" << endl;
        } else {
            cout << "valid with " << n << " balls" << endl;
        }

    }
}
