n,v=map(int,input().split())
box = [list(map(int,input().split())) for _ in range(n)]
print(max(l*w*h-v for l,w,h in box))
