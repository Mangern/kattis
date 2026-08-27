#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int k = 0;
    queue<int> stream;
    stack<int> st;

    auto fillstream = [&] () {
        int x = ++k;
        while (x) {
            st.push(x%10);
            x /= 10;
        }
        while (st.size()) {
            stream.push(st.top());
            st.pop();
        }
    };

    for (char c : s) {
        int dig = c - '0';
        for (;;) {
            while (stream.size() && stream.front() != dig) 
                stream.pop();
            if (stream.empty()) {
                fillstream();
                continue;
            }
            stream.pop();
            break;
        }
    }

    cout << k << endl;
}
