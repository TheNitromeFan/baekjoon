import sys
import string


def valid_xml(line):
    content_stack = []
    i = 0
    while i < len(line):
        c = line[i]
        if c not in "<>&" and 32 <= ord(c) <= 127:
            i += 1
            continue
        elif c == "&":
            if (i + 4 <= len(line) and line[i: i + 4] == "&lt;") or (i + 4 <= len(line) and line[i: i + 4] == "&gt;"):
                i += 4
                continue
            elif i + 5 <= len(line) and line[i: i + 5] == "&amp;":
                i += 5
                continue
            elif i + 3 <= len(line) and line[i + 1] == "x":
                i += 2
                cnt = 0
                while i < len(line) and line[i] != ";":
                    if line[i] not in string.hexdigits:
                        return False
                    i += 1
                    cnt += 1
                if i == len(line) or cnt % 2 != 0:
                    return False
                i += 1
                continue
            else:
                return False
        elif c == "<":
            if i + 1 == len(line):
                return False
            i += 1
            if line[i] == "/":
                i += 1
                tag = ""
                while i < len(line) and line[i] != ">":
                    tag += line[i]
                    i += 1
                if i == len(line) or not content_stack or content_stack.pop() != tag:
                    return False
                i += 1
                continue
            else:
                tag = ""
                while i < len(line) and line[i] not in "/>":
                    if line[i] not in string.ascii_lowercase + string.digits:
                        return False
                    tag += line[i]
                    i += 1
                if i == len(line) or not tag:
                    return False
                elif line[i] == ">":
                    content_stack.append(tag)
                    i += 1
                    continue
                elif i + 1 < len(line) and line[i] == "/" and line[i + 1] == ">":
                    i += 2
                    continue
                else:
                    return False
        else:
            return False
    return not content_stack


def main():
    for line in sys.stdin.readlines():
        line = line.rstrip()
        if valid_xml(line):
            print("valid")
        else:
            print("invalid")


main()
