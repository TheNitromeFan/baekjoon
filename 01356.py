def product(n):
    ans = 1
    for digit in n:
        ans *= int(digit)
    return ans


def is_evenly_product(n):
    for i in range(1, len(n)):
        if product(n[:i]) == product(n[i:]):
            return True
    return False


def main():
    n = input()
    if is_evenly_product(n):
        print("YES")
    else:
        print("NO")


main()
