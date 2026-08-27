a,b,c,d=map(int,input().split())
print("COZY" if d == a*b*c else "TOO TIGHT" if d > a*b*c else "SO MUCH SPACE")
