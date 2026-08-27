n = int(input())

a = list(map(int,input().split()))

sm = 0
for i in range(1,7):
    for j in range(1,7):
        x = i+j
        if x in a:
            sm += 1

print(sm / 36)
