from collections import deque
def toip(ips):
    return tuple(map(int,ips.split(".")))

def matches(ip,port, rules, cnt):
    good = True
    for r in rules:
        if r.startswith("port"):
            p = int(r.split("=")[1])
            if p != port:
                return False
        elif r.startswith("ip"):
            i = toip(r.split("=")[1])
            if i != ip:
                return False
        elif r.startswith("limit"):
            lim = int(r.split("=")[1])
            if cnt[ip] < lim:
                return False
    return True
fw=[]
for _ in range(int(input())):
    tok=input().split()
    act = tok[0]
    rules=tok[1:] if len(tok) >= 1 else []
    fw.append((act,rules))

cnt={}
window=deque()

for i in range(int(input())):
    ip, port = input().split(":")
    ip = toip(ip)
    port = int(port)
    window.append(ip)
    if ip not in cnt:
        cnt[ip] = 0
    cnt[ip] += 1

    if len(window) > 1000:
        j = window.popleft()
        cnt[j] -= 1

    for act, rules in fw:
        if matches(ip, port, rules, cnt):
            print(act, i+1)
            if act in ["accept", "drop"]:
                break
