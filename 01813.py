def main():
    input()
    nums = [int(x) for x in input().split()]
    counts = {0: 0}
    for num in nums:
        if num in counts:
            counts[num] += 1
        else:
            counts[num] = 1
    # print(counts)
    for k in sorted(counts.keys(), reverse=True):
        if counts[k] == k:
            return k
    return -1


print(main())
