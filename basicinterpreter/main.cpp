#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

int vars[26];

int getval(const string& var) {
    if (var.size() == 1 && 'A' <= var[0] && var[0] <= 'Z') {
        return vars[var[0]-'A'];
    }
    return stoi(var);
}

int parse_line(const string& line) {
    stringstream ss(line);
    string cmd;
    string tmp;
    ss >> cmd;

    if (cmd == "LET") {
        string var;
        ss >> var;
        ss >> tmp;
        string op;
        string var1, var2;
        ss >> var1;
        if (!(ss >> op)) {
            vars[var[0] - 'A'] = getval(var1);
        } else {
            ss >> var2;
            if (op == "+") {
                vars[var[0] - 'A'] = getval(var1) + getval(var2);
            } else if (op == "-") {
                vars[var[0] - 'A'] = getval(var1) - getval(var2);
            } else if (op == "*") {
                vars[var[0] - 'A'] = getval(var1) * getval(var2);
            } else if (op == "/") {
                vars[var[0] - 'A'] = getval(var1) / getval(var2);
            }
        }
    } else if (cmd == "IF") {
        string var1, condo, var2;
        ss >> var1 >> condo >> var2;
        ss >> tmp >> tmp >> tmp;
        int ret = stoi(tmp);
        int val1 = getval(var1);
        int val2 = getval(var2);
        if (condo == "=") {
            if (val1 == val2)return ret;
        } else if (condo == ">") {
            if (val1 > val2)return ret;
        } else if (condo == "<") {
            if (val1 < val2)return ret;
        } else if (condo == "<>") {
            if (val1 != val2)return ret;
        } else if (condo == "<=") {
            if (val1 <= val2)return ret;
        } else if (condo == ">=") {
            if (val1 >= val2)return ret;
        }
    } else if (cmd == "PRINT" || cmd == "PRINTLN") { 
        string rest = line.substr(line.find(' ')+1, line.size());
        if (rest[0] == '"') {
            cout << rest.substr(1, rest.length() - 2);
        } else {
            cout << getval(rest);
        }
        if (cmd == "PRINTLN")cout << endl;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<int, string> prog;
    string line;
    vector<int> nums;
    while (getline(cin, line)) {
        int num;
        int i = line.find(' ');
        num = stoi(line.substr(0, i));
        prog[num] = line.substr(i+1, line.length());
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    map<int, int> lineidx;
    for (int i = 0; i < nums.size(); ++i)lineidx[nums[i]] = i;
    int i = 0;
    while (i < nums.size()) {
        int res = parse_line(prog[nums[i]]);
        if (res == -1) {
            ++i;
        } else {
            i = lineidx[res];
        }
    }
}
