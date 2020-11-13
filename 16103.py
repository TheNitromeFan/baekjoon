def main():
    n, k = (int(x) for x in input().split())
    s = input()
    a, b, c, d = (s[i:i + n // 4] for i in range(0, n, n // 4))
    for _ in range(k % 3):
        b, c, d = d, b, c
    print("".join([a, b, c, d]))


main()
