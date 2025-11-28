ws=input().split()
i = 0
ansc=0
anss=""
while i < len(ws):
    j = i
    while j < len(ws) and ws[j] == ws[i]:
        j += 1
    if j - i > ansc:
        ansc = j - i
        anss = ws[i]
    i = j
print(anss)
