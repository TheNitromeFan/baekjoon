import sys


temperatures = set()
for line in sys.stdin.readlines():
    temperatures |= {int(x) for x in line.split()[1:]}
print(min(temperatures), max(temperatures))
