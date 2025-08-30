lft="qwertasdfgzxcvb"
rgt="yuiophjklnm"
s=input()
print("yes" if all(c in lft for c in s[::2]) and all(c in rgt for c in s[1::2]) or all(c in rgt for c in s[::2]) and all(c in lft for c in s[1::2]) else "no")
