while True:
    line = input()
    if line == '*':
        break
    words = line.lower().split()
    if all(word[0] == words[0][0] for word in words):
        print('Y')
    else:
        print('N')
