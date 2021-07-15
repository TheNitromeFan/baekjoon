import sys


class Node:
    def __init__(self, val):
        self.parent = None
        self.children = []
        self.value = val


def count_descendants(node, desc):
    if node.value in desc:
        return desc[node.value]
    desc[node.value] = 1
    for child in node.children:
        desc[node.value] += count_descendants(child, desc)
    return desc[node.value]


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        line1 = sys.stdin.readline().rstrip().split()
        root1 = Node(line1[0])
        for x in line1[1:-1]:
            if x != '#':
                child = Node(x)
                root1.children.append(child)
                child.parent = root1
                root1 = child
            else:
                root1 = root1.parent
        descendants1 = {}
        count_descendants(root1, descendants1)
        line2 = sys.stdin.readline().rstrip().split()
        root2 = Node(line2[0])
        for x in line2[1:-1]:
            if x != '#':
                child = Node(x)
                root2.children.append(child)
                child.parent = root2
                root2 = child
            else:
                root2 = root2.parent
        descendants2 = {}
        count_descendants(root2, descendants2)
        if sorted(descendants1.values()) == sorted(descendants2.values()):
            print("The two trees are isomorphic.")
        else:
            print("The two trees are not isomorphic.")


main()
