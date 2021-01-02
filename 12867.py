import sys


def no_backtracking(path, directions, m):
    for length in range(1, m + 1):
        for start in range(m - length + 1):
            end = start + length
            traveled = {}
            for idx in range(start, end):
                p = path[idx]
                if p not in traveled:
                    traveled[p] = 0
                if directions[idx] == "+":
                    traveled[p] += 1
                else:
                    traveled[p] -= 1
            if all(val == 0 for val in traveled.values()):
                return False
    return True


def main():
    sys.stdin.readline()
    m = int(sys.stdin.readline())
    path = [int(x) for x in sys.stdin.readline().split()]
    directions = sys.stdin.readline().rstrip()
    print(int(no_backtracking(path, directions, m)))


main()
