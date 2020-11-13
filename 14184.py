import sys


def sort_key(tuple1):
    return tuple1[1], tuple1[2], tuple1[3], tuple1[4], -tuple1[0]


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        votes = {}
        for _ in range(n):
            entries = [int(x) for x in input().split()]
            d = entries[0]
            for i in range(1, d + 1):
                flag = entries[i]
                if flag not in votes:
                    votes[flag] = [flag, 0, 0, 0]
                votes[flag][i] += 1
        flags = [(flag, 3 * votes[flag][1] + 2 * votes[flag][2] + votes[flag][3],
                  votes[flag][1], votes[flag][2], votes[flag][3]) for flag in votes]
        flags.sort(key=sort_key, reverse=True)
        index = 0
        while flags[index][1:] == flags[0][1:]:
            print(flags[index][0], end=" ")
            index += 1
        print()


main()
