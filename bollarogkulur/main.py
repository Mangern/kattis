state=[0,1,0,0]
for _ in range(5):
    i=int(input())
    j=int(input())
    tmp=state[i]
    state[i]=state[j]
    state[j]=tmp
print(state.index(1))
