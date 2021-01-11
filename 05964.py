import sys


n = int(sys.stdin.readline())
stack = []
for _ in range(n):
    x = sys.stdin.readline().rstrip()
    if x == "1":
        entry = 0
        while stack and stack[-1] != 0:
            entry += stack.pop()
        stack.pop()
        if entry == 0:
            stack.append(1)
        else:
            stack.append(2 * entry)
    else:
        stack.append(0)
ans = 0
while stack:
    ans += stack.pop()
print(ans % 12345678910)
