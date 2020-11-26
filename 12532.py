import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n = int(sys.stdin.readline())
        nums = set()
        for _ in range(n):
            nums.add(int(sys.stdin.readline().rstrip()[2:].ljust(11, "0")))
            # print(nums)
        eliminated = []
        for i in range(1, 51):
            elimination = []
            for num in nums:
                if int(num * 3 ** i // 10 ** 11) % 3 == 1:
                    elimination.append(num)
            for num in elimination:
                nums.remove(num)
            elimination.sort()
            eliminated += elimination
        eliminated += sorted(nums)
        sys.stdout.write("Case #{}:\n".format(a0))
        for num in eliminated:
            sys.stdout.write("0.{}\n".format(str(num).zfill(11).rstrip("0")))


main()
