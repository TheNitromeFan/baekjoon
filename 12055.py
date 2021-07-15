import sys


t = int(sys.stdin.readline())
for a0 in range(1, t + 1):
    n = int(sys.stdin.readline())
    prefixes = set()
    for _ in range(n):
        ip, subnet = sys.stdin.readline().split("/")
        a, b, c, d = (int(x) for x in ip.split("."))
        p = int(subnet)
        binary = a * 2 ** 24 + b * 2 ** 16 + c * 2 ** 8 + d
        prefixes.add((binary // 2 ** (32 - p), p))
    flag = True
    while flag:
        flag = False
        for prefix, p in prefixes:
            if (prefix // 2 * 2, p) in prefixes and (prefix // 2 * 2 + 1, p) in prefixes:
                prefixes.remove((prefix // 2 * 2, p))
                prefixes.remove((prefix // 2 * 2 + 1, p))
                prefixes.add((prefix // 2, p - 1))
                flag = True
                break
        for prefix, p in prefixes:
            for i in range(0, p):
                if (prefix // 2 ** (p - i), i) in prefixes:
                    prefixes.remove((prefix, p))
                    flag = True
                    break
            if flag:
                break
    ans = []
    for prefix, p in prefixes:
        binary = prefix * 2 ** (32 - p)
        ans.append((binary // 2 ** 24, binary // 2 ** 16 % 2 ** 8, binary // 2 ** 8 % 2 ** 8, binary % 2 ** 8, p))
    ans.sort()
    print(f"Case #{a0}:")
    for a, b, c, d, p in ans:
        print(f"{a}.{b}.{c}.{d}/{p}")
