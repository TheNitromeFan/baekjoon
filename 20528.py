import sys


sys.stdin.readline()
words = sys.stdin.readline().rstrip().split()
print(int(all(word[0] == words[0][0] for word in words)))
