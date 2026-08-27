#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length() - 2; ) {
            if (line[i] == '0' && tolower(line[i+1]) == 'x') {
                int j;
                for (j = i + 2; j < line.length(); ++j) {
                    if (!(
                        '0' <= line[j] && line[j] <= '9' 
                     || 'a' <= line[j] && line[j] <= 'f' 
                     || 'A' <= line[j] && line[j] <= 'F')) break;
                }
                if (j == i + 2) { 
                    i += 3; 
                    continue;
                }
                cout << line.substr(i, j - i) << " " << strtoimax(line.data()+i, 0, 16) << endl;
                i = j;
            } else ++i;
        }
    }
}
