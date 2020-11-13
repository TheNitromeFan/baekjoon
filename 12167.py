import sys


def main():
    t = int(sys.stdin.readline())
    for x in range(1, t + 1):
        entries = sys.stdin.readline().rstrip().split()
        max_shyness = int(entries[0])
        shyness_levels = [int(k) for k in entries[1]]
        friends = 0
        standing = 0
        for i in range(max_shyness + 1):
            if standing < i:
                friends += i - standing
                standing = i
            standing += shyness_levels[i]
        print("Case #{}: {}".format(x, friends))


main()
