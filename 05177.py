import sys


def parsed(line):
    line = line.lower().replace(";", ",").replace("{", "(").replace("}", ")").replace("[", "(").replace("]", ")")
    line = "(" + line + ")"
    ret = ""
    i = 0
    while i < len(line):
        if line[i] == " ":
            start = i - 1
            while line[i] == " ":
                i += 1
            end = i
            if not (line[start] in "(.,:" or line[end] in "(.,:"):
                ret += " "
        else:
            ret += line[i]
            i += 1
    return ret


def main():
    t = int(sys.stdin.readline())
    ans = []
    for a0 in range(1, t + 1):
        line1 = sys.stdin.readline()
        line2 = sys.stdin.readline()
        if parsed(line1) == parsed(line2):
            ans.append("Data Set {}: equal".format(a0))
        else:
            ans.append("Data Set {}: not equal".format(a0))
    sys.stdout.write("\n\n".join(ans))


main()
