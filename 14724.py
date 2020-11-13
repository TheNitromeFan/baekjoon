clubs = ["PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"]


def main():
    input()
    candidates = []
    for i in range(9):
        solved = max(int(x) for x in input().split())
        candidates.append((solved, clubs[i]))
    candidates.sort(reverse=True)
    print(candidates[0][1])


main()
