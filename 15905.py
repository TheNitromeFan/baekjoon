def main():
    n = int(input())
    scores = [tuple(int(x) for x in input().split()) for _ in range(n)]
    scores.sort(key=lambda x: (x[0], -x[1]), reverse=True)
    print(sum(1 for x in scores if x[0] == scores[4][0] and x[1] > scores[4][1]))


main()
