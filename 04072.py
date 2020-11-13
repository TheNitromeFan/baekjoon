while True:
    line = input()
    if line == '#':
        break
    print(" ".join(word[::-1] for word in line.split()))