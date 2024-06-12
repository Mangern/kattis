#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

int len = 1;
vector<string> buf;

string nxt() {
    if (buf.empty()) {
        string start(len, 'a');

        while (1) {
            buf.push_back(start);
            int i;
            for (i = len - 1; i >= 0; --i) {
                if (++start[i] <= 'z')break;
                start[i] = 'a';
            }
            if (i < 0)break;
        }

        ++len;
    }
    string ret = buf.back();
    buf.pop_back();
    return ret;
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < max(a, (b+1)/2); ++i)cout << nxt() << " ";
    cout << endl;
}
