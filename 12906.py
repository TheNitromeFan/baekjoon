import sys
import collections


def ending_sequence(a, b, c):
    return all(s == 'A' for s in a) and all(s == 'B' for s in b) and all(s == 'C' for s in c)


def bfs(sa, sb, sc):
    dist = {}
    q = collections.deque()
    dist[(sa, sb, sc)] = 0
    q.append((sa, sb, sc))
    while q:
        a, b, c = q.popleft()
        if ending_sequence(a, b, c):
            return dist[(a, b, c)]
        if a:
            na, nb, nc = a[:-1], b + a[-1], c
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))
            na, nb, nc = a[:-1], b, c + a[-1]
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))
        if b:
            na, nb, nc = a + b[-1], b[:-1], c
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))
            na, nb, nc = a, b[:-1], c + b[-1]
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))
        if c:
            na, nb, nc = a + c[-1], b, c[:-1]
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))
            na, nb, nc = a, b + c[-1], c[:-1]
            if (na, nb, nc) not in dist:
                dist[(na, nb, nc)] = dist[(a, b, c)] + 1
                q.append((na, nb, nc))


def main():
    line = sys.stdin.readline().rstrip()
    if line != '0':
        a = line.split()[1]
    else:
        a = ''
    line = sys.stdin.readline().rstrip()
    if line != '0':
        b = line.split()[1]
    else:
        b = ''
    line = sys.stdin.readline().rstrip()
    if line != '0':
        c = line.split()[1]
    else:
        c = ''
    print(bfs(a, b, c))


main()
