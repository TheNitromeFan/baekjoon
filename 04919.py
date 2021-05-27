import sys


t = 0
while True:
    line = sys.stdin.readline().strip()
    if line == '0':
        break
    t += 1
    p = line
    r = ''
    pos = 0
    while p[pos] != ' ':
        r += p[pos]
        pos += 1
    r = int(r)
    p = p[pos + 1:]
    while p[0] == ' ':
        p = p[1:]
    n = ''
    pos = 0
    while p[pos] != ' ':
        n += p[pos]
        pos += 1
    n = int(n)
    p = p[pos + 1:]
    while p[0] == ' ':
        p = p[1:]
    if p[0] == '"':
        p1 = ''
        pos = 1
        while p[pos] != '"':
            p1 += p[pos]
            pos += 1
        p = p[pos + 2:]
    else:
        p1 = ''
        pos = 0
        while p[pos] != ' ':
            p1 += p[pos]
            pos += 1
        p = p[pos + 1:]
    while p[0] == ' ':
        p = p[1:]
    if p[0] == '"':
        p2 = ''
        pos = 1
        while p[pos] != '"':
            p2 += p[pos]
            pos += 1
    else:
        p2 = ''
        pos = 0
        while pos < len(p):
            p2 += p[pos]
            pos += 1
    r -= 1
    if r % (2 * n) < n:
        print(f"{t}. {p1.lower()}")
    else:
        print(f"{t}. {p2.lower()}")
