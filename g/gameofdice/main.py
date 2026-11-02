dice = [0]*5
for _ in range(5):
    parts = input().split("| |")
    for i, p in enumerate(parts):
        dice[i] += sum(1 for c in p if c == 'o')

ans=[]
cnt = [0]*7
for d in dice:
    cnt[d] += 1

# 1-6
for i in range(1,7):
    ans.append(i * cnt[i])

# Pair
for i in range(6, 0, -1):
    if cnt[i] >= 2:
        ans.append(2 * i)
        break
else:
    ans.append(0)

# Two pairs
ans.append(0)
for i in range(1, 7):
    for j in range(i+1, 7):
        if cnt[i] >= 2 and cnt[j] >= 2:
            ans[-1] = 2 * i + 2 * j

# Three of a kind
for i in range(6, 0, -1):
    if cnt[i] >= 3:
        ans.append(3 * i)
        break
else:
    ans.append(0)

# Four
for i in range(6, 0, -1):
    if cnt[i] >= 4:
        ans.append(4 * i)
        break
else:
    ans.append(0)

# House
ans.append(0)
for i in range(1, 7):
    for j in range(1, 7):
        if i != j:
            if cnt[i] == 3 and cnt[j] == 2:
                ans[-1] = 3 * i + 2 * j

# Straights
if sorted(dice) == [1,2,3,4,5]: ans.append(15)
else: ans.append(0)

if sorted(dice) == [2,3,4,5,6]: ans.append(20)
else: ans.append(0)

ans.append(50 * (min(dice) == max(dice)))
ans.append(sum(dice))

print(" ".join(map(str, ans[:6])))
print(" ".join(map(str, ans[6:])))
