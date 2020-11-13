import sys


def main():
    k = int(sys.stdin.readline())
    for i in range(1, k + 1):
        a, b = "", ""
        n = int(sys.stdin.readline())
        for _ in range(n):
            t, d = sys.stdin.readline().rstrip().split()
            for _ in range(int(t)):
                a += d
        m = int(sys.stdin.readline())
        for _ in range(m):
            t, d = sys.stdin.readline().rstrip().split()
            for _ in range(int(t)):
                b += d
        c = str(int(a) + int(b))
        ans = []
        cnt, digit = 1, c[0]
        for x in c[1:]:
            if x == digit:
                cnt += 1
            else:
                ans.append((cnt, digit))
                cnt = 1
                digit = x
        ans.append((cnt, digit))
        print("Data Set {}:".format(i))
        print(len(ans))
        for elem in ans:
            print(" ".join(str(x) for x in elem))
        print()


main()
