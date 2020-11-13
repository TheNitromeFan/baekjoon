def main():
    t = int(input())
    for _ in range(t):
        num = input()
        ans = 0
        while num != "6174":
            num = str(int("".join(sorted(num, reverse=True))) - int("".join(sorted(num)))).zfill(4)
            ans += 1
        print(ans)


main()
