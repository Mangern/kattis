w,s=map(int,input().split())
c=s*(s+1)//2

wt=c*29260
dif=w-wt
print(dif // (29370-29260))
