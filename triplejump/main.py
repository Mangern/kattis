n=int(input())
a=list(map(int,input().split()))

d1 = a[0]//3
d3 = a[-1]//3

# d1*3, d1*2 + d2

d2 = a[1] - 2 * d1
print(d1,d2,d3)
