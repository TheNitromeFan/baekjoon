keys = [-1, 0, 1]


class NineTree:
    def __init__(self, n, tiles):
        self.size = n
        self.tiles = tiles
        self.children = None

    def get_children(self):
        for line in self.tiles:
            for number in line:
                if number != self.tiles[0][0]:
                    self.children = []
                    for x in range(0, self.size, self.size//3):
                        for y in range(0, self.size, self.size//3):
                            self.children.append(NineTree(self.size//3, tuple(a[y:y+self.size//3] for a in self.tiles[x:x+self.size//3])))
                    return

    def get_counts(self):
        self.get_children()
        if self.children is None:
            return {x: int(x == self.tiles[0][0]) for x in keys}
        else:
            res = {-1: 0, 0: 0, 1: 0}
            for child in self.children:
                tmp = child.get_counts()
                for key in tmp:
                    res[key] += tmp[key]
            return res


def main():
    n = int(input())
    tiles = tuple(tuple(int(x) for x in input().split()) for _ in range(n))
    root = NineTree(n, tiles)
    ans = root.get_counts()
    for key in keys:
        print(ans[key])


main()
