import sys

DEMERIT = {"TT": 75, "TX": 50, "PR": 80, "RT": 30, "AP": 25, "PX": 60}


def main():
    while True:
        line = sys.stdin.readline()
        if line[0] == "0":
            break
        w, n = (int(x) for x in line.split())
        misdemeanors = []
        for _ in range(n):
            name, code = sys.stdin.readline().rstrip().split()
            misdemeanors.append((name, code))
        points = {name: 0 for name, _ in misdemeanors}
        for name, code in misdemeanors:
            points[name] += DEMERIT[code]
        confiscate = []
        for name, _ in misdemeanors:
            if points[name] >= 100 and name not in confiscate:
                confiscate.append(name)
        if not confiscate:
            confiscate.append("No phones confiscated")
        sys.stdout.write("Week {} {}\n".format(w, ",".join(confiscate)))


main()
