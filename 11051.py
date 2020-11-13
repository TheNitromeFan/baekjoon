from math import factorial as f


n, m = [int(x) for x in input().split()]
print(f(n) // f(m) // f(n-m) % 10007)
