import sys


def main():
    n = int(sys.stdin.readline())
    nums = [int(x) for x in sys.stdin.readline().split()]
    reflections = []
    for i in range(1, n + 1):
        if nums.index(i) + 1 != i:
            a, b = i, nums.index(i) + 1
            if a > b:
                a, b = b, a
            reflections.append((a, b))
            nums = nums[:a - 1] + nums[a - 1:b][::-1] + nums[b:]
    sys.stdout.write(str(len(reflections)))
    for a, b in reflections:
        sys.stdout.write("\n{} {}".format(a, b))


main()
