import sys


sys.stdin.readline()
entries = sys.stdin.readline().rstrip().split()
stack = []
parens = 0
for entry in entries:
    if entry == "(":
        stack.append("(")
        parens += 1
    elif entry == ")":
        if parens % 2 == 0:
            new_entry = 0
            while stack and stack[-1] != "(":
                new_entry += stack[-1]
                new_entry %= 10 ** 9 + 7
                stack.pop()
        else:
            new_entry = 1
            while stack and stack[-1] != "(":
                new_entry *= stack[-1]
                new_entry %= 10 ** 9 + 7
                stack.pop()
        stack.pop()
        parens -= 1
        stack.append(new_entry)
    else:
        stack.append(int(entry))
ans = 0
while stack:
    ans += stack[-1]
    ans %= 10 ** 9 + 7
    stack.pop()
print(ans)
