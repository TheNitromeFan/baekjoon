import sys


def main():
    n, t, p = (int(x) for x in sys.stdin.readline().split())
    points = {x: n for x in range(t)}
    problems = {x: [] for x in range(1, n + 1)}
    for i in range(1, n + 1):
        score = [int(x) for x in sys.stdin.readline().split()]
        for j in range(t):
            if score[j]:
                points[j] -= 1
                problems[i].append(j)
    scores = {}
    for x in range(1, n + 1):
        scores[x] = (sum(points[j] for j in problems[x]), len(problems[x]))
    # print(scores)
    contestants = list(range(1, n + 1))
    contestants.sort(key=lambda x: (scores[x][0], scores[x][1], -x), reverse=True)
    sys.stdout.write("{} {}".format(scores[p][0], contestants.index(p) + 1))


main()
