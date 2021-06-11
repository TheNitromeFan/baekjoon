import sys


def print_postorder(preorder, inorder, n):
    root = inorder.find(preorder[0])
    if root != 0:
        print_postorder(preorder[1:], inorder, root)
    if root != n - 1:
        print_postorder(preorder[root + 1:n], inorder[root + 1:n], n - 1 - root)
    print(preorder[0], end="")


def main():
    for line in sys.stdin.readlines():
        preorder, inorder = line.strip().split()
        print_postorder(preorder, inorder, len(preorder))
        print()


main()
