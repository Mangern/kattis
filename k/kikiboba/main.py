from collections import Counter
s = [c for c in input() if c in ['b', 'k']]
c = Counter(s)

if c['b'] == 0 and c['k'] == 0:
    print("none")
elif c['b'] == c['k']:
    print("boki")
elif c['b'] > c['k']:
    print("boba")
else:
    print("kiki")
