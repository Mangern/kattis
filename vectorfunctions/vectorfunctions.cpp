#include "vectorfunctions.h"

#include <bits/stdc++.h>

using namespace std;

void backwards(std::vector<int>& vec){
    reverse(begin(vec), end(vec));
}

std::vector<int> everyOther(const std::vector<int>& vec){
    auto ret = std::vector<int>();
    for (int i = 0; i < vec.size(); i += 2) {
        ret.push_back(vec[i]);
    }
    return ret;
}

int smallest(const std::vector<int>& vec){
    return *min_element(begin(vec), end(vec));
}

int sum(const std::vector<int>& vec){
    return accumulate(begin(vec), end(vec), 0);
}

int veryOdd(const std::vector<int>& suchVector){
    int ret = 0;
    for (int i = 1; i < suchVector.size(); i += 2) {
        ret += (suchVector[i]&1);
    }
    return ret;
}

