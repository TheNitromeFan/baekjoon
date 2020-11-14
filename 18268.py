import sys


def consistent(sessions, n1, n2):
    if n1 == n2:
        return False
    for session1 in sessions:
        for session2 in sessions:
            if (session1.index(n1) - session1.index(n2)) * (session2.index(n1) - session2.index(n2)) < 0:
                return False
    return True


def main():
    k, n = (int(x) for x in input().split())
    sessions = []
    for _ in range(k):
        sessions.append([int(x) for x in input().split()])
    pairs = 0
    for n1 in range(1, n + 1):
        for n2 in range(1, n1):
            if consistent(sessions, n1, n2):
                pairs += 1
    print(pairs)



main()
