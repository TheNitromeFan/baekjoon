import sys


while True:
    n, m = (int(x) for x in sys.stdin.readline().split())
    if n == m == 0:
        break
    a = {int(x) for x in sys.stdin.readline().split()}
    b = {int(x) for x in sys.stdin.readline().split()}
    print(min(len(a - b), len(b - a)))
