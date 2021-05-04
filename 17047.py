import sys


def main():
    blocks = []
    while True:
        block = []
        while True:
            line = sys.stdin.readline().rstrip()
            block.append(line)
            if line in ["", "#"]:
                break
        blocks.append(block)
        if block[-1] == "#":
            break
    delta = int(sys.stdin.readline())
    for block in blocks:
        begin, end = block[1].split(" --> ")
        h, m, s, milli = int(begin[0:2]), int(begin[3:5]), int(begin[6:8]), int(begin[9:12])
        start = 60 * 60 * 1000 * h + 60 * 1000 * m + 1000 * s + milli
        h, m, s, milli = int(end[0:2]), int(end[3:5]), int(end[6:8]), int(end[9:12])
        finish = 60 * 60 * 1000 * h + 60 * 1000 * m + 1000 * s + milli
        start += delta
        finish += delta
        print(block[0])
        print(
          f"{start // 1000 // 60 // 60:02d}:{start // 1000 // 60 % 60:02d}:{start // 1000 % 60:02d},{start % 1000:03d}",
          end=" --> ")
        print(
          f"{finish // 1000 // 60 // 60:02d}:{finish // 1000 // 60 % 60:02d}:{finish // 1000 % 60:02d},{finish % 1000:03d}")
        for line in block[2:]:
            print(line)


main()
