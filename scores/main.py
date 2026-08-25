a=list(map(float,input().split()))
a.sort()
if len(a) < 3:
    print("At least 3 scores needed!")
    exit()
s=sum(a)-sum(a[:3])
print(f"Sum of scores (3 lowest removed): {s}")
