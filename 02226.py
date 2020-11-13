a, b = 0, 1
n = int(input())
for i in range(1, n):
    if i % 2 == 0:
        a, b = a + b - 1, a + b
    else:
        a, b = a + b, a + b
print(a)
