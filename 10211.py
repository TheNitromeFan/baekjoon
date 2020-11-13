def maximum_sum(a):
    max_ending_here = a[0]
    max_so_far = max_ending_here
    for entry in a[1:]:
        max_ending_here = max(entry, max_ending_here + entry)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far


def main():
    input()
    print(maximum_sum([int(x) for x in input().split()]))


for i in range(int(input())):
    main()
