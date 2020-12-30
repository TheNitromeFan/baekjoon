import sys
import string


while True:
    try:
        word1 = sys.stdin.readline().rstrip()
        word2 = sys.stdin.readline().rstrip()
    except (ValueError, EOFError):
        break
    counter1 = {x: word1.count(x) for x in string.ascii_lowercase}
    counter2 = {x: word2.count(x) for x in string.ascii_lowercase}
    new_counter = {x: min(counter1[x], counter2[x]) for x in string.ascii_lowercase}
    w = "".join(x * new_counter[x] for x in string.ascii_lowercase)
    print(w)
