def multiplications(first, second):
    yield first * (second % 10)
    yield first * (second // 10 % 10)
    yield first * (second // 100)
    yield first * second


a = int(input())
b = int(input())
for number in multiplications(a, b):
    print(number)
