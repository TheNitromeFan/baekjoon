import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        seq = sys.stdin.readline().rstrip()
        min_seq = seq
        for i, _ in enumerate(seq):
            if min_seq > seq[i:] + seq[:i]:
                min_seq = seq[i:] + seq[:i]
        print(min_seq)


main()
