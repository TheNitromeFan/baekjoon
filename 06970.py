import sys


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        s = int(sys.stdin.readline())
        v = int(sys.stdin.readline())
        o = int(sys.stdin.readline())
        subjects, verbs, objects = [], [], []
        for _ in range(s):
            subjects.append(sys.stdin.readline().rstrip())
        for _ in range(v):
            verbs.append(sys.stdin.readline().rstrip())
        for _ in range(o):
            objects.append(sys.stdin.readline().rstrip())
        for subject in subjects:
            for verb in verbs:
                for obj in objects:
                    print(subject + " " + verb + " " + obj + ".")
        print()


main()
