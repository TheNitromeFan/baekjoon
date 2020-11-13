def partition(arr, ell, r):
    x = arr[r]
    i = ell
    for j in range(ell, r):
        if arr[j] <= x:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i


def kth_smallest(a, ell, r, k):
    index = partition(a, ell, r)
    if index - ell + 1 == k:
        return a[index]
    elif index - ell + 1 > k:
        return kth_smallest(a, ell, index - 1, k)
    else:
        return kth_smallest(a, index + 1, r, k - index + ell - 1)


def kth(a, k):
    return kth_smallest(a, 0, len(a) - 1, k)


arr = [50, 50, 50, 50, 50, 0]
n = len(arr)
k = 2
print("K-th smallest element is ", end="")
print(kth(arr, k))
