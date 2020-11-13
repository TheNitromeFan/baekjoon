def main():
    scores = set()
    for i in range(1, 9):
        scores.add((i, int(input())))
    counted = sorted(scores, key=lambda x: x[1], reverse=True)[:5]
    print(sum(pair[1] for pair in counted))
    print(" ".join(str(x) for x in sorted(pair[0] for pair in counted)))


main()
