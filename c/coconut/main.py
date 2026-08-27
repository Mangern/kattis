s,n = map(int,input().split())
players = [(i,0) for i in range(n)]
ptr = 0 
s -= 1
while len(players) > 1:
    ptr += s
    ptr %= len(players)
    curr = players[ptr]
    if not curr[1]:
        players.pop(ptr)
        players.insert(ptr,(curr[0],1))
        players.insert(ptr,(curr[0],1))
    elif curr[1] == 1:
        players[ptr] = (curr[0],2)
        ptr += 1
    else:
        players.pop(ptr)

print(players[0][0]+1)
