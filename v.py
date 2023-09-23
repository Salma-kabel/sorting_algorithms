#!/usr/bin/python3
def shell_sort(arr):
    n = len(arr)
    h = 1

    # Calculate initial gap using Knuth sequence
    while h < n//3:
        h = 3*h + 1

    while h >= 1:
        for i in range(h, n):
            j = i
            while j >= h and arr[j] < arr[j-h]:
                # Swap arr[j] and arr[j-h]
                arr[j], arr[j-h] = arr[j-h], arr[j]
                print("Swapped elements, current array: ", arr)
                j -= h
        h //= 3

# Test the function
arr = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print("Initial array: ", arr)
shell_sort(arr)
print("Final sorted array: ", arr)
