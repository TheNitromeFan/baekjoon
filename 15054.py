import collections
import sys


def main():
    k, n = (int(x) for x in sys.stdin.readline().split())
    s = [int(x) for x in sys.stdin.readline().split()]
    c = collections.Counter(s)
    if n % k == 1:
        list1 = [x for x in range(1, k + 1) if c[x] == n // k]
        list2 = [x for x in range(1, k + 1) if c[x] == n // k + 1]
        if len(list1) == k - 1 and len(list2) == 1:
            print("-{}".format(list2[0]))
        else:
            print("*")
    elif n % k == k - 1:
        list1 = [x for x in range(1, k + 1) if c[x] == n // k + 1]
        list2 = [x for x in range(1, k + 1) if c[x] == n // k]
        if len(list1) == k - 1 and len(list2) == 1:
            print("+{}".format(list2[0]))
        else:
            print("*")
    elif n % k == 0:
        list1 = [x for x in range(1, k + 1) if c[x] == n // k + 1]
        list2 = [x for x in range(1, k + 1) if c[x] == n // k]
        list3 = [x for x in range(1, k + 1) if c[x] == n // k - 1]
        if len(list2) == k - 2 and len(list1) == 1 and len(list3) == 1:
            print("-{} +{}".format(list1[0], list3[0]))
        else:
            print("*")
    else:
        print("*")


main()
