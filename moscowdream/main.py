a,b,c,n = map(int,input().split())

print("YES" if a*b*c > 0 and a+b+c>=n and n >= 3 else "NO")
