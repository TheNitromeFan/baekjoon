def longest_streak(length, string):
    maximum = 1
    count = 1
    for i in range(2, 2*length, 2):
        if string[i] >= string[i-2]:
            count += 1
        else:
            count = 1
        maximum = max(maximum, count)
    count = 1
    for i in range(2, 2*length, 2):
        if string[i] <= string[i-2]:
            count += 1
        else:
            count = 1
        maximum = max(maximum, count)
    return maximum


print(longest_streak(int(input()), input()))
