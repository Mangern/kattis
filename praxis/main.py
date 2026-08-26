input()
a=list(map(int,input().split()))
print("da komrad" if max(a) - min(a) <= 1 else "ósvífinn kapítalisti")
