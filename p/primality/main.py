import subprocess
n=int(input())
p=int(subprocess.check_output(["factor",str(n)],text=True).split()[-1])
print("YES" if n==p else "NO")
