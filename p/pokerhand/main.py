from collections import Counter
s = list(map(lambda x: x[0], input().split()))
c = Counter(s)
print(max(c[k] for k in c))
