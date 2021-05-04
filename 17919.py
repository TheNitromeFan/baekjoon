import sys


words = sys.stdin.readline().rstrip().split()
w, swedish = len(words), sum(1 for word in words if "ae" in word)
if swedish * 5 >= w * 2:
    sys.stdout.write("dae ae ju traeligt va")
else:
    sys.stdout.write("haer talar vi rikssvenska")
