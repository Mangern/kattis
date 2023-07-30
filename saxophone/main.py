mp = {
    'c': [2,3,4,7,8,9,10],
    'd': [2,3,4,7,8,9],
    'e': [2,3,4,7,8],
    'f': [2,3,4,7],
    'g': [2,3,4],
    'a': [2,3],
    'b': [2],
    'C': [3],
    'D': [1,2,3,4,7,8,9],
    'E': [1,2,3,4,7,8],
    'F': [1,2,3,4,7],
    'G': [1,2,3,4],
    'A': [1,2,3],
    'B': [1,2]
}

for _ in range(int(input())):
    s = input()

    ans = [0 for i in range(10)]

    prv = set()
    for c in s:
        for x in mp[c]:
            if x not in prv:
                ans[x-1] += 1
        prv = set(mp[c])
    print(" ".join(map(str,ans)))
