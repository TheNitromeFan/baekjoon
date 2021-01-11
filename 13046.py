import sys


correct = sys.stdin.readline().rstrip()
positions = {}
for idx, c in enumerate(correct):
    positions[c] = idx
n = int(sys.stdin.readline())
for _ in range(n):
    attempt = sys.stdin.readline().rstrip()
    strikes, balls = 0, 0
    for idx, c in enumerate(attempt):
        if c in positions and positions[c] == idx:
            strikes += 1
        elif c in positions:
            balls += 1
    print(strikes, balls)
