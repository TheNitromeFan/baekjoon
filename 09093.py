def main():
    n = int(input())
    for _ in range(n):
        print(" ".join(word[::-1] for word in input().split()))


main()
