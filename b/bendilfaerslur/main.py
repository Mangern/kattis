s=input()
if ":" in s:
    nc = sum(1 for c in s if c == ':')
    if "::" in s:
        s=s.replace("::", ":" + "0:"*(7-nc+1))
    if s[0] == ':':
        s = "0" + s
    if s[-1] == ":":
        s = s + "0"

    ws=[f"{int(x,16):04x}" for x in s.split(":")]
    print(".".join(("".join(ws))[::-1]) + ".ip6.arpa.")
else:
    l=s.split(".")
    print(".".join(l[::-1])+".in-addr.arpa.")
