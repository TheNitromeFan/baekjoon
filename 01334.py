number = input()
n = len(number)
ans = number[:n // 2]
if n % 2 == 0:
    tmp = ans
    if tmp + tmp[::-1] <= number:
        tmp = str(int(tmp) + 1)
    if len(tmp) == len(ans) + 1:
        ans = tmp + tmp[:-1][::-1]
    else:
        ans = tmp + tmp[::-1]
else:
    tmp = ans + number[n // 2]
    if tmp + ans[::-1] <= number:
        tmp = str(int(tmp) + 1)
    if len(tmp) == len(ans) + 2:
        ans = tmp[:-1] + tmp[:-1][::-1]
    else:
        ans = tmp + tmp[:-1][::-1]
print(ans)
