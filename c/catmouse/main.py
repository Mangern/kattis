from math import pi, asin
for _ in range(int(input())):
    R,t,j=map(int,input().split())
    if j < (1+pi)*t:
        print("YES")
    else:
        print("NO")
