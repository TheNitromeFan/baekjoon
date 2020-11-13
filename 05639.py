import sys


class Tree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def insert_value(head, value):
    if head is None:
        print("self!")
        return Tree(value)
    print(head.value)
    if head.value > value:
        print("left!")
        head.left = insert_value(head.left, value)
        return head
    else:
        print("right!")
        head.right = insert_value(head.right, value)
        return head


def print_tree(head):
    if head.left is not None:
        print_tree(head.left)
    if head.right is not None:
        print_tree(head.right)
    print(head.value)


def print_tree2(head):
    if head.left is not None:
        print_tree(head.left)
    print(head.value)
    if head.right is not None:
        print_tree(head.right)


def main():
    head = None
    for line in sys.stdin.readlines():
        print(line.strip())
        head = insert_value(head, line.strip())
        print()
    print_tree(head)


main()
