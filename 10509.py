import sys


positions = {"1": (0, 0), "2": (0, 1), "3": (0, 2), "4": (1, 0), "5": (1, 1), "6": (1, 2), "7": (2, 0),
             "8": (2, 1), "9": (2, 2), "0": (3, 1)}


def valid(combination):
    for i in range(len(combination) - 1):
        x1, y1 = positions[combination[i]]
        x2, y2 = positions[combination[i + 1]]
        if not (x1 <= x2 and y1 <= y2):
            return False
    return True


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        k = int(sys.stdin.readline())
        min_difference = k
        ans = 0
        for x in range(1, 301):
            if valid(str(x)) and min_difference > abs(x - k):
                min_difference = abs(x - k)
                ans = x
        sys.stdout.write("{}\n".format(ans))


main()
