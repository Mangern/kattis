input()
s1=sum(map(int,input().split()))
s2=sum(map(int,input().split()))
print("Oh no" if s1 == s2 else "Button 1" if s1 > s2 else "Button 2")
