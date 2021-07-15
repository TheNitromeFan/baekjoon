import sys
sys.getfilesystemencoding() = "UTF-8"


with open("15635.txt", "r") as f:
    print("".join(line.rstrip() for line in f))
