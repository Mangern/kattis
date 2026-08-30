input()
print(sum({0:2,1:1,2:0.5,4:1/4,8:1/8,16:1/16}[x] for x in map(int,input().split())))
