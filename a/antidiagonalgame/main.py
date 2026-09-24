def heur(n):
    k=(n+1)//2
    return 2**(2*(k-1))*3
print(heur(int(input()))%(10**9+3233))
