cost=[3*5, 1+3*4,2+3*3,3+3*2,4+3,5,3+4,3*2+3,3*3+2,3*4+1]
ans=(int(input())-1)*7
for w in input().split():
    ans += 3 * (len(w) - 1)
    for c in w:
        ans += cost[ord(c) - ord('0')]+4
print(ans)
