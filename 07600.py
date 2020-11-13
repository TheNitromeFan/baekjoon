import string


while True:
    line = input()
    if line == '#':
        break
    print(len(set(x for x in string.ascii_lowercase if x in line.lower())))
