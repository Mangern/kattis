pa,pb=0,0
fail = False
for _ in range(int(input())):
    a,b=map(int,input().split())
    if a < pa or b < pb:
        fail = True
    pa,pb=a,b
print("yes" if not fail else "no")
