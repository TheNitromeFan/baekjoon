n = input()
m = input()
n = '0' * (max(len(n), len(m)) - len(n)) + n
m = '0' * (max(len(n), len(m)) - len(m)) + m
a = list(n)
b = list(m)
for i in range(len(n)):
    if a[i] < b[i]:
        a[i] = ''
    elif a[i] > b[i]:
        b[i] = ''
x = ''.join(a)
y = ''.join(b)
if x:
    print(int(x))
else:
    print("YODA")
if y:
    print(int(y))
else:
    print("YODA")
