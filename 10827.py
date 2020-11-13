a, b = input().split()
decimal = len(a) - 1 - a.find('.')
a_to_int = int(a.replace('.', ''))
b = int(b)
c = str(a_to_int ** b)
if len(c) < decimal * b + 1:
    c = '0' * (decimal * b + 1 - len(c)) + c
print(c[:-decimal * b] + '.' + c[-decimal * b:])
