import sys


while True:
    try:
        n = int(sys.stdin.readline())
    except (EOFError, ValueError):
        break
    categories = set()
    for _ in range(n):
        trainee = sys.stdin.readline().rstrip()
        categories.add(tuple(sorted(set(trainee))))
    print(len(categories))
