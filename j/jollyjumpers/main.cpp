#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int a[3004];
bool vis[3004];

int main() {
    string line;
    stringstream ss;
    int n;
    while (getline(cin, line)) {
        ss.clear();
        ss.str(line);
        ss >> n;

        if (n <= 1) {
            cout << "Jolly" << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            ss >> a[i];
        }

        for (int i = 0; i < n - 1; ++i)vis[i] = 0;

        for (int i = 1; i < n; ++i) {
            int d = abs(a[i] - a[i-1]);
            if (d - 1 >= n - 1)continue;
            vis[d-1] = 1;
        }

        bool jol = 1;
        for (int i = 0; i < n - 1; ++i)jol &= vis[i];
        if (jol)
            cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
}
