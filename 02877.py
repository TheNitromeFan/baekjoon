k = int(input())
ans = ""
while k:
    if k % 2:
        ans = "4" + ans
    else:
        ans = "7" + ans
    k = (k - 1) // 2
print(ans)
