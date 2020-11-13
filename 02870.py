n = int(input())
numbers = []
for _ in range(n):
    line = input()
    j = 0
    while j < len(line):
        if j < len(line) and '0' <= line[j] <= '9':
            number = 0
            while j < len(line) and '0' <= line[j] <= '9':
                number = number * 10 + int(line[j])
                j += 1
            numbers.append(number)
        while j < len(line) and 'a' <= line[j] <= 'z':
            j += 1
print('\n'.join(str(x) for x in sorted(numbers)))
