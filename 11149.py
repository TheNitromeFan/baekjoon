import string


t = int(input())
for _ in range(t):
    words = input().split()
    for word in words:
        value = 0
        for c in word:
            value += string.ascii_lowercase.index(c)
        r = value % 27
        if r == 26:
            print(" ", end="")
        else:
            print(string.ascii_lowercase[r], end="")
    print()
