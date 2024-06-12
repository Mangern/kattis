#include <iostream>
#include <string>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;

    while (n.back() == '0' && m.back() == '0') {
        n.pop_back();
        m.pop_back();
    }

    if (m.length() == 1) {
        cout << n << endl;
        return 0;
    }

    if (m.length() > n.length()) {
        cout << "0.";
        for (int i = 0; i < m.length() - n.length() - 1; ++i)cout << '0';
        cout << n << endl;
    } else {
        int cnt = n.length() - m.length() + 1;

        for (int i = 0; i < cnt; ++i)cout << n[i];
        cout << '.';
        for (int i = cnt; i < n.length(); ++i)cout << n[i];
        cout << endl;
    }
}
