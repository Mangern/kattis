input()
ans=0
for x in map(int,input().split()):
    ans ^= x
print(f"*{ans}")
