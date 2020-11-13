def sliced(line):
    n = len(line)
    for i in range(0, n, 10):
        yield line[i:min(i+10, n)]


for string in sliced(input()):
    print(string)
