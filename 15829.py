import string


n = int(input())
line = input()
ans = sum((string.ascii_lowercase.index(line[i]) + 1) * 31 ** i for i in range(n))
print(ans % 1234567891)
