a,b=map(int,input().split())

sa = 0
for _ in range(a):
    v,c=map(int,input().split())
    sa += v * c
sb = 0
for _ in range(b):
    v,c=map(int,input().split())
    sb += v * c

print("same" if sa == sb else "different")
