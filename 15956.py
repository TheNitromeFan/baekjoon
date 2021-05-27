import sys


def is_int(x):
    try:
        int(x)
        return True
    except ValueError:
        return False


def find_parent(parent, x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find_parent(parent, parent[x])
        return parent[x]


def unite(parent, x, y):
    px = find_parent(parent, x)
    py = find_parent(parent, y)
    if px == py:
        return
    if (len(px), px) < (len(py), py):
        parent[py] = px
    else:
        parent[px] = py


def unite_comparisons(comparisons):
    parent = {}
    for a, b, _ in comparisons:
        parent[a] = a
        parent[b] = b
    for a, b, equal in comparisons:
        if equal:
            unite(parent, a, b)
    return parent


def main():
    entries = sys.stdin.readline().rstrip().split("&&")
    elements = set()
    comparisons = []
    for entry in entries:
        if "==" in entry:
            left, right = entry.split("==")
            elements.add(left)
            elements.add(right)
            comparisons.append((left, right, True))
        else:
            left, right = entry.split("!=")
            elements.add(left)
            elements.add(right)
            comparisons.append((left, right, False))
    parent = unite_comparisons(comparisons)
    element_map = {}
    output = set()
    for a, b, _ in comparisons:
        pa = find_parent(parent, a)
        if pa not in element_map:
            element_map[pa] = set()
        element_map[pa].add(a)
        pb = find_parent(parent, b)
        if pb not in element_map:
            element_map[pb] = set()
        element_map[pb].add(b)
    output = [f"{pa}!={pb}" for pa, pb in output]
    has_int = {}
    for x in element_map:
        has_int[x] = False
        element_map[x] = sorted(element_map[x], key=lambda y: (len(y), y))
        s = sum(is_int(y) for y in element_map[x])
        if s >= 2:
            print("0==1")
            return
        elif s:
            has_int[x] = True
        for element in element_map[x][1:]:
            output.append(f"{x}=={element}")
    output1 = set()
    for a, b, equal in comparisons:
        pa = find_parent(parent, a)
        pb = find_parent(parent, b)
        if not equal and pa == pb:
            print("0==1")
            return
        elif not equal and not (has_int[pa] and has_int[pb]):
            if (len(pa), pa) > (len(pb), pb):
                pa, pb = pb, pa
            output1.add((pa, pb))
    output += [f"{pa}!={pb}" for pa, pb in output1]
    if not output:
        output = ["1==1"]
    print("&&".join(output))


main()
