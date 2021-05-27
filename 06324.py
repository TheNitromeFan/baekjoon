import sys
import string
import itertools


n = int(sys.stdin.readline())
for a0 in range(1, n + 1):
    port, path = "<default>", "<default>"
    url = sys.stdin.readline().rstrip()
    idx0 = url.find("://")
    protocol, host = url[:idx0], url[idx0 + 3:]
    l1 = [x for x, val in enumerate(host) if val == ":"]
    l2 = [x for x, val in enumerate(host) if val == "/"]
    flag = False
    if l1 and l2:
        for idx1, idx2 in itertools.product(l1, l2):
            if idx1 < idx2 and host[idx1 + 1] in string.digits:
                host, port, path = host[:idx1], host[idx1 + 1:idx2], host[idx2 + 1:]
                flag = True
                break
    if not flag and l1:
        for idx1 in l1:
            if idx1 + 1 < len(host) and host[idx1 + 1] in string.digits:
                host, port = host[:idx1], host[idx1 + 1:]
                flag = True
                break
    if not flag and l2:
        idx2 = l2[0]
        host, path = host[:idx2], host[idx2 + 1:]
    print(f"URL #{a0}")
    print(f"Protocol = {protocol}")
    print(f"Host     = {host}")
    print(f"Port     = {port}")
    print(f"Path     = {path}")
    print()
