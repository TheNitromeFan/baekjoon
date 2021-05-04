import sys


s = sys.stdin.readline().rstrip()
t = "a"
while t in s:
    t += "a"
sys.stdout.write(t)
