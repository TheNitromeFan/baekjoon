import sys


words = []
for line in sys.stdin.readlines():
    words += line.rstrip().split()
current_line = ""
for word in words:
    if word == "<br>":
        print(current_line)
        current_line = ""
    elif word == "<hr>":
        if current_line:
            print(current_line)
            current_line = ""
        print("-" * 80)
    else:
        if current_line:
            if len(current_line) + 1 + len(word) > 80:
                print(current_line)
                current_line = word
            else:
                current_line += " " + word
        else:
            current_line = word
if current_line:
    print(current_line)
