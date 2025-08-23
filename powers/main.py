print((lambda a,b: 0 if a&1 else pow(a//2,b,a))(*map(int,input().split())))
