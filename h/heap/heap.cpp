#include "heap.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heap;

int getMax(){
    return heap[0];
}

int getSize(){
    return heap.size();
}

void insert(int element){
    heap.push_back(element);
    int ptr = heap.size()-1;

    while (ptr) {
        int par = ((ptr+1)>>1)-1;

        if (heap[ptr] > heap[par]) {
            swap(heap[ptr],heap[par]);
            ptr = par;
        } else break;
    }
}

void removeMax(){
    swap(heap[0],heap.back());
    heap.pop_back();

    if (heap.size() <= 1)return;
    
    int ptr = 0;
    while (((ptr+1)<<1)-1 < heap.size()) {
        int l = ((ptr+1)<<1)-1;
        int r = ((ptr+1)<<1|1)-1;

        if (r >= heap.size() || heap[l] > heap[r]) {
            if (heap[ptr] > heap[l])return;
            swap(heap[ptr],heap[l]);
            ptr = l;
        } else {
            if (heap[ptr] > heap[r])return;
            swap(heap[ptr],heap[r]);
            ptr = r;
        }
    }
}
