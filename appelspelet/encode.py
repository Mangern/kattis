import heapq
from collections import Counter
import base64

class Node:
    def __init__(self, cnt, value = None):
        self.cnt = cnt
        self.value = value
        self.child = [None, None]

    def set_left(self, left_child):
        self.child[0] = left_child

    def set_right(self, right_child):
        self.child[1] = right_child


    def __lt__(self, other):
        return self.cnt < other.cnt

def populate_encodings(cur_str, ptr, encodings):
    if ptr.value is not None:
        encodings[ptr.value] = cur_str
        return

    populate_encodings(cur_str+"0", ptr.child[0], encodings)
    populate_encodings(cur_str+"1", ptr.child[1], encodings)

lines = open("grundy.txt").readlines()
#lines = open("test.txt").readlines()

nums = list(map(int,lines))
print(max(nums))


freqs = [Node(fr, el) for el, fr in Counter(nums).items()]

heapq.heapify(freqs)

while len(freqs) > 1:
    top = heapq.heappop(freqs)
    ntop = heapq.heappop(freqs)

    par = Node(top.cnt + ntop.cnt)

    par.set_left(top)
    par.set_right(ntop)

    heapq.heappush(freqs, par)

root = freqs[0]

encodings = dict()

populate_encodings("", root, encodings)

result = []
for n in nums:
    result.append(encodings[n])

result = "".join(result)

bigint = int(result, 2)

bts = bigint.to_bytes((len(result) + 7)//8, "big")
print(len(bts))
