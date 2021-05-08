import sys


def main():
    while True:
        entries = [int(x) for x in sys.stdin.readline().split()]
        if entries[1] == 0:
            break
        t, n, nums = entries[0], entries[1], entries[2:]
        ans = set()
        for perm in range(2 ** n):
            selection = []
            x = perm
            for i in range(n):
                if x % 2:
                    selection.append(nums[i])
                x //= 2
            if sum(selection) == t:
                ans.add(tuple(selection))
        print(f"Sums of {t}:")
        if ans:
            for select in sorted(ans, reverse=True):
                print("+".join(str(x) for x in select))
        else:
            print("NONE")


main()
