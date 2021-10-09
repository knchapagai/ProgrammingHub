import timeit
import random
import matplotlib.pyplot as plt
import sys
import psutil

sys.setrecursionlimit(10000000)
# print(sys.getrecursionlimit())

n = list(map(int, input().split()))
timetaken = [[0 for x in range(len(n))] for j in range(4)]
memorytaken = [[0 for x in range(len(n))] for j in range(4)]


def mergeSortRec(rl):
    arr = rl.copy()

    # print(arr)
    if len(arr) > 1:

        # Finding the mid of the array
        mid = len(arr) // 2

        # Dividing the array elements
        L = arr[:mid]

        # into 2 halves
        R = arr[mid:]

        # Sorting the first half
        mergeSortRec(L)

        # Sorting the second half
        mergeSortRec(R)

        i = j = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            merged = []
            if L[i] < R[j]:
                merged.append(L[i])
                i += 1
            else:
                merged.append(R[j])
                j += 1

            # Checking if any element was left
            merged.append(L[i:])

            merged.append(R[j:])
    del arr

    # print(arr)


def mergeSortIter(arr):
    a = arr.copy()
    # start with least partition size of 2^0 = 1
    width = 1
    n = len(a)
    # subarray size grows by powers of 2
    # since growth of loop condition is exponential,
    # time consumed is logarithmic (log2n)
    while width < n:
        # always start from leftmost
        l = 0
        while l < n:
            r = min(l + (width * 2 - 1), n - 1)
            m = (l + r) // 2
            # final merge should consider
            # unmerged sublist if input arr
            # size is not power of 2
            if width > n // 2:
                m = r - (n % width)
            mergeIter(a, l, m, r)
            l += width * 2
        # Increasing sub array size by powers of 2
        width *= 2
    del a


# Merge Function
def mergeIter(a, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * n1
    R = [0] * n2
    
    L[0:n1-1] = a[l:m]
    
    R[0:n2-1] = a[m +1:r]

    i, j, k = 0, 0, l
    while i < n1 and j < n2:
        if L[i] > R[j]:
            a[k] = R[j]
            j += 1
        else:
            a[k] = L[i]
            i += 1
        k += 1

    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1


def partition(arr, low, high):
    i = low - 1  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range(low, high):

        # If current element is smaller
        # than or equal to pivot
        if arr[j] <= pivot:

            # increment index of
            # smaller element
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low --> Starting index,
# high --> Ending index

# Function to do Quick sort
def quickSortRec(rl, low, high):
    arr = rl.copy()
    if low < high:

        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)

        # Separately sort elements before
        # partition and after partition
        quickSortRec(arr, low, pi - 1)
        quickSortRec(arr, pi + 1, high)
    del arr


def partition(arr, l, h):
    i = l - 1
    x = arr[h]

    for j in range(l, h):
        if arr[j] <= x:

            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return i + 1


# Function to do Quick sort
# arr[] --> Array to be sorted,
# l  --> Starting index,
# h  --> Ending index
def quickSortIter(rl, l, h):
    arr = rl.copy()

    # Create an auxiliary stack
    size = h - l + 1
    stack = [0] * (size)

    # initialize top of stack
    top = -1

    # push initial values of l and h to stack
    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h

    # Keep popping from stack while is not empty
    while top >= 0:

        # Pop h and l
        h = stack[top]
        top = top - 1
        l = stack[top]
        top = top - 1

        # Set pivot element at its correct position in
        # sorted array
        p = partition(arr, l, h)

        # If there are elements on left side of pivot,
        # then push left side to stack
        if p - 1 > l:
            top = top + 1
            stack[top] = l
            top = top + 1
            stack[top] = p - 1

        # If there are elements on right side of pivot,
        # then push right side to stack
        if p + 1 < h:
            top = top + 1
            stack[top] = p + 1
            top = top + 1
            stack[top] = h
    del arr


def memory_usage_psutil():
    # return the memory usage in MB
    process = psutil.Process()
    mem = process.memory_info()[0] / float(2 ** 20)
    return mem


for i in range(0, len(n)):

    randomlist = sorted(random.sample(range(0, 1000000), n[i]), reverse=True)

    start = timeit.default_timer()
    mergeSortRec(randomlist)

    end = timeit.default_timer()
    timetaken[0][i] = end - start
    memorytaken[0][i] = memory_usage_psutil()

    start = timeit.default_timer()
    mergeSortIter(randomlist)

    end = timeit.default_timer()
    timetaken[1][i] = end - start
    memorytaken[1][i] = memory_usage_psutil()

    start = timeit.default_timer()
    quickSortRec(randomlist, 0, len(randomlist) - 1)

    end = timeit.default_timer()
    timetaken[2][i] = end - start
    memorytaken[2][i] = memory_usage_psutil()

    start = timeit.default_timer()
    quickSortIter(randomlist, 0, len(randomlist) - 1)

    end = timeit.default_timer()
    timetaken[3][i] = end - start
    memorytaken[3][i] = memory_usage_psutil()

print("Merge Sort Rec   : ", timetaken[0])
print("Merge Sort Iter  : ", timetaken[1])
print("Quick Sort Rec  : ", timetaken[2])
print("Quick Sort Iter  : ", timetaken[3])

print("Memory Merge Sort Rec   : ", memorytaken[0])
print("Memory Merge Sort Iter  : ", memorytaken[1])
print("Memory Quick Sort Rec   : ", memorytaken[2])
print("Memory Quick Sort Iter  : ", memorytaken[3])


plt.plot(
    n,
    timetaken[0],
    label="Merge Sort Rec",
    linestyle="dashed",
    linewidth=1,
    marker="o",
)


plt.plot(
    n,
    timetaken[1],
    label="Merge Sort Iter",
    linestyle="dashed",
    linewidth=1,
    marker="o",
)


plt.plot(
    n,
    timetaken[2],
    label="Quick Sort Rec",
    linestyle="dashed",
    linewidth=1,
    marker="o",
)


plt.plot(
    n,
    timetaken[3],
    label="Quick Sort Iter",
    linestyle="dashed",
    linewidth=1,
    marker="o",
)

# naming the x axis
plt.xlabel("Number of Elements")
# naming the y axis
plt.ylabel("Time Taken (seconds)")
# giving a title to my graph
plt.title("Comparison of Sorting Algorithms")

# show plot legend
plt.legend()

plt.savefig("Sort.png", dpi=1000)
# function to show the plot
plt.show()
