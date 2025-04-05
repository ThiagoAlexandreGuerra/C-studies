def quickSort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quickSort(left) + middle + quickSort(right)

arr = [12, 3, 4, 67, 90, 9, 87, 54, 2, 4, 1, 56, 74, 32, 33, 15]
sortedArray = quickSort(arr)
print(sortedArray)
