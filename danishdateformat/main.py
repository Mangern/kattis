mo =[ "januar", "februar", "marts", "april", "maj", "juni", "juli", "august", "september", "oktober", "november", "december" ]
a,b,c=map(int,input().split("/"))
print(f"{b}. {mo[a-1]} {c}")
