import sys


def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    lengths = [1] * n
    num_idx_map = {a[0]: 0}
    max_length = 1
    for i in range(1, n):
        if a[i] - 1 in num_idx_map:
            lengths[i] = lengths[num_idx_map[a[i] - 1]] + 1
        else:
            lengths[i] = 1
        if lengths[i] > max_length:
            max_length = lengths[i]
        num_idx_map[a[i]] = i
    sys.stdout.write(str(max_length))


main()
