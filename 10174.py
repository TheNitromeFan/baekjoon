def main():
    n = int(input())
    for _ in range(n):
        line = input().lower()
        if line == line[::-1]:
            print("Yes")
        else:
            print("No")


main()
