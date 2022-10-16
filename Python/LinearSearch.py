def search(arr,x):
    for i in range(0,len(arr)):
        if arr[i]==x:
            print('Element Found in the array')
            return
        else:
            continue
    print("Element not found in the array")
    
arr=[1,2,3,4,5,6,7]
print("Enter the element you want to search:")
x=int(input())
search(arr,x)
