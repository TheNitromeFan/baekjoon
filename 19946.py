n = int(input())
while n % 2 == 0:
    n //= 2
k = 0
n += 1
while n > 1:
    n //= 2
    k += 1
print(k)
