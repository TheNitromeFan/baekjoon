import sys


def period_start_count(line):
    ret = 0
    while ret < len(line) and line[ret] == ".":
        ret += 1
    return ret


def valid_indentation(stylish, r, c, s):
    indent = 0
    small, medium, large = 0, 0, 0
    for i in range(len(stylish) - 1):
        line = stylish[i]
        small += line.count("(") - line.count(")")
        medium += line.count("{") - line.count("}")
        large += line.count("[") - line.count("]")
        if period_start_count(stylish[i + 1]) != r * small + c * medium + s * large:
            return False
    return True


def indentation(stylish):
    candidates = []
    for r in range(1, 21):
        for c in range(1, 21):
            for s in range(1, 21):
                if valid_indentation(stylish, r, c, s):
                    candidates.append((r, c, s))
    return candidates


def possible_indentations(stylish, lines):
    candidates = indentation(stylish)
    indents = [set() for _ in lines]
    indents[0].add(0)
    for r, c, s in candidates:
        small, medium, large = 0, 0, 0
        for i in range(len(lines) - 1):
            line = lines[i]
            small += line.count("(") - line.count(")")
            medium += line.count("{") - line.count("}")
            large += line.count("[") - line.count("]")
            indents[i + 1].add(r * small + c * medium + s * large)
    answer = [-1] * len(lines)
    for idx, indent in enumerate(indents):
        if len(indent) == 1:
            answer[idx] = indent.pop()
    return answer


def main():
    while True:
        n, m = (int(x) for x in sys.stdin.readline().split())
        if n == m == 0:
            break
        stylish, lines = [], []
        for _ in range(n):
            stylish.append(sys.stdin.readline().rstrip())
        for _ in range(m):
            lines.append(sys.stdin.readline().rstrip())
        print(" ".join(str(x) for x in possible_indentations(stylish, lines)))


main()
