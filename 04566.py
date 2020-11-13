import sys


def main():
    while True:
        line = sys.stdin.readline().rstrip()
        if line == 'END':
            break
        s = line.split('"')
        if len(s) == 3 and s[0] == '' and ' ' + s[1] == s[2]:
            print('Quine({})'.format(s[1]))
        else:
            print('not a quine')


main()
