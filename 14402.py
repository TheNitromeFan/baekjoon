import sys


def main():
    q = int(sys.stdin.readline())
    logs = {}
    ans = 0
    for _ in range(q):
        name, action = sys.stdin.readline().rstrip().split()
        if action == "-":
            if name not in logs or logs[name] == 0:
                logs[name] = 0
                ans += 1
            else:
                logs[name] -= 1
        else:
            if name in logs:
                logs[name] += 1
            else:
                logs[name] = 1
    for name in logs:
        ans += logs[name]
    print(ans)


main()
