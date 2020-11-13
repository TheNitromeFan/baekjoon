def mean(numbers, length):
    return sum(numbers) // length


def median(numbers, length):
    return sorted(numbers)[(length-1) // 2]


ints = [int(input()) for i in range(5)]
print(mean(ints, 5))
print(median(ints, 5))
