n = input()
print(bin(int(n, base=2) + int(n + "0000", base=2))[2:])
