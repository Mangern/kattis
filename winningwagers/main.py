import operator
from functools import reduce
mp={"COIN":2,"DIE":6,"CARDS":52}
input()
print((reduce(operator.mul,map(mp.get, input().split())) - 1) * int(input()))
