import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n = int(sys.stdin.readline())
        head_count = {}
        for _ in range(2 * n - 1):
            list1 = [int(x) for x in sys.stdin.readline().split()]
            for x in list1:
                if x in head_count:
                    head_count[x] += 1
                else:
                    head_count[x] = 1
        missing_list = sorted(x for x, v in head_count.items() if v % 2 == 1)
        print(f"Case #{a0}: {' '.join(str(x) for x in missing_list)}")


main()
