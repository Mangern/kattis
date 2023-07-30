inp = [input().split() for i in range(4)]
cards = [s for l in inp for s in l]

found = False
for i in range(12):
    for j in range(i+1,12):
        for k in range(j+1,12):
            props = [True for l in zip(cards[i],cards[j],cards[k]) if len(set(l)) == 2]
            if len(props):
                continue
            print(i+1,j+1,k+1)
            found = True

if not found:
    print("no sets")
            
