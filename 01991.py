branches = {}


def preorder(start):
    ret = start
    if branches[start][0] != '.':
        ret = ret + preorder(branches[start][0])
    if branches[start][1] != '.':
        ret = ret + preorder(branches[start][1])
    return ret


def inorder(start):
    ret = start
    if branches[start][0] != '.':
        ret = inorder(branches[start][0]) + ret
    if branches[start][1] != '.':
        ret = ret + inorder(branches[start][1])
    return ret


def postorder(start):
    ret = start
    if branches[start][1] != '.':
        ret = postorder(branches[start][1]) + ret
    if branches[start][0] != '.':
        ret = postorder(branches[start][0]) + ret
    return ret


def main():
    for _ in range(int(input())):
        top, left, right = input().split()
        branches[top] = (left, right)
    print(preorder('A'))
    print(inorder('A'))
    print(postorder('A'))


main()
