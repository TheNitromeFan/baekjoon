import sys


def main():
    p, g = (int(x) for x in sys.stdin.readline().split())
    parties = {}
    for _ in range(p):
        entries = sys.stdin.readline().rstrip().split()
        parties[entries[0]] = int(entries[1].replace(".", ""))
    # print(parties)
    for guess in range(1, g + 1):
        conjecture = sys.stdin.readline().rstrip().split()
        percentage_sum = 0
        for i in range(0, len(conjecture) - 1, 2):
            percentage_sum += parties[conjecture[i]]
        if (conjecture[-2] == "=" and percentage_sum == int(conjecture[-1]) * 10) \
            or (conjecture[-2] == "<" and percentage_sum < int(conjecture[-1]) * 10) \
            or (conjecture[-2] == ">" and percentage_sum > int(conjecture[-1]) * 10) \
            or (conjecture[-2] == "<=" and percentage_sum <= int(conjecture[-1]) * 10) \
                or (conjecture[-2] == ">=" and percentage_sum >= int(conjecture[-1]) * 10):
            print("Guess #{} was correct.".format(guess))
        else:
            print("Guess #{} was incorrect.".format(guess))


main()
