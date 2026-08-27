ans=0
q,m,s,l=map(int,input().split())
ans += q * ((l+m-1)//m)
wo   = (m - l % m) % m
s   -= min(s, q * wo)
ans += (s + m - 1) // m
print(ans)
