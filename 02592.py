def mean(numbers, length):
    return sum(numbers) // length


def mode(numbers):
    return sorted(numbers, key=numbers.count, reverse=True)[0]


ints = [int(input()) for i in range(10)]
print(mean(ints, 10))
print(mode(ints))
