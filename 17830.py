import sys
import math


t = int(sys.stdin.readline())
for _ in range(t):
    entries = sys.stdin.readline().rstrip().split()
    n, b = int(entries[0]), entries[1]
    max_b, min_b = b.replace("?", "1"), b.replace("?", "0")
    idx = max_b.find("1")
    if idx != -1:
        if max_b.count("1") == 1:
            max_len = 2 * n - 1 - idx
        else:
            max_len = 2 * n - idx
    else:
        max_len = 1
    idx = min_b.find("1")
    if idx != -1:
        if min_b.count("1") == 1:
            min_len = 2 * n - 1 - idx
        else:
            min_len = 2 * n - idx
    else:
        min_len = 1
    print(max_len, min_len)
