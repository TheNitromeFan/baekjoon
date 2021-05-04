import sys


def main():
    n = int(sys.stdin.readline())
    predict, final = {}, {}
    for i in range(n):
        predict[sys.stdin.readline().rstrip()] = i
    for i in range(n):
        final[sys.stdin.readline().rstrip()] = i
    if predict == final:
        sys.stdout.write("suspicious")
        return
    rankings = sorted(predict.keys(), key=lambda x: (final[x] - predict[x], final[x]))
    winner = rankings[0]
    sys.stdout.write(winner)


main()
