mp={
"abc": 2,
"def": 3,
"ghi": 4,
"jkl": 5,
"mno": 6,
"pqrs": 7,
"tuv": 8,
"wxyz": 9,
}
for k in list(mp.keys()):
    for c in k:
        mp[c] = mp[k]
for _ in range(int(input())):
    for c in input().lower():
        print(mp[c],end="")
    print()
