beats={"rock":"scissors","paper":"rock","scissors":"paper"}
a=input();b=input()
print("Draw" if a == b else "Player 1" if beats[a] == b else "Player 2")
