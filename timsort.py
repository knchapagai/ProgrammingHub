def insertion_sort(t, left=0, right=None):
    if right is None:
        right = len(t) - 1

    for i in range(left+1, right+1):
        key = t[i]
        j = i-1
        while j>= left and t[j] > key:
            t[j+1] = t[j]
            j -= 1
        t[j+1] = key
    return t

def tim_sort(t):
    min_run = 32
    n = len(t)

    for i in range(0,n,min_run):
        insertion_sort(t,i,min((i+min_run-1), (n-1)))

        size = min_run
        while size < n:
            for s in range(0,n, size*2):
                mid = s+ size-1
                end = min((s+size*2-1), (n-1))

                merged = merged(left=t[s:mid+1], right=t[mid+1:end+1])

                t[s:s+len(merged)] = merged
            
        size *= 2
    return t

l1 = [34,10,64,51,32,21]
res = tim_sort(l1)
print(res)