import sys


for line in sys.stdin.readlines():
    tmp = line.rstrip().split('=')
    a, b = tmp[0].split('+')
    c = tmp[1]
    print(int(a[::-1]) + int(b[::-1]) == int(c[::-1]))
