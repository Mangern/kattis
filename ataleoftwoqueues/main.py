input()
s1 = sum(map(int,input().split()))
s2 = sum(map(int,input().split()))
print("either" if s1 == s2 else "left" if s1 < s2 else "right")
