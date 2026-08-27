g,s,c=map(int,input().split())
sm = 3*g+2*s+1*c

aa = "Province" if sm >= 8 else ("Duchy" if sm >= 5 else ("Estate" if sm >= 2 else ""))
ab = "Gold" if sm >= 6 else ("Silver" if sm >= 3 else "Copper")
sp = " or " if len(aa) > 0 else ""
print(aa+sp+ab)

