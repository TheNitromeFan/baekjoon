while True:
    line = input()
    if line == "#":
        break
    words = line.split()
    converted = []
    for word in words:
        if len(word) == 1:
            converted.append(word)
        else:
            converted.append(word[0] + word[-2:0:-1] + word[-1])
    print(" ".join(converted))
