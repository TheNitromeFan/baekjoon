def change_base(n, base):
    ret = ""
    while n:
        ret = str(n % base) + ret
        n //= base
    return ret


def palindrome(x):
    return x == x[::-1]


def main():
    n = int(input())
    ans  = []
    for b in range(2, 11):
        k = change_base(n, b)
        if palindrome(k):
            ans.append((b, k))
    if ans:
        for b, k in ans:
            print("{} {}".format(b, k))
    else:
        print("NIE")


main()
