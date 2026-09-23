import subprocess
n=int(input())
print(subprocess.check_output(["factor",str(n-1)],text=True).split()[-1])
