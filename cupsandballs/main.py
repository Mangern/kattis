g=int(input())-1
n=int(input())

bloc=[0,1,0]
for _ in range(n):
    a,b=map(int,input().split())
    bloc[a-1], bloc[b-1] = bloc[b-1], bloc[a-1]

if bloc[g]:
    a=bloc.index(0)+1
    b=bloc.index(0,a)+1
    print(a,b)
else:
    print(g+1, bloc.index(1)+1)
