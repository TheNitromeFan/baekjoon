import sys


data = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec quis lectus sit amet ante suscipit tempor. " \
       "Aenean dapibus finibus tortor vitae facilisis. Nulla facilisi. Donec suscipit ante a sapien gravida eleifend. " \
       "Curabitur in lectus ut enim semper venenatis. Aenean elit nibh, hendrerit nec nunc in, dictum cursus dolor. " \
       "Aenean eget lectus risus. Cras sollicitudin quam vitae augue mollis bibendum. " \
       "Aliquam euismod vulputate dolor at tristique. Praesent elementum pretium velit non interdum. " \
       "Nunc posuere faucibus magna id pretium. Maecenas congue, velit eget semper porttitor, " \
       "tellus tortor porttitor dui, tristique lobortis quam sem ac odio.".split()
a, b = (int(x) for x in sys.stdin.readline().split())
print(" ".join(data[a-1 : b]))
