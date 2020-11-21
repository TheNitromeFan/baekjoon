import sys


def main():
    n, k = (int(x) for x in sys.stdin.readline().split())
    p = []
    for _ in range(n):
        entries = [int(x) for x in sys.stdin.readline().split()]
        p.append(entries[1:])
    # print(p)
    judge = 0
    judge_round = 0
    points = 0
    while k:
        if judge_round < len(p[judge]) and points <= p[judge][judge_round]:
            points += p[judge][judge_round]
            k -= 1
        elif judge_round >= len(p[judge]):
            points += 50
            k -= 1
        judge = (judge + 1)
        if judge == n:
            judge_round += 1
            judge = 0
    print(points)


main()
