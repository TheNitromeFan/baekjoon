def binary_and(a, b):
    ans = ""
    for val in zip(a, b):
        if val[0] == val[1] == "1":
            ans += "1"
        else:
            ans += "0"
    return ans


def binary_or(a, b):
    ans = ""
    for val in zip(a, b):
        if val[0] == val[1] == "0":
            ans += "0"
        else:
            ans += "1"
    return ans


def binary_xor(a, b):
    ans = ""
    for val in zip(a, b):
        if val[0] == val[1]:
            ans += "0"
        else:
            ans += "1"
    return ans


def negate(binary):
    ans = ""
    for c in binary:
        if c == "0":
            ans += "1"
        else:
            ans += "0"
    return ans


def main():
    a = input()
    b = input()
    print(binary_and(a, b))
    print(binary_or(a, b))
    print(binary_xor(a, b))
    print(negate(a))
    print(negate(b))


main()
