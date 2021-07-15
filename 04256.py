import sys


def postorder(preorder, inorder, n):
    ret = []
    root = inorder.index(preorder[0])
    if root != 0:
        ret += postorder(preorder[1:], inorder, root)
    if root != n - 1:
        ret += postorder(preorder[1 + root:], inorder[1 + root:], n - root - 1)
    ret.append(preorder[0])
    return ret


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        preorder = [int(x) for x in sys.stdin.readline().split()]
        inorder = [int(x) for x in sys.stdin.readline().split()]
        print(" ".join(str(x) for x in postorder(preorder, inorder, n)))


main()
